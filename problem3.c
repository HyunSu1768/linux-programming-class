#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// 1부터 n까지의 합을 계산하는 함수
long long sum(int n) {
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

// 1부터 n까지의 곱을 계산하는 함수
long long product(int n) {
    long long total = 1;
    for (int i = 1; i <= n; i++) {
        total *= i;
    }
    return total;
}

int main() {
    int n;
    pid_t pid;

    // 사용자로부터 정수 입력 받기
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    // fork()를 사용하여 자식 프로세스 생성
    pid = fork();

    if (pid == 0) {
        // 자식 프로세스
        printf("자식 프로세스: 1부터 %d까지의 곱 = %lld\n", n, product(n));
    } else if (pid > 0) {
        // 부모 프로세스
        printf("부모 프로세스: 1부터 %d까지의 합 = %lld\n", n, sum(n));
    } else {
        // fork 실패
        fprintf(stderr, "fork() 실패\n");
        return 1;
    }

    return 0;
}

