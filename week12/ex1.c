#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <zconf.h>

#define N 20

int main() {
    unsigned char buffer[N];
    int file = open("/dev/urandom", O_RDONLY);
    if (file < 0) {
        exit(1);
    }
    read(file, buffer, N);
    close(file);
    for (int i = 0; i < N; i++) {
        printf("%c", buffer[i]);
    }
    return 0;
}