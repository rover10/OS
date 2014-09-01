#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

pid_t pid1,pid2,pid3;

printf("\nhello");

pid1=-1;
pid1=fork();

pid2=-1;
if(pid1>0){
   pid2=fork();
}

pid3=-1;
if(pid2>0){
pid3=fork();
}


if(pid1==0)
      execlp("./ch1","child1",NULL);
if(pid2==0)
   execlp("./ch2","child2",NULL);
if(pid3==0)
   execlp("./ch3","child3",NULL);
  

/*
if(pid1==0&&pid2==0&&pid3==0){
   execlp("./ch1","child1",NULL);
   
}
else if (pid2==0&&pid1>0&&pid3<=0){
   execlp("./ch2","child2",NULL);
   
}
else if (pid3==0&&pid1>0&&pid2>0){
   execlp("./ch3","child3",NULL);
}
*/

return 0;
}

