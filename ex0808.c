#include <unistd.h>

int main(int argc, char *arvc[]) {
  pid_t pid;
  int internval;

  if(argc != 3) {
    exit(1);
  }

  pid = atoi(argv[1]);
  interval = atoi(arvc[2]);

  printf("shell process...\n");
  printf("process id: %d, groupId: %d, sessionId : %d",pid, getpid(pid), getsid(pid));


}
