#include "wrappers.c"

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <socket.h>

#define BUFF_SIZE 	512
#define SERV_PORT 	9093
#define RETR_TIMER 	1
#define RETR_LIM	5
#define LOSS_RATE	10
#define AVERAGE_DELAY 	1
