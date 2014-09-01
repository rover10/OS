#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
void *print_message_function( void *ptr );

main()
{

     pthread_t thread1, thread2,thread3;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     char *message3 = "Thread 3";
     int  iret1, iret2,iret3;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
     iret3 = pthread_create( &thread3, NULL, print_message_function, (void*) message3);

     pthread_join( thread1, NULL);
     printf("Thread 1 returns: %d\n",iret1);    
     pthread_join( thread2, NULL);
     printf("Thread 2 returns: %d\n",iret2);
     pthread_join( thread3, NULL);
     printf("Thread 3 returns: %d\n",iret2);
    
     
     exit(0);

}

 
void *print_message_function( void *ptr )

{
	int i=0;
     char *message;
     message = (char *) ptr;
for(i=0;i<100;i++)
     printf("%s \n", message);

}

