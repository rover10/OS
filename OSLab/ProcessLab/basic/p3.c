//Experimental program
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
pid_t pid1,pid2,pid3;
printf("\nHello");

printf("%d\n%d",pid1=fork(),pid2=fork());
return 0;
}
