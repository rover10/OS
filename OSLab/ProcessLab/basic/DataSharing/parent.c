#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#define BUFFER_SIZE 10;

typedef struct{
char ch[10];
}buffer;

int main(){

item buffer[10];



   pid_t p1=-1,p2=-1;
   p1=fork();

   if(p1>0)
      p2=fork();

   if(p1<0){
     printf("Error in creating process 1");
   else if(p1==0&&p2<0)
     execlp("./cp1","ChildProcess1",NULL);

  if(p1<0&&p2<0)
     printf("Error in creating process 2");
  else if(p2<0&&p1<0)
     printf("Error in creating process 2");
  else if(p1>=0&&p2>=0)
     execlp("cp2","ChildProcess2",NULL);
   
int i=0,j=0;
for(i=0;i<10;i++){
   printf("\n%c",item[i].ch[0];
}
}
