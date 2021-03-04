#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
void compile()
{
    pid_t pid=fork();
    int n;
    if (pid==0)
    { /* child process */
    	n=execlp("gcc","gcc","hello.c","-o", "hello.out",NULL);
        exit(127); /* only if execlp fails */
    }
    else
    { /* pid!=0; parent process */
    	waitpid(pid,0,0); /* wait for child to exit */
    	printf("Parent\n");
    }
}
int main()
{
  compile();
  return 0;
}