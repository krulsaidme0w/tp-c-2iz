#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* create_array(size_t size) {
    char *array = (char *)malloc(size);
    return array;
};

FILE* open_file(char* path) {
    FILE  *f;
    f = fopen(path, "r");

    if (f != NULL) {
        return f;
    }
    else {
        printf("can't open file\n");
        return NULL;
    }
};

bool close_file(FILE *f) {
    if(fclose(f)) {
        return 1;
    }
    else {
        return 0;
    }
};

size_t fill_array(char *array, size_t size, char* path_to_words, size_t max_buffer_length) {

    FILE *f = open_file(path_to_words);

    if(f == NULL) {
        return 0;
    }

    char* buffer = (char*)malloc(sizeof(char*) * max_buffer_length);

    while(fgets(buffer, max_buffer_length, f) != NULL) {

        buffer[strlen(buffer) - 1] = '\0';

        if (strlen(array) + strlen(buffer) < size) {
            char *t = array + strlen(array);
            strcpy(t, buffer);
        }
        else {
            break;
        }

    }

    printf("%s\n", array);
    printf("%zu\n", strlen(array));

    close_file(f);
    return 1;
};

