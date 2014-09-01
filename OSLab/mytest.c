#include<pthread.h>
#include<stdio.h>

void (*myblock)(void *message);
int main()
{

pthread_t thread1,thread2,thead3;
int t1,t2,t3;

t1=pthread_create(&thread1,NULL,myblock,(void*)message);

t2=pthread_create(&thread2,NULL,myblock,(void*)message);

t2=pthread_create(&thread3,NULL,myblock,(void*)message);

char *message2={"thread1_sms"};

char *message1={"thread1_sms"};


pthread_join(thread1,NULL);

pthread_join(thread2,NULL);

pthread_join(thread3,NULL);


return 0;
}

void (*myblock)(void *message)
{
printf("Thread",(char *) message);
}
