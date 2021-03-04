#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h>
#define max 12
#define Th_max 4 
int a[max] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 
               22, 300, 220 }; 
  
// Array to store max of threads 
int max_n[Th_max] = { 0 }; 
int no = 0; 
// Function to find maximum 
void maximum(void* arg) 
{ 
    int i, num ; 
    int maxs = 0; 
  
    for (i = num * (max / 4); i < (num + 1) * (max / 4); i++) 
    { 
        if (a[i] > maxs) 
            maxs = a[i]; 
    }   
    max[num] = maxs; 
} 
// Main function
int main() 
{ 
    int maxs = 0; 
    int i; 
    pthread_t threads[Th_max]; 
     // creating 4 threads 
    for (i = 0; i < Th_max; i++) 
        pthread_create(&threads[i], NULL, maximum, (void*)NULL); 
      // joining threads 
    // all 4 threads to complete 
    for (i = 0; i < Th_max; i++) 
        pthread_join(threads[i], NULL); 
      // Finding max element in an array 
    // by individual threads 
    for (i = 0; i < Th_max; i++) { 
        if (max_n[i] > maxs) 
            maxs = max_n[i]; 
    }   
    printf("Max: %d", maxs); 
    return 0; 
} 
