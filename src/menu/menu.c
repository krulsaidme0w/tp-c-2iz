#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "no_threads.h"
#include "with_threads.h"
#include <pthread.h>
#include "menu.h"
#include <time.h>

//const size_t SIZE = 100 * 1024 * 1024;
const size_t SIZE = 100 * 1024 * 32;
const size_t MAX_BUFFER_LENGTH = 400;
const char* PATH_TO_FILE = "/home/krul/Documents/tp-c-2iz/src/words_gen/words.txt";

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

void menu() {
    char* command = "0";

    do
    {
        if(!strcmp(command, "0")) {
            printf("0. help\n");
            printf("1. create array(no threads)\n");
            printf("2. create array(with threads)\n");
            printf("3. exit");
            continue;
        }

        else if(!strcmp(command, "1")) {

            clock_t begin = clock();

            char* array = create_array(SIZE);
            size_t array_length = fill_array(array, SIZE, PATH_TO_FILE, MAX_BUFFER_LENGTH);
            char* max_word = find_max_word(array, array_length, MAX_BUFFER_LENGTH);

            clock_t end = clock();

            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

            printf("longest word: %s\n", max_word);
            printf("length: %zu\n", strlen(max_word));
            printf("time: %f\n", time_spent);
            //print_array(array);

            free(array);
            continue;
        }

        else if(!strcmp(command, "2")) {
            continue;
        }

        else if(!strcmp(command, "3")) {
            printf("goodbye!\n");
            break;
        }

        else {
            printf("unknown command: %s\n", command);
        }

    } while(printf("\ninput command number (0 - help): "), command = get_string(), command != NULL);

}