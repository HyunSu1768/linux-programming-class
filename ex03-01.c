#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int filedes, fdnew1, fdnew2;
	ssize_t nread;
	off_t newpos;

	char buffer[1024];
	char content[]="Hello my friend!!\n";

	filedes = open("data.txt", O_RDWR);
	
	nread=read(filedes, buffer, 1024);
	printf("%s", buffer);
}
