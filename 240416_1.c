#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  int x,y;

  while(1) {
    printf("x,y의 값은 1이상 10이하이고 x가 y보다 작은 수를 입력하세요. ( x,y 순서대로 )\n");
    scanf("%d %d", &x, &y);
    if((x > 0 && x <= 10) && (y > 0 && y <= 10) && (x < y)) {
      break;
    }
    printf("다시 입력하세요\n");
  }

  pid_t pid;

  pid = fork();

  if(pid == 0) {
    int result = 0;
    for(int i=x;i<=y;i++) {
      result += i;
    }

    printf("%d 부터 %d까지의 합: %d\n", x,y, result);
    return result;
  }
  else if(pid > 0) {
    int status;
    wait(&status);

    int child_result = WEXITSTATUS(status);
    int result = 1;
    for(int i=1;i<=y;i++) {
      result *= x;
    }

    printf("%d의 %d승은 : %d\n", x,y,result);
    printf("최종 결과값 : %d", child_result + result);
  }
}
