#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int a, b;
    int sum, product;
    int fd1[2], fd2[2];

    printf("첫 번째 값을 입력하세요: ");
    scanf("%d", &a);
    printf("두 번째 값을 입력하세요: ");
    scanf("%d", &b);

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(1);
    } else if (pid1 == 0) { 
        close(fd1[0]); 
        sum = a + b;
        printf("첫 번째 자식 프로세스에서 계산한 합: %d\n", sum);
        write(fd1[1], &sum, sizeof(sum));
        close(fd1[1]); 
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(1);
    } else if (pid2 == 0) {
        close(fd2[0]); 
        product = a * b;
        write(fd2[1], &product, sizeof(product));
        close(fd2[1]); 
        exit(0);
    }

    close(fd1[1]);
    close(fd2[1]);

    read(fd1[0], &sum, sizeof(sum));
    close(fd1[0]);

    read(fd2[0], &product, sizeof(product));
    close(fd2[0]);

    wait(NULL);
    wait(NULL);

    printf("부모 프로세스에서 계산한 두 자식 프로세스의 결과들의 합: %d\n", sum + product);

    return 0;
}

