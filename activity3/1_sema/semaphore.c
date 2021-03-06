#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>
#define maxitem 5 // Maximum items 
#define bufsiz 5 // Buffer size
sem_t s1;
sem_t s2;
int inside = 0;
int out = 0;
int item=0;
int buffer[bufsiz];
void *consumer(void *con)
{   
    if(out==bufsiz-1)
    {
        printf("Stack is empty-can't consume\n");

    }
    else
    {
     int item=0;
     for(int i = 0; i < maxitem; i++) {
        sem_wait(&s2);
        item = buffer[out];
        printf("Consumer %d: Remove an Item %d from %d\n",*((int *)con),item, out); 
        out = (out + 1) % bufsiz;     
        sem_post(&s1);
     }
    }
}
void *producer(void *prod)

{   
    if(inside==bufsiz-1)
    {
        printf("stack is full- Producer can produce \n");
    }
    else
    {
     for(int i = 0; i < maxitem; i++) {
        item = rand(); // Produce a random item
        sem_wait(&s1);
        /* put value item into the buffer */
        buffer[inside] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)prod),buffer[inside],inside);
        inside = (inside + 1) % bufsiz;     
        sem_post(&s2);
     }
    }
}
int main()
{   
    pthread_t prod[5],cons[5];
    sem_init(&s1,0,bufsiz);
    sem_init(&s2,0,0);
    int arr[5] = {2,4,6,8,9}; 
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&prod[i], NULL, (void *)producer, (void *)&arr[i]);
    }
    for(int i = 0; i < 5; i++) 
    {
        pthread_create(&cons[i], NULL, (void *)consumer, (void *)&arr[i]);
    }
    for(int i = 0; i < 5; i++) 
    {
        pthread_join(prod[i], NULL);
    }
    for(int i = 0; i < 5; i++) 
    {
        pthread_join(cons[i], NULL);
    }
    sem_destroy(&s1);
    sem_destroy(&s2);
    return 0;
}