#include <stdio.h>
#include <unistd.h>

int main(){
    symlink("a.txt", "b.txt");
    if (access("b.txt", F_OK) == -1) {
        printf("b.txt로의 소프트 링크는 유효하지 않습니다. (원본 파일이 삭제되었을 수 있습니다.)\n");
    } else {
        printf("b.txt로의 소프트 링크는 유효합니다.\n");
    }

    return 0;
}
