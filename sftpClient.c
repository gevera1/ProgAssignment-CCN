#include "wrappers.c"

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/socket.h>

#define BUFF_SIZE 	512	// bytes
#define PORT_NUM 	9093	
#define RETR_TIMER 	1	// seconds
#define RETR_LIM	5	// times
#define AVERAGE_DELAY	400000	// microseconds
#define LOSS_RATE	5	// percent

volatile int flag 	= 0;
volatile int retransmit = 0;

struct pkt {
	char seqnum, acknum, finnum, data[BUFF_SIZE];
};

void sigalarm( int sig ) 
// In the event a signal is a detected, changes global flag to 1.
// This signal indicates the alarm went off and a timeout occured, the packet is
// 	lost and the program continues its client loop
{
	fprintf(stderr, "Timeout occured\n");
	retransmit = 1;
}

void cli_loop( char *fp, int sockfd, const SA *pservaddr, socklen_t servlen )
// Loop to send file over to server
{
	int	transmit, n;
	char	seq;
	struct	pkt *recv_pkt = (struct pkt *) malloc( BUFF_SIZE + 3 * sizeof(char) );
	struct 	pkt *packet   = (struct pkt *) malloc( BUFF_SIZE + 3 * sizeof(char) );
  
	struct timeval start, stop; 
	double	time;

	// Open input file
	FILE * in_file = fopen(fp, "r");

	// Set up signal handler
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags	= 0;
	act.sa_handler	= sigalarm;
	sigaction(SIGALRM, &act, NULL);

	// Set up rdt3.0 protocol variables
	seq = 1;
	transmit = 0;
	char string[BUFF_SIZE];
	
	gettimeofday(&start, NULL);

//	printf("Begin reading file\n");
	while (!feof(in_file)) {
		while( fgets(string, BUFF_SIZE, in_file) ) {
		// While loop reads contents of entire file and constructs them into packets

			transmit = 0;

			bzero(packet, BUFF_SIZE + 3 * sizeof(char));
			bzero(packet->data, sizeof(string));
			bzero(recv_pkt, BUFF_SIZE + 3 * sizeof(char));
	
			// Turn 512 bytes of data into a packet
			if (seq == 1) 	{ packet->seqnum = 0; seq = 0; }
			else 		{ packet->seqnum = 1; seq = 1; }
		
//			printf("Packet size: %ld\nString length: %ld\n", sizeof(*packet), strlen(string));
			
			strcpy(packet->data, string);	
			packet->finnum = 0;	
	
		send_packet:
			// If the number of transmissions reaches limit, break	
			if (transmit == RETR_LIM) { 
				fprintf(stderr, "Retransmission error\n"); 
				flag = 1; 
				break; 
			}
		
//			printf("Sending Packet...\nSize: %ld\n", sizeof(packet->data));
			Sendto(sockfd, packet, sizeof(*packet), 0, pservaddr, servlen);
		
			transmit++;		// Increment number of transmissions
			alarm(RETR_TIMER);	// Set timer to wait for ACK
			usleep(AVERAGE_DELAY);	// Simulate propagation delay
		
//			printf("Waiting for ACK...\n");		
	
			while ( ( n = Recvfrom(sockfd, recv_pkt, sizeof(*recv_pkt), 0, NULL, NULL) ) < 1 ) {
				if (retransmit) { printf("\nRetransmitting...\n"); retransmit = 0; goto send_packet; }	 
				// if retransmit flag is signaled, try again
			}
		
			transmit = 0; 	// Reset retransmission count
	
			if (recv_pkt->acknum != seq) {	// Handles OUT OF ORDER packet
				fprintf(stderr, "ERROR: Out of Order ACK!\n");
				fclose(in_file);
				goto send_packet;	// Retransmits in case of out of order ACK
			}
//			printf("Received ACK\n\n");

		}	
		if (flag) break;	
	}
	if (!flag) {
		// Closing connection with packet smaller than 512 
		char close_req[] = "request close\n";

		// Reconfigure packet to send final message (Close request)
		bzero(packet, BUFF_SIZE);
		packet->seqnum 		= (char)( (seq + 1) % 2 );
		packet->finnum		= (char) 1;
		bzero(packet->data, sizeof(close_req));
		
//	printf("Closing Packet Size: %ld\n", sizeof(close_req));	
	
		strcpy(packet->data, close_req);		

//		printf("Sending Last Packet...\nSize: %ld\n", sizeof(packet->data));
		
		Sendto(sockfd, packet, sizeof(*packet), 0, pservaddr, servlen);
	
		while ( ( n = Recvfrom(sockfd, recv_pkt, sizeof(*recv_pkt), 0, NULL, NULL) ) < 1 );
	
//		printf("Received ACK\n\n");
	
		gettimeofday(&stop, NULL);

		double time = (double) ( (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec )/1000000;

		printf("sFTP: file sent successfully to 127.0.0.1 in %.5lf secs\n", time); 
	} else{ printf("sFTP: file transfer unsuccessful: packet retransmission limit reached\n"); }
	
	// Free memory to prevent leaks
	free(packet);
	free(recv_pkt);
	fclose(in_file);
	return;
}

int main( int argc, char* argv[] ) 
{
	int	sockfd;
	struct	sockaddr_in servaddr;

	if (argc != 2) {
		fprintf(stderr, "ERROR: Invalid command line format.\n");
		return EXIT_FAILURE;
	}
	
	// Clear IO streams/buffers to prevent memory leaks
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin,  NULL, _IONBF, 0);

	// Create server sockaddr_in struct
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family	= AF_INET;
	servaddr.sin_port	= htons( PORT_NUM );
	Inet_pton( AF_INET, argv[1], &servaddr.sin_addr );

	// Create socket for Client	
	sockfd = Socket( AF_INET, SOCK_DGRAM, 0 );

	char i_file[] = "inputfile.txt";	

	cli_loop(i_file, sockfd, (SA *) &servaddr, sizeof(servaddr));

	return EXIT_SUCCESS; 
}
