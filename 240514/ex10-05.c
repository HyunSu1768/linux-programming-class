#include <stdio.h>
#include <unistd.h>
#include <signal.h>

main(){
  sigset_t set;
  int count = 5;
  

  sigemptyset(&set);
  sigfillset(&set);
  sigprocmask(SIG_BLOCK, &set, NULL);
  while(count) {
    printf("dont disturb me (%d)\n", count--);
    sleep(1);
  }
  
  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigprocmask(SIG_UNBLOCK, &set, NULL);

  printf("you did not disturb me!!\n");
}
