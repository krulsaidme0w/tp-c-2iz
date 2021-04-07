#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "no_procs.h"
#include "with_procs.h"
#include "menu.h"

//consts for no_procs
#define SIZE 10485760
#define MAX_BUFFER_LENGTH 400
#define PATH_TO_FILE "words.txt"

//consts for with_procs
#define PROCS_COUNT 2


char get_char() {
    char c = '\0';
    int result = 0;

    do {
        result = scanf("%c", &c);
    } while (result != 1);

    return c;
}

char *get_string() {

    struct buffer {
        char *string;
        size_t size;
        size_t capacity;
    } buf = {NULL, 0, 0};

    char c = '\0';

    while (c = get_char(), c != EOF && c != '\n') {
        if (buf.size + 1 >= buf.capacity) {
            size_t new_capacity = !buf.capacity ? 1 : buf.capacity * 2;
            char *tmp = (char *)malloc((new_capacity + 1) * sizeof(char));
            if (!tmp) {
                if (buf.string) {
                    free(buf.string);
                }
                return NULL;
            }
            if (buf.string) {
                tmp = strcpy(tmp, buf.string);
                free(buf.string);
            }
            buf.string = tmp;
            buf.capacity = new_capacity;
        }
        buf.string[buf.size] = c;
        buf.string[buf.size + 1] = '\0';
        ++buf.size;
    }

    return buf.string;
}

size_t menu_max_len(size_t size, size_t max_buffer_length, size_t procs_count, const char* path_to_file) {
    clock_t begin = clock();

    char* max_word = NULL;

    if(procs_count > 1) {
        max_word = find_max_word_procs(size, max_buffer_length, procs_count, path_to_file);

        if (max_word == NULL) {
            return 0;
        }
    }

    else {
        max_word = find_max_word_no_procs(size, max_buffer_length, procs_count, path_to_file);

        if (max_word == NULL) {
            return 0;
        }
    }

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    if(max_word == NULL) {
        printf("can't find max_word\n");
        return 0;
    }
    size_t res = strlen(max_word);

    printf("\nlongest word: %s\n", max_word);
    printf("length: %zu\n", strlen(max_word));
    printf("time: %f\n", time_spent);
    free(max_word);
    return res;
}

void menu() {
    char* command = "0";
    char* info = "0";
    char* no_procs = "1";
    char* with_procs = "2";
    char* exit = "3";

    do
    {
        if(!strcmp(command, info)) {
            printf("0. help\n");
            printf("1. create array(no threads)\n");
            printf("2. create array(with processes)\n");
            printf("3. exit");
            continue;
        }

        else if(!strcmp(command, no_procs)) {

            menu_max_len(SIZE, MAX_BUFFER_LENGTH, 0, PATH_TO_FILE);

            continue;
        }

        else if(!strcmp(command, with_procs)) {

            menu_max_len(SIZE, MAX_BUFFER_LENGTH, PROCS_COUNT, PATH_TO_FILE);

            continue;
        }

        else if(!strcmp(command, exit)) {
            printf("\ngoodbye!\n");
            break;
        }

        else {
            printf("unknown command: %s\n", command);
        }

    } while(printf("\ninput command number (0 - help): "), command = get_string(), command != NULL);

}
