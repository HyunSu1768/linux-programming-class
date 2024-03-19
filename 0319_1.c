#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd;
    char buffer[1024];
    ssize_t nread; 
    int cnt, numChar = 0;

    fd = open("alpha.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while((nread = read(fd, buffer, 1024)) > 0) {
        for(cnt = 0; cnt < nread; cnt++) {
            if((buffer[cnt] >= 'a' && buffer[cnt] <= 'z') || (buffer[cnt] >= 'A' && buffer[cnt] <= 'Z'))
                numChar++;
        }
    }

    printf("%d\n", numChar);

    close(fd);
    return 0;
}

