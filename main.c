#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// TODO: parse the filepath
// TODO: print the file

#define LINE_LENGHT 1024

char* get_entire_file(const char* filepath);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stdout, "Usage: scat [FILE]\n");
        return EXIT_SUCCESS;
    }

    char* file = get_entire_file(argv[1]);
    if (file == NULL) {
        perror("Error");
        return EXIT_FAILURE;
    }
    printf("%s", file);

    free(file);
    return EXIT_SUCCESS;
}

char* get_entire_file(const char* filepath) {
    FILE* fp = fopen(filepath, "r");
    if (fp == NULL) return NULL;

    fseek(fp, 0, SEEK_END);
    size_t fsize = ftell(fp);
    rewind(fp);

    char* file_string = malloc(fsize);
    char line[LINE_LENGHT];

    while (fgets(line, LINE_LENGHT, fp) != NULL) {
        strcat(file_string, line);
    }

    fclose(fp);
    return file_string;
}
