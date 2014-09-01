// sendfifo1.c
#include "fifo1.h"
#define QUIT "quit"
int main( int argc, char *argv[])
{
int nbytes; // num bytes read
int publicfifo; // file descriptor to write-end of PUBLIC
char text[PIPE_BUF]; // Open the public FIFO for writing
if ( (publicfifo = open(PUBLIC, O_WRONLY) ) == -1) {
    perror(PUBLIC);
    exit(1);
   }

// Repeatedly prompt user for command, read it, and send to server
while (1) {
     memset(text, 0x0, PIPE_BUF); // zero string
     nbytes = read(fileno(stdin), text, PIPE_BUF);
     if ( !strncmp(QUIT, text, nbytes-1))// is it quit?
           break;
     write(publicfifo, text, nbytes);
}
// User quit; close write-end of public FIFO
close(publicfifo);
}
