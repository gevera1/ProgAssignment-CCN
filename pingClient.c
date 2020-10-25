#include "wrappers.c"

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

#define BUFFER_SIZE 	1024
#define WAIT 		1

volatile int flag = 0;

void sighandler( int sig ) 
{
	flag = 1;
}

void cli_loop(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen, const char* ip) 
{
	int		n, recv, lost;
	char		recvline[BUFFER_SIZE + 1];
	time_t		t;
	double 		time_rtt, avg_rtt, alpha;

	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags 		= 0;
	act.sa_handler 		= sighandler;
	sigaction(SIGALRM, &act, NULL);

	avg_rtt = 0.0;
	alpha = 0.2;	
	lost = 0;
	recv = 0;

	const char* message = "The horse is the white of the eyes and the dark within.\n";

	for (unsigned int i = 0; i < 5; i++) {
		flag = 0;
		t = clock();	
		Sendto(sockfd, message, strlen(message), 0, pservaddr, servlen);	
		alarm(1);
		usleep(100000);
		while ( ( (n = Recvfrom(sockfd, recvline, BUFFER_SIZE, 0, NULL, NULL)) < 1 ) && !flag );  
		time_rtt = (double)(clock()-t)/CLOCKS_PER_SEC;
		
		printf("PING %s %3d ", ip, i);
		if (!flag) {
			++recv;
			avg_rtt = ( (1-alpha) * avg_rtt ) + ( alpha * time_rtt);
			printf("%F\n", avg_rtt);	
		} else {
			++lost;
			printf("LOST\n");
		}
	}
	printf("\nCOMPLETED:\t%d packets received,\t%d packets lost\n", recv, lost);
}

int main(int argc, char* argv[]) 
{
	int			sockfd;
	struct sockaddr_in	servaddr;
	char			*localhost, *port_num;
	
	if (argc != 3) { 
		fprintf(stderr, "ERROR: Invalid command line format.\n"); 
		return EXIT_FAILURE; 
	}
	
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin,	NULL, _IONBF, 0);

	localhost 	= argv[1];
	port_num	= argv[2];

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family 	= AF_INET;
	servaddr.sin_port 	= htons(atoi(port_num));
	Inet_pton( AF_INET, localhost, &servaddr.sin_addr );

	sockfd = Socket( AF_INET, SOCK_DGRAM, 0 );

	cli_loop(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr), localhost);
	
	return EXIT_SUCCESS;  
}
