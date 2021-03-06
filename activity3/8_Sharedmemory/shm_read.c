/* File Mapping */
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
	int file=4096; //to multiples of 4096
	int filedes,off=0;
	filedes=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(filedes<0)
	{
		perror("open");
		exit(1);
	}
	//truncate the files
    ftruncate(filedes, file);
	void *pba;
	pba=mmap(0,file, PROT_READ, MAP_SHARED,filedes,off);
	if(pba==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		//close(filedes);
		exit(1);
	}
	sem_t  *ps;
	sem_t  *qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	char buf[64];
	sem_wait(qs);
	sem_wait(ps);
        strncpy(buf,pba,10);
	printf("buf=%s\n",buf);
	strcpy(buf,pba+10);
	printf("buf=%s\n",buf);
	sem_post(ps);
	sem_unlink("s1");
	sem_unlink("s2");
	munmap(pba,file);
    return 0;
}
		









