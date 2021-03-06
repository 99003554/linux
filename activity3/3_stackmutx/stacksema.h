#ifndef STACKSEMA_H
#define STACKSEMA_H

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void* push(void* pv);
void* pop(void* pv);
#endif

