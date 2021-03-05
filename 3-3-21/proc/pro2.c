#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
//#include <sys/types.h> 
#include <sys/wait.h> 
int main()
{
    int ret = fork();
    if(ret<0)
    { 
      perror("fork");
      exit(1);
      // break;
    }
    if(ret==0)
    {
    execlp("./new",NULL);
      for (int i = 0; i < 5; i++)
      {
        printf("Child__PID = %d_____PPID = %d\n",getpid(),getppid());
        sleep(1);
      }
        //    break;
    }
      else
      {
        for (int i = 0; i < 5; i++)
        {
        printf("Parent\n");
        sleep(1);
        }
       //     break;
    }
    exit(0);
}
