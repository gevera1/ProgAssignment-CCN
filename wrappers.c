#include "unpv13e/lib/unp.h"
#include <errno.h>

extern int errno;

const char *
Inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
	const char	*ptr;

	if (strptr == NULL)		/* check for old code */
		fprintf(stderr, "NULL 3rd argument to inet_ntop\n");
	if ( (ptr = inet_ntop(family, addrptr, strptr, len)) == NULL)
		fprintf(stderr, "inet_ntop error, errno: %s\n", strerror(errno) );		/* sets errno */
	return(ptr);
}

void
Inet_pton(int family, const char *strptr, void *addrptr)
{
	int		n;

	if ( (n = inet_pton(family, strptr, addrptr)) < 0)
		fprintf(stderr, "inet_pton error for %s\n", strptr);	/* errno set */
	else if (n == 0)
		fprintf(stderr, "inet_pton error for %s\n", strptr);	/* errno not set */

	/* nothing to return */
}

void 	
Bind(int fd, const struct sockaddr *sa, socklen_t salen) 
{
	if (bind(fd, sa, salen) < 0) { fprintf(stderr, "bind error\n"); }
}

int 	
Socket(int family, int type, int protocol) 
{
	int		n;

	if ( (n = socket(family, type, protocol)) < 0 ) { fprintf(stderr, "socket error\n"); }
	return n;
}

ssize_t 
Recvfrom(int fd, void *ptr, size_t nbytes, int flags, struct sockaddr *sa, socklen_t *salenptr)
{
	ssize_t		n;

	if ( (n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr)) < 0) { 
		if (errno != EINTR) { fprintf(stderr, "recvfrom error: %s\n", strerror(errno)); }
	}
	return n;
}

void
Sendto(int fd, const void *ptr, size_t nbytes, int flags, const struct sockaddr *sa, socklen_t salen)
{
	if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes) { fprintf(stderr, "sendto error\n"); }
}
