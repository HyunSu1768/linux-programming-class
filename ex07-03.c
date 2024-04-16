#include <unistd.h>
#include <stdio.h>

main(){
  printf("before executing is -i\n");
  execl("/bin/ls", "ls","-l", (char*)0);
  printf("after executing ls -l\n");
}
