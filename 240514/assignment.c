#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num = 0;

main (){
  static struct sigaction act;

  void int_handle(int);

  act.sa_handler = int_handle;
  sigfillset(&(act.sa_mask));
  sigaction(SIGINT, &act, NULL);
  while(1) {
    printf("종료해봐 \n");
    sleep(1);
  }
}

void int_handle(int signum) {
  FILE *fp;
  char goodBye[10] = "Goodbye!";

  fp = fopen("a.txt", "w");

  if(fp ==NULL) {
    printf("파일 열기 실패\n");
    exit(1);
  }

  fputs(goodBye, fp);
  fclose(fp);
  exit(0);
}
