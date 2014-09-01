#include<stdio.h>
#include<pthread.h>

/*
        pthread_t to declare a thread. eg pthread_t t1,t2;
        pthread_create a thread
        Each thread is idenfied by an integre variable eg. int idthread1;
        pthread_create() takes four parameters:

                1. thread variable address ie. &t1 or &t2
                2. NULL
                3. function's name
                4. argument of the function

        when we call the function pthread_create then it returns an integer
        this Integer is stored in int variable,
                                                eg. t1id=pthread_create(...)
*/

void* myFun(void* n);   //must have void* as parameter type & return type as void*

int main()
{
        pthread_t t1,t2;
        int t1id,t2id;
        
        int myarg1=1;
        int myarg2=2;
        
        t1id=pthread_create(&t1,NULL,myFun,(void*) myarg1);
	printf("\nThread 1 created state=%d",t1id);        
	t2id=pthread_create(&t2,NULL,myFun,(void*) myarg2);        
	printf("\nThread 2 created state=%d",t2id);       
        
    pthread_join(t1,NULL);/*blocking state; if you dn't provide it..the thread still runs but if you want 
				to execute a particular statement just after the end of a particular thread 
				then you must write this statement...it ensures that the statement would 
				executes after the thread completes its job
			*/

	printf("\nExecution of thread 1 Ended");     		 //this statement executes only after thread1 ends its execution
	pthread_join(t2,NULL);					//blocking state
	printf("\nExecution of thread 2 Ended");	       //this statement executes only after thread1 ends its execution

return 0;
}       

void* myFun(void* n)
{
	int rc;
	rc=(int) n; //casting required as n is pointer to void
        int i=0;
        for(i=0;i<100;i++)
                printf("\nT=%d i=%d",rc,i);
return 0;
}
