
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
   
// sighup() function 
void sighup() 
{ 
    signal(SIGHUP, sighup); /* reset signal */
    printf("CHILD:SIGHUP\n"); 
} 
// sigint() function  
void sigint() 
{ 
    signal(SIGINT, sigint); /* reset signal */
    printf("CHILD:SIGINT\n"); 
} 
// sigquit() function  
void sigquit() 
{ 
    printf("Child process killed\n"); 
    exit(0); 
}  
void main() 
{ 
    int pid; 
   /* get child process */
    pid = fork();
    if (pid < 0) { 
        perror("fork"); 
        exit(1); 
    } 
     if (pid == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; /* loop for ever */
    } 
     else /* parent */
    { /* pid hold id of child */
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
        sleep(5); /* pause for 5 secs */
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
        sleep(5); /* pause for 5 secs */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(5); 
    } 
} 
