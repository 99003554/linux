#include<pthread.h>
#include<stdio.h>	
  
void* task_body1(void* pv)
{
	int val=100,i;
	printf("A--welcome\n");
	for(i=0;i<=100;i++)
    {
		printf("A--%d\n",i);
	    val++;
    }
}
void* task_body2(void* pv)
{
	int i,val=100;
	printf("B--welcome\n");
	for(i=0;i<=100;i++)
    {
		printf("B--%d\n",i);
        val--;
    } 
} 
   int main()
   { 
    pthread_t pt1,pt2;	//thread handle
	pthread_create(&pt1,NULL,task_body1,NULL);
	pthread_create(&pt2,NULL,task_body2,NULL);
    pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
    return 0;
   }
