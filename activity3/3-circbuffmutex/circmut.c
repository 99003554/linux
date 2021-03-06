#include"circ.h"
int in = 0;
int out = 0;
int buf[bufsiz];
pthread_mutex_t mutex;
void *producer(void *prod)
{   
    int it;
    for(int i = 0; i < maxit; i++) {
        it = rand(); // Produce a random it
        pthread_mutex_lock(&mutex);
        /* wait for space in buf */
        while (((in + 1) % bufsiz) == out)
        {
        /* put value it into the buf */
           buf[in] = it;
           printf("Producer %d inserted it %d at %d\n", *((int *)prod),buf[in],in);
           in = (in + 1) % bufsiz;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *con)
{   
    int it=0;
    for(int i = 0; i < maxit; i++) {
        pthread_mutex_lock(&mutex);
        while (in == out) 
        {
           it = buf[out];
           printf("Consumer %d removed it %d from %d\n",*((int *)con),it, out); 
           out = (out + 1) % bufsiz;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

 
int main()
{   //creating a thread
    pthread_t prod[5],cons[5];
	pthread_mutex_init(&mutex, NULL);
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
    pthread_mutex_destroy(&mutex);
    return 0;
}