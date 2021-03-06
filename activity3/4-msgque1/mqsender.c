#include"message.h"
int main()
{
	int ret;
	mqd_t mqid;

	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);
	//mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,NULL);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str[]="Hello Message queue";
	int len=strlen(str);
	ret=mq_send(mqid,str,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
/*#if 1
	char str1[]="Message with pri =10";
	len=strlen(str1);
	ret=mq_send(mqid,str1,len,10);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	#endif*/
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=10;
	mqd_t mqid2;
	mqid2=mq_open("/mque2",O_RDONLY|O_CREAT,0666,&attr2);
	if(mqid2<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256,prio;
	int nbytes=mq_receive(mqid2,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	
	buf[nbytes]='\0';
	printf("receive msg from receiver :%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
	mq_close(mqid);
	mq_close(mqid2);
	return 0;
}

