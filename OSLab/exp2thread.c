
#include<stdio.h>
#include<pthread.h>

void* threadFun(void* args1);

int main()
{
	pthread_t thread1,thread2;

	int t1,t2;
	int data1,data2;
	data1=3;
	data2=9;
	
	t1=pthread_create(&thread1,NULL,threadFun,(void*) data1);
	t2=pthread_create(&thread2,NULL,threadFun,(void*) data2);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}

void* threadFun(void* args1)
{
	int d;
	int i=0;
	d=(int) args1;
	for(i=0;i<100;i++)
		{
			printf(" thread=%d",d);
				
		}
}
