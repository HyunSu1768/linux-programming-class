#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void count_files_and_directories(const char* path, int* file_count, int* dir_count) {
    DIR* dir;
    struct dirent* entry;
    struct stat statbuf;

    // 디렉터리 열기
    dir = opendir(path);
    if (!dir) {
        printf("Failed to open directory '%s'\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // '.' 과 '..' 디렉터리는 무시
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 파일/디렉터리 경로 생성
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // 파일/디렉터리 상태 정보 가져오기
        if (stat(full_path, &statbuf) == -1) {
            continue;
        }

        // 디렉터리인지 파일인지 판별
        if (S_ISDIR(statbuf.st_mode)) {
            (*dir_count)++;
        } else {
            (*file_count)++;
        }
    }

    // 디렉터리 닫기
    closedir(dir);
}

int main() {
    char path[1024];
    int file_count = 0, dir_count = 0;

    // 사용자로부터 디렉터리 경로를 입력받음
    printf("디렉토리 : ");
    scanf("%s", path);

    // 파일과 하위 디렉터리의 개수 세기
    count_files_and_directories(path, &file_count, &dir_count);

    // 결과 출력
    printf("%d개의 파일과 %d 개의 디렉토리\n", file_count, dir_count);

    return 0;
}

