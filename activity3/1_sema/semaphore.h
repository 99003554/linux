#ifndef __SEMAPHORE_H
#define __SEMAPHORE_H
//defining
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void* consumer(void* arg);
void* producer(void* arg);
#endif