#include <stdio.h>
#include <sys/stat.h>

int is_directory_exists(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

int main() {
    char path[1024];
    
    printf("Enter the directory path: ");
    scanf("%s", path);
    
    if (is_directory_exists(path)) {
        printf("The directory '%s' exists.\n", path);
    } else {
        printf("The directory '%s' does not exist.\n", path);
    }
    
    return 0;
}

