#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>


int   id;      
pid_t *sptr;    

void  SIGINT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From interrupt:got a %d (SIGINT ^C) msg\n", sig);
     signal(sig, SIGINT_handler);
}

void  SIGQUIT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From quit:got a %d (SIGQUIT ^\\) signal to quit\n", sig);
     shmdt(sptr);
     shmctl(id, IPC_RMID, NULL);
     exit(3);
}

void main(void)
{
     int   i;
     pid_t pid = getpid();
     key_t key;

     if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
          printf("INT install error\n");
          exit(1);
     }
     if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) {
          printf("QUIT install error\n");
          exit(2);
     }

     key   = ftok(".", 's');    
     id   = shmget(key, sizeof(pid_t), IPC_CREAT | 0666);
     sptr = (pid_t *) shmat(id, NULL, 0);
     *sptr = pid;               

     for (i = 0; ; i++) {        
          printf("From process %d: %d\n", pid, i);
          sleep(1);
     }
}
