#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
//max value and buf size
#define maxit 5 
#define bufsiz 5 
void *producer(void *prod);
void *consumer(void *con);

