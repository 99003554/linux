#include "timeth.h"

void *task_body_time(void* pv)
{
  int i=0;
  time_t t;
  struct tm* current_time;
  /* Get current time in seconds */
  t = time(NULL);
  /* hh : mm : ss*/
  current_time = localtime(&t);
  printf("%02d : %02d : %02d \n",current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}
void getTime()
{
  int i, n=5;
  pthread_t parr[n];

  for(i=0; i<n; ++i)
  {
    /* Create a thread to get current time */
    pthread_create(&parr[i], NULL, task_body_time, (void *)(__intptr_t)i);
    /* Sleep for 3 seconds */
    sleep(5);
  }
  for(i=0; i<n; i++)
  {
    pthread_join(parr[i], NULL);
  }
}

