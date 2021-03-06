#include<unistd.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>

int main()
{
	int file=4096; //file 
	int filedes,off=0;
	sem_t *ps;	//semaphore
	sem_t *qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	filedes=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(filedes<0)
	{
		perror("open");
		exit(1);
	}
    ftruncate(filedes, file);
	void *pbase;
	pbase=mmap(0,file, PROT_WRITE, MAP_SHARED,filedes,off);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		//close(filedes);
		exit(1);
	}
	char buf[64];
    char str[]="GENESISLINUXPROGRAMMING";
       sem_wait(ps);
	strncpy(pbase,str,20);	
	sem_post(ps);
	sem_post(qs);
	printf("BUFFER=%s\n",str);
	munmap(pbase,file);
    //shm_unlink("/shm1");
	return 0;
}
		