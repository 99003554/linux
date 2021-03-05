#include <stdio.h> 
#include <pthread.h> 
 // size of array 
//#define MAX 1
// maximum number of threads 
#define MAX_THREAD 5 
int a[1000] = {  }; 
int sum[5] = {}; 
int part = 0; 
//Thread for summ  
void* sum_array(void* arg) 
{ 
    // Each thread computes sum 
	  int i, ps, temp, thread_num = (__intptr_t)arg;
  for (i = 0; i < 100; i++)
    /* Adding 16 array values */
    sum[i] += a[ thread_num * 100 + i]; 
    //int thread_part = part++; 
     //for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++) 
       // sum[thread_part] += a[i]; 
} 
  
// Code 
int sum() 
{ 	
	int i;
	//pthread_t ptarr[n];
	srand(time(0));
    pthread_t threads[MAX_THREAD]; 
	for(i=0; i<1000; i++) {
    /* Assigning random value to Array */
		a[i] = random()%10;
	             }
      // Creating 5 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)(__intptr_t)i); 
      // joining 5 threads  
    for (int i = 0; i < MAX_THREAD; i++) 
    {
        pthread_join(threads[i], NULL); 
    }
      // adding sum of all 4 parts 
    int total_sum = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
     {   total_sum += sum[i]; }
      //printf("Sum is \n" ,total_sum); 
       return total_sum; 
} 

int main()
{
  printf("Sum of 1000 random numbers : %d\n", sum()); /* Print the sum */
  return 0;
}
