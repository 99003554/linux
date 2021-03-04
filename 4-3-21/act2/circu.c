#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 10 // Maximum items 
#define BufferSize 10 // Size of the buffer
sem_t emp;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Produce a random item
        sem_wait(&emp);
        /* wait for space in buffer */
        while (((in + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buffer[in] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
           in = (in + 1) % BufferSize;     
        }
        sem_post(&full);
    }
}



int main()
{   

    pthread_t pro[5],con[5];
    sem_init(&emp,0,BufferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) 
    {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }

    
    for(int i = 0; i < 5; i++)
    {
        pthread_join(pro[i], NULL);
    }
    return 0;
}