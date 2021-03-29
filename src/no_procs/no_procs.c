#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "no_procs.h"

char* create_array(size_t size) {
    char *array = (char *)malloc(size);
    return array;
}

FILE* open_file(const char* path) {
    FILE  *f;
    f = fopen(path, "r");

    if (f != NULL) {
        return f;
    }
    else {
        printf("can't open file\n");
        return NULL;
    }
}

bool close_file(FILE *f) {
    if(!fclose(f)) {
        return 1;
    }
    else {
        return 0;
    }
}

size_t fill_array(char *array, size_t begin, size_t end, const char* path_to_words, size_t max_buffer_length) {

    FILE *f = open_file(path_to_words);

    if(f == NULL) {
        return 0;
    }

    char* buffer = (char*)malloc(sizeof(char*) * max_buffer_length);

    while(fgets(buffer, max_buffer_length, f) != NULL) {

        buffer[strlen(buffer) - 1] = '\0';

        if (strlen(array) + strlen(buffer) - begin <= end) {
            char *t = array + strlen(array);
            strcpy(t, buffer);
        }
        else {
            break;
        }

    }

    if(!close_file(f)) {
        return 0;
    }

    return strlen(array);
}

char* find_max_word(const char* array, size_t begin, size_t end, size_t max_buffer_length) {

    size_t max_length = 0;
    char *max_word = NULL;

    size_t word_length = 0;
    char* word = (char*)malloc(sizeof(char*) * max_buffer_length);


    for(size_t i = begin; i <= end; ++i) {
        char c = array[i];

        if(c != ' ') {
            word[word_length] = array[i];
            word_length++;
        }
        else {
            if(word_length > max_length) {
                word[word_length] = '\0';
                max_length = word_length;
                max_word = word;
            }
            word = (char*)malloc(sizeof(char*) * max_buffer_length);
            word_length = 0;
        }
    }

    return max_word;

}

bool print_array(char* array) {
    if(printf("%s\n",array))
        return 1;
    return 0;
}