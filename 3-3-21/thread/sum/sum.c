#include <stdio.h> 
#include <pthread.h> 
  
// size of array 
#define MAX 12
  
// maximum number of threads 
#define MAX_THREAD 5 
  
int a[] = { 0, 15, 27, 10, 52, 34, 22, 14, 13, 42, 5, 25, 30, 4, 120, 240 }; 
int sum[5] = { 0 }; 
int part = 0; 
//Thread for summ  
void* sum_array(void* arg) 
{ 
    // Each thread computes sum 
    int thread_part = part++; 
     for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++) 
        sum[thread_part] += a[i]; 
} 
  
// Driver Code 
int main() 
{ 
  
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 5 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 
      // joining 5 threads  
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all 4 parts 
    int total_sum = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total_sum += sum[i]; 
  
    cout << "sum is " << total_sum << endl; 
  
    return 0; 
} 
