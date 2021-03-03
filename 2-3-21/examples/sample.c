#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
   int s = fork();
    printf("Hi: %d\n",s);
    switch(s)
    {
        case 0:
            execlp("./b.out",NULL);
            /*
            printf("child\n%d,%d",getpid(),getppid() );
            break;*/
        case -1:
            printf("fork");
            exit(1);
            break;
        default:
            for(int i=0; i<10;i++)
            {printf("Parent\n PID=%d, PPID=%d\n",getpid(),getppid());}
    }
    exit(0);
}