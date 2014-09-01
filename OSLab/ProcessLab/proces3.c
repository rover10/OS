//creating a separate process using the UNIUX fork() system call
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){

   pid_t pid,pid2;
   printf("initail id1=%d,id2=%d",pid=fork(),pid2=fork());
   //printf("Rakesh process id=%d",pid); 


  if(pid<0){
     fprintf(stderr,"Fork Failled");
     return 1;
   }
   else if(pid==0){
     printf("Child Process 1 STARTS%d",pid); 
     execlp("./child.out","child2",NULL);
    }
   else if(pid2==0){
     printf("Child Process 2 STARTS%d",pid);
     execlp("./child2.out","child",NULL);
     }

//will the code below in thi block ever executes ????   
  /*int i=0; 
     for(i=0;i<100;i++)
       printf("After ls command%d",pid); 
    
   */
   else{
     //wait(NULL);//parent processs waits for child process to complete its task..then it reumes its task..
                //try to see the output by running this program after compiling without wait(NULL) system call
         int i=0;
         for(i=0;i<10000;i++)    
	   printf(".");
   //  printf("\nRakesh process id=%d",pid); 
    }
   return 0;
}
