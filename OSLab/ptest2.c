#include<stdio.h>
#include<pthread.h>

int main()
{
	int pid;
	pid=fork();
	
	if(pid==0)
		printf("I am Child");
	else
		getchar();
return 0;
	
}
