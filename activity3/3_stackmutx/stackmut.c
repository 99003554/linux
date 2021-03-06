#include "stacksema.h"

//const int max=10;
int a[20];
int top=-1;
sem_t s1;
//sem_t s2;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
void* push(void* arg)	//consumer
{
    int va=(int*)arg;
	//sem_wait(&s1);
    pthread_mutex_lock(&m1);
	if(top<=18){
        a[++top]=va;
         printf("pushed va:%d\n",va);
    }
    pthread_mutex_unlock(&m1);
    sem_post(&s1);
   //sem_post(&s2);
   
}
void* pop(void* arg)	//producer
{
    int temp=0;
   // sem_wait(&s2);
    sem_wait(&s1);
    pthread_mutex_lock(&m1);
	if(top!=-1){
        //temp+=1;
        temp=a[top--];
        printf("val:%d\n",temp);
    }
    pthread_mutex_unlock(&m1);
    //sem_post(&s1);
	//pthread_exit(temp);
}
int main()
{

    int i,val;
	pthread_t pt1,pt2;	//thread handle
   // sem_init(&s2,0,0);
    sem_init(&s1,0,0);
    for(i=0;i<15;i++){
           pthread_create(&pt1,NULL,push,(void*)i);
    }
	 for(i=0;i<15;i++){ 	
         pthread_create(&pt2,NULL,pop,NULL);
     }

	pthread_join(pt1,NULL);
	pthread_join(pt2, NULL );
   sem_destroy(&s1);
	//sem_destroy(&s2);
    pthread_mutex_destroy(&m1);
	//printf("val:%d",val);
	return 0;	//exit(0);
}
