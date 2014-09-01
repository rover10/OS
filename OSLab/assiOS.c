#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int count[5]={0};
int inputs[10000]={0};
void *job(void *);
pthread_mutex_t mutexprotect;

int main(){

	pthread_t t[5];
	int tstatus[5];
	int i=0,j=0;
	time_t tim;

	
	
/////////////////////////////////////////////////////////////////////////// This code section is generating same ////////// 
/**/	srand((int) tim);//initialize the random function 		//  sequence whenever I run the program. 	//
/**/	for(j=0;j<10000;j++){						//  Can anyone explain Why is it so???		//
/**/		inputs[j]=(rand()%5);					//						//
/**/		printf("%d",inputs[j],"\n");				//						//
/**/		}							//						//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(i=0;i<5;i++){
		tstatus[i]=pthread_create(&t[i],NULL,job,(void*) i);
		printf("Thread Started =%d \n",i);
		}
	
	for(i=0;i<5;i++)
		pthread_join(t[i],NULL);
	
	int total=0;  
	for(i=0;i<5;i++){
		printf("\nCount of %d=%d",i,count[i],"\n");
		total=total+count[i];
		}

	printf("\nTotal=%d",total);
	//printf("thread execution terminated !");
}

void *job(void *i){
	
	int j=0;
	j=(int) i;
	int k=0;
	k=j;

	while(k<10000){
		//printf("\nThread=%d k=%d",j,k,"\n");
		pthread_mutex_lock(&mutexprotect);
		switch (inputs[k]){
			case 0:	
				count[0]++;
				break;
			 case 1:	
				count[1]++;
				break;
			 case 2:	
				count[2]++;
				break;
			 case 3:	
				count[3]++;
				break;
			 case 4:	
				count[4]++;
				break;
				
			}	
		pthread_mutex_unlock(&mutexprotect);
		k=k+5;
			//printf("Running Thread %d",j);
		}
	pthread_exit((void*) 0);
}

