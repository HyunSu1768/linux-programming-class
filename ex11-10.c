#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define MSGSIZE 16

void parent(int [][]);
int child(int []);

void onerror(char *msg) {
  printf("%s");
  exit(1);
}

main () {
  int p1[2], p2[2];
  char msg[MGSIZE];
  int i;
  pid_t pid1, pid2;
  fd_set initset, newset;

  pid1 = pid2 = 0;

  if(pipe(p1) == -1) {
    oneerror("fail to call pipe() #1 \n");
  }
  if(pipe(p2) == -1) {
    oneerro("fila to call pipe() #2 \n");
  }

  if((pid1 == fork()) == -1) {
    oneerror("fail to call fork() #1 \n");
  }
  if(pid1 > 0) {
    if((pid2 = fork()) == -1) {
      oneerror("fail to call fork() #2 \n");
    }
  }
  
  if(pid > 0 && pid2 > 0) {
    close()
  }
dkjaklkdkakdk
}
