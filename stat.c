#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include "job.h"
#define DEBUG

/* 
 * 命令语法格式
 *     stat
 */

void JGDebugTask5_2(int cmdtype, int owner)
{
	#ifdef DEBUG
		printf("statcmd cmdtype\t%d (-1 means enq, -2 means deq, -3 means stat)\n", cmdtype);
		printf("statcmd owner:\t%d\n", owner);
	#endif
}

void usage()
{
	printf("Usage: stat\n");		
}

int main(int argc,char *argv[])
{
	struct jobcmd statcmd;
	int fd;

	if(argc!=1)
	{
		usage();
		return 1;
	}

	statcmd.type=STAT;
	statcmd.defpri=0;
	statcmd.owner=getuid();
	statcmd.argnum=0;

	JGDebugTask5_2(statcmd.type, statcmd.owner);

	if((fd=open("/tmp/server",O_WRONLY))<0)
		error_sys("stat open fifo failed");

	if(write(fd,&statcmd,DATALEN)<0)
		error_sys("stat write failed");

	close(fd);
	return 0;
}
