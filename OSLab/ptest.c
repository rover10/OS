#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
extern int arr[];
int main()
{

printf("INSIDE MAIN");
int arr[10];

	int i=0;
for(i=0;i<10;i++){
	arr[i]=0;
	printf("%d",arr[i]);
	
}
	int pid;
	char cmd[20];
	char *const parmlist[]={NULL};

	if((pid=fork())==-1)
		perror("fork error");
	else
		{

			execvp("./p1.out",parmlist);
				printf("next line");			
			execvp("time",parmlist);
		}
for(i=0;i<10;i++){
	printf("%d",arr[i]);
}
return 0;
}
