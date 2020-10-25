#include "wrappers.c"
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 	1024
#define LOSS_RATE 	25

int echo_ping(int sockfd, SA * pcliaddr, socklen_t clilen)
{
	srand((unsigned) time(0));

	int			n;
	socklen_t		len;
	char			mesg[BUFFER_SIZE], ptr[15];
	struct sockaddr_in	*sa;

	while (1) 
	{
		memset(mesg, 0, sizeof(mesg));
		memset(ptr , 0, sizeof(ptr) );
		sa 	= (struct sockaddr_in *) pcliaddr;
		len 	= clilen;
			
		while ( (n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len)) < 1 ) {
			if (n < 0) { fprintf(stderr, "ERROR: Recvfrom() error\n"); }
		}
		
		Inet_ntop(AF_INET, &sa->sin_addr, ptr, len);

		printf("Received from %s: %s", ptr ,mesg);
		
		if (rand() % 100 < LOSS_RATE) {
			printf("    Reply not sent.\n\n");
			continue;
		}
		Sendto(sockfd, mesg, n, 0, pcliaddr, len);
		printf("    Reply sent.\n\n");
	}
	return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) 
{
	if (argc != 2) { 
		fprintf(stderr, "ERROR: Incorrect command line format.\n"); 
		return EXIT_FAILURE;
	}

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin,  NULL, _IONBF, 0);

	int 			sockfd;
	struct sockaddr_in	servaddr, cliaddr;

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family 		= AF_INET;
	servaddr.sin_addr.s_addr 	= htonl( INADDR_ANY );
	servaddr.sin_port		= htons( atoi(argv[1]) );	// 9877 for TCP/UDP
	
	Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));
	
	echo_ping(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
	
	return EXIT_SUCCESS;
}

