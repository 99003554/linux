#ifndef __SEMAPHORE_H
#define __SEMAPHORE_H
//defining
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void* push(void* pv);
void* pop(void* pv);
#endif