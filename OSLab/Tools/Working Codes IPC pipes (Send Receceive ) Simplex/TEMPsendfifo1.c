// sendfifo1.c
#include "fifo1.h"
#define QUIT "quit"
int main( int argc, char *argv[])
{
int nbytes; // num bytes read
int publicfifo; // file descriptor to write-end of PUBLIC
int readFifo; // file descriptor to READ-end of PUBLIC
int n=0;
char text[PIPE_BUF]; 
if ( (publicfifo = open(PUBLIC, O_RDWR)  == -1))
    exit(1);
   }

// Repeatedly prompt user for command, read it, and send to server
while (1) {
     

//---------------pasted----------------------------------------------for reading from other process
    memset(text, 0, PIPE_BUF);
    if ( ( nbytes = read( readFifo, text, PIPE_BUF)) > 0 ) {
           text[nbytes] = '\0';
           printf("Message %d received by server: %s", ++n,text);
          fflush(stdout);
          }
      else
  {
     memset(text, 0x0, PIPE_BUF); // zero string
     nbytes = read(fileno(stdin), text, PIPE_BUF);
     if ( !strncmp(QUIT, text, nbytes-1))// is it quit?
           break;
     write(publicfifo, text, nbytes);

}       
}
//break;
//--------------------------------------------------------------------


// User quit; close write-end of public FIFO
close(publicfifo);
}
