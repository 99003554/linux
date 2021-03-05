  
#ifndef __PROCESS1_1_H
#define __PROCESS1_1_H
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
void pro1()
{
    int ret,i,stat;
	printf("welcome_Pid=%d\n",getpid());
	ret=fork();
	if(ret<0)
	{
		perror("fork not created");
		exit(1);
	}
	if(ret==0)
	{
		int a;
        char s[30];
        scanf("%s",s);
        a=execl("/usr/bin/pwd","pwd",NULL);
		if(a<0)
		{
			perror("execl not working");
			exit(10);
		}
        exit(1);
	}
	else	
	{
		printf("Parent,pid=%d,ppid=%d\n",getpid(),getppid());
		waitpid(-1,&stat,0); 
		printf("Parent--Child status=%d\n",WEXITSTATUS(stat));
	}
}
#endif
