#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
  int fd[2];
  pid_t pid;
  int num1, num2;

  if(pipe(fd) == -1) {
    perror("pipe");
    exit(1);
  }

  printf("첫 번째 숫자를 입력해 주세요 : ");
  scanf("%d", &num1);
  
  printf("두 번째 숫자를 입력해 주세요 : ");
  scanf("%d", &num2);

  pid = fork();

  if(pid < 0) {
    perror("fork");
    exit(1);
  } else if(pid > 0) {
    close(fd[0]);

    write(fd[1], &num1, sizeof(int));
    write(fd[1], &num2, sizeof(int));
    close(fd[1]);

    wait(NULL);
  } else {
    int a,b;
    close(fd[1]);

    read(fd[0], &a, sizeof(int));
    read(fd[0], &b, sizeof(int));
    close(fd[0]);
ㅜ
    printf("두 숫자의 합 : %d", a+b);
    exit(0);
  }
  return 0;
}
