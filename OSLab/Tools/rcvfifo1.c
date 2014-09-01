// rcvfifo1.c
#include "fifo1.h"
int main( int argc, char *argv[])
{
int nbytes;// number of bytes read from popen()
int n = 0;
int dummyfifo; // file descriptor to write-end of PUBLIC
int publicfifo; // file descriptor to read-end of PUBLIC
static char buffer[PIPE_BUF];// buffer to store output of command

// Create public FIFO
if ( mkfifo(PUBLIC, 0666) < 0 )
     if (errno != EEXIST ) {
         perror(PUBLIC);
         exit(1);
}


if ( (publicfifo = open(PUBLIC, O_RDONLY) ) == -1 ||( dummyfifo = open(PUBLIC, O_WRONLY | O_NDELAY )) == -1){
     perror(PUBLIC);
     exit(1);
}


while ( 1 ) {
    memset(buffer, 0, PIPE_BUF);
    if ( ( nbytes = read( publicfifo, buffer, PIPE_BUF)) > 0 ) {
           buffer[nbytes] = '\0';
           printf("Message %d received by server: %s", ++n, buffer);
          fflush(stdout);
          }
      else
         break;
    }


return 0;
}
