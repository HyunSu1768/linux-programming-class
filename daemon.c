#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(){
  int pid;

  pid = fork();

  if(pid < 0) {
    printf("fork Error... : return is [%d] \n", pid );
    perror("fork error : ");
    exit(0);
  } else if(pid > 0) {
    printf("child process : [%d] - parent process : [%d] \n", pid, getpid());
    exit(0);
  } else if(pid==0){
    printf("process : [%d]\n", getpid());
  }

  setsid();
  int fd;
  while(1) {
  time_t t = time(NULL);
  char *buf = ctime(&t);
  
  fd = open("curtime.txt", O_RDWR | O_CREAT, 0644);
  write(fd, buf, strlen(buf));

  sleep(10);
  }

}
