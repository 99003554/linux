#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
//max value and buf size
#define maxit 5 
#define bufsiz 5 
sem_t st;
sem_t stp;
int in = 0;
int out = 0;
int buf[bufsiz];

void *producer(void *prod)
{   
    int it;
    for(int i = 0; i < maxit; i++) {
        it = rand(); // Produce a random it
        sem_wait(&st);
        /* wait for space in buf */
        while (((in + 1) % bufsiz) == out)
        {
        /* put value it into the buf */
           buf[in] = it;
           printf("Producer %d inserted it %d at %d\n", *((int *)prod),buf[in],in);
           in = (in + 1) % bufsiz;     
        }
        sem_post(&stp);
    }
}
void *consumer(void *con)
{   
    int it=0;
    for(int i = 0; i < maxit; i++) {
        sem_wait(&stp);
        while (in == out) 
        {
           it = buf[out];
           printf("Consumer %d removed it %d from %d\n",*((int *)con),it, out); 
           out = (out + 1) % bufsiz;     
        }
        sem_post(&st);
    }
}
int main()
{   
    pthread_t prod[5],cons[5];
    sem_init(&st,0,bufsiz);
    sem_init(&stp,0,0);
    int a[5] = {1,2,3,4,6}; 
    for(int i = 0; i < 5; i++) {
        pthread_create(&prod[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&cons[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(prod[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(cons[i], NULL);
    }
    sem_destroy(&st);
    sem_destroy(&stp);
    return 0;
}
