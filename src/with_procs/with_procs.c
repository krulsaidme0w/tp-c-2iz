#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "no_procs.h"
#include "with_procs.h"


char* find_max_word_procs(size_t size, size_t max_buffer_length, const size_t procs_count, const char* path_to_words) {

    char* array = create_array(size);

    pid_t* pids = (pid_t *) malloc(sizeof(pid_t *) * procs_count);

    size_t begin = 0;
    size_t end = size / procs_count;

    for(size_t i = 0; i < procs_count; ++i) {
        switch (pids[i] = fork()) {
            case -1:{
                printf("can't create process\n");
                return NULL;
            }
            case 0:{
                if(!(begin = fill_array(array, begin, end, path_to_words, max_buffer_length))) {
                    printf("can't fill the array with procs\n");
                    return NULL;
                }
                end = (i + 2) * size / procs_count;
                printf("%s\n", array);
                printf("%zu\n", strlen(array));
            }
            default:{
                printf("asd");
            }
        }
    }


    return array;
}


