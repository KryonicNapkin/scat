#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// TODO: parse the filepath

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stdout, "Usage: scat [FILE]\n");
        return EXIT_SUCCESS;
    }

    struct stat st = {0};
    if (stat(argv[1], &st) == -1) {
        perror("Error");
        return EXIT_FAILURE;
    }
    printf("%s\n", argv[1]);
    return EXIT_SUCCESS;
}
