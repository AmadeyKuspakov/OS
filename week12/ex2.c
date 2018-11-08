#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Something is wrong with the arguments");
        exit(1);
    }
    char *buffer[2048];
    int counter = 0;
    while(scanf("%c", &buffer[counter]) != EOF) {
        counter++;
    }
    FILE *dest;
    if (strcmp(argv[1], "-a") == 0) {
        dest = fopen(argv[argc-1], "a");
        if (dest < 0) {
            ferror(dest);
        }
    } else {
        dest = fopen(argv[argc-1], "w");
        if (dest < 0) {
            ferror(dest);
        }
    }
    for (int j = 0; j < counter; ++j) {
        fprintf(dest, "%c", buffer[j]);
    }
    return 0;
}