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

    size_t words_count = 0;

    if(f == NULL) {
        return 0;
    }

    char* buffer = (char*)malloc(sizeof(char*) * max_buffer_length);

    while(fgets(buffer, max_buffer_length, f) != NULL) {

        buffer[strlen(buffer) - 1] = '\0';

        if (strlen(array) + strlen(buffer) - begin <= end) {
            words_count++;
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

    return words_count;
}

char** create_matrix(const char* array, const char* path_to_words, size_t max_buffer_length, size_t words_count) {

    size_t j = 0, k = 0, h = 0;
    char** words_arr = (char**)malloc(words_count * sizeof(char *));
    words_arr[k] = (char*)malloc(max_buffer_length * sizeof(char));

    while(array[j] != '\0') {

        if(array[j] == ' ') {
            words_arr[k][h] = '\0';
            words_arr[++k] = (char*)malloc(max_buffer_length * sizeof(char));
            j++;
            h = 0;
        }
        else {
            words_arr[k][h++] = array[j++];
        }
    }

    return words_arr;
}

char* find_max_word(char** array, size_t words_count) {

    size_t max_str_len = 0;
    char* max_word;


    for(size_t i = 0; i < words_count; i++) {
        if(max_str_len <= strlen(array[i])) {
            max_str_len = strlen(array[i]);
            max_word = array[i];
        }
    }


    return max_word;
}

bool print_array(char* array) {
    if(printf("%s\n",array) && array != NULL)
        return 1;
    return 0;
}

char* find_max_word_no_threads(size_t size, size_t max_buffer_length, const size_t procs_count, const char* path_to_words) {

    char* array = create_array(size);
    size_t words_count = fill_array(array, 0, size - 1, path_to_words, max_buffer_length);
    char** words_arr = create_matrix(array, path_to_words, max_buffer_length, words_count);
    char* max_word = find_max_word(words_arr, words_count);

    free(array);
    for(size_t i = 0; i < words_count; i++) {
        free(words_arr[i]);
    }
    free(words_arr);

    return max_word;
}
