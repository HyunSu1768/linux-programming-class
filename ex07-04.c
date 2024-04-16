#include <stdio.h>
#include <unistd.h>
int main(){

  char *arg[] = {"ls", "-l", (char *)0};
  printf("before executing is -l\n");
  execv("/bin/ls", arg);
  printf("after executing ls -l\n");
}
