#include<pthread.h>
#include<stdio.h>	
int val=100;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
void* task_body1(void* pv)
{
	int i;
	//printf("A--welcome\n");
	for(i=0;i<=100;i++)
    {
		//printf("A--%d\n",i);
        pthread_mutex_lock(&m1);
	        val++;
        pthread_mutex_unlock(&m1);
       
    }
}
void* task_body2(void* pv)
{
	int i;
	//printf("B--welcome\n");
	for(i=0;i<=100;i++)
    {
		//printf("B--%d\n",i);
        pthread_mutex_lock(&m1);
            val--;
        pthread_mutex_unlock(&m1);
        //pthread_mutex_destroy(&m1);
    } 
} 
   int main()
   { 
    pthread_t pt1,pt2;	//thread handle
	pthread_create(&pt1,NULL,task_body1,NULL);
	pthread_create(&pt2,NULL,task_body2,NULL);
    pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
     pthread_mutex_destroy(&m1);
    printf("%d",val);
    return 0;
   }
