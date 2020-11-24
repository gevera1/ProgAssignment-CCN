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
#define AVERAGE_DELAY	10000 	// microseconds
#define LOSS_RATE	0	// percent

struct pkt {
	char seqnum, acknum, finnum, data[BUFF_SIZE];
};

void serv_loop( int sockfd, SA * pcliaddr, socklen_t clilen ) 
// Takes in the datagrams from the client and writes them to an output text file
{
	srand( (unsigned) time(0) );

	int 			n, write_chk;
	char			s_n, *len_chk;
	socklen_t		len;
	struct	pkt		*recv_pkt = (struct pkt *) malloc(BUFF_SIZE +  3 * sizeof(char));
	struct	pkt 		*send_pkt = (struct pkt *) malloc( BUFF_SIZE ); 

	FILE * out_file = fopen("outputfile.txt", "w");
	printf("Opening File...\n");
	while (1) 
	{
		bzero(recv_pkt, BUFF_SIZE + 3 * sizeof(char));
		bzero(send_pkt, BUFF_SIZE);

		bzero(recv_pkt->data, BUFF_SIZE);	

		len 	= clilen;
	
		printf("Waiting for packet...\n");
		while ( (n = Recvfrom(sockfd, recv_pkt, sizeof(*recv_pkt), 0, pcliaddr, &len)) < 1 ) {	// Get message from socket
			if ( n < 0 ) { fprintf(stderr, "ERROR: Recvfrom() error\n"); }
		}
		
		printf("\nSize of received Data: %ld\n", sizeof(recv_pkt->data));
		
		s_n = recv_pkt->seqnum;		

		send_pkt->acknum = s_n;	
	
		printf("Packet received.\n\tString length: %ld\n\tString: %s\n", strlen(recv_pkt->data), recv_pkt->data);

		if (rand() % 100 < LOSS_RATE) continue;	
		
		Sendto(sockfd, send_pkt, sizeof(*send_pkt), 0, pcliaddr, len);
		
		if ( recv_pkt->finnum ) {
			// free(recv_pkt->data);
			free(recv_pkt);
			free(send_pkt);
			break;
		}
		
		write_chk = fputs(recv_pkt->data, out_file); // Write to file
		if (write_chk == EOF) { 
			fprintf(stderr, "ERROR: write to file failed\n"); 
			fclose(out_file);
			return; 
		} 	
	}
	fclose(out_file);
	return;
}

int main( int argc, char* argv[] ) 
{	
	// Clear IO streams/buffers to prevent memory leaks
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin,  NULL, _IONBF, 0);

	int	sockfd;
	struct 	sockaddr_in servaddr, cliaddr;

	char localhost[] = "127.0.0.1";

	sockfd = Socket( AF_INET, SOCK_DGRAM, 0 );
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family		= AF_INET;
	servaddr.sin_addr.s_addr	= htonl( INADDR_ANY );
	servaddr.sin_port		= htons( PORT_NUM );

	Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

	serv_loop(sockfd, (SA *) &cliaddr, sizeof(cliaddr));

	return EXIT_SUCCESS; 
}
