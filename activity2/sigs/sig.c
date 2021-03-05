
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
   
// sighup() function 
void sighup() 
{ 
    signal(SIGHUP, sighup); 
    printf("CHILD:SIGHUP\n"); 
} 
// sigint() function  
void sigint() 
{ 	/*Interrupt*/
    signal(SIGINT, sigint); 
    printf("CHILD:SIGINT\n"); 
} 
// sigquit() function  
void sigquit() 
{ 	/*Terminate*/
    printf("Child process killed\n"); 
    exit(0); 
}  
void main() 
{ 
    int pid; 
   /* get child process */
    pid = fork();
    if (pid < 0) 
    { 
        perror("fork"); 
        exit(1); 
    } 
     if (pid == 0) 
     { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        /* Infinity loop */
        for (;;) 
            ; 
    } 
     else /* parent */
    { /* pid of child */
        printf("\nPARENT:SIGHUP\n"); 
        kill(pid, SIGHUP); 
	/* sleep for 5 secs */
	sleep(5); 
        printf("\nPARENT: SIGINT\n"); 
        kill(pid, SIGINT); 
        /* sleep 5 secs */
        sleep(5); 
        printf("\nPARENT: SIGQUIT\n"); 
        kill(pid, SIGQUIT); 
        sleep(5); 
    } 
} 
