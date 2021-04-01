#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "no_procs.h"
#include "with_procs.h"

typedef struct {
    long mtype;
    char mtext[1024];
} Message;

const long message_t = 696969;

char* find_max_word_procs(size_t size, size_t max_buffer_length, const size_t procs_count, const char* path_to_words) {

    int status;

    char* array = create_array(size);
    size_t words_count = fill_array(array, 0, size - 1, path_to_words, max_buffer_length);
    char** words_arr = create_matrix(array, path_to_words, max_buffer_length, words_count);

    size_t part_size = words_count / procs_count;

    key_t key = IPC_PRIVATE;
    int qid = msgget(key, 0666 | IPC_CREAT);
    pid_t* pids = (pid_t *)malloc(sizeof(pid_t) * procs_count);

    if(pids == NULL) {
        printf("can't allocate memory for pids\n");
        return NULL;
    }

    for(size_t i = 0; i < procs_count; ++i) {
        pids[i] = fork();

        if (pids[i] != 0) {
            continue;
        }

        char* max_word = NULL;

        if(array == NULL) {
            printf("can't fill the array\n");
            exit(EXIT_FAILURE);
        }

        size_t max_len = 0;

        if(i == procs_count - 1) {
            for(size_t j = i * part_size; j < words_count; ++j) {
                if(strlen(words_arr[j]) >= max_len) {
                    max_len = strlen(words_arr[j]);
                    if(max_word != NULL)
                        free(max_word);
                    max_word = (char*)malloc(max_buffer_length * sizeof(char));
                    strcpy(max_word, words_arr[j]);
                }
            }
        }
        else {
            for(size_t j = i * part_size; j < (i + 1) * part_size; ++j) {
                 if(strlen(words_arr[j]) >= max_len) {
                     max_len = strlen(words_arr[j]);
                     if(max_word != NULL)
                         free(max_word);
                     max_word = (char*)malloc(max_buffer_length * sizeof(char));
                     strcpy(max_word, words_arr[j]);
                 }
            }
        }


        if(max_word == NULL) {
            printf("can't find no_procs\n");
            exit(EXIT_FAILURE);
        }

        Message message = {message_t, ""};
        strcpy(message.mtext, max_word);

        if(-1 == msgsnd(qid, (struct msgbuf *)&message, strlen(message.mtext) + 1, 0)) {
            printf("can't send msg\n");
            exit(EXIT_FAILURE);
        }

        free(max_word);

        exit(EXIT_SUCCESS);
    }

    for (size_t i = 0; i < procs_count; ++i) {
        if (waitpid(pids[i], &status, 0) != pids[i]) {
            printf("can't wait for pids\n");
            free(pids);
            return NULL;
        }
    }

    char* max_word = NULL;
    size_t max_len = 0;

    for (size_t i = 0; i < procs_count; ++i) {
        Message message;

        if(-1 == msgrcv(qid, (struct msgbuf *)&message, max_buffer_length, message_t, 0)) {
            printf("can't receive msg\n");
            free(pids);
            return NULL;
        }

        if(message.mtext[0] == '\0') {
            printf("can't receive max_word\n");
            return NULL;
        }

        if(max_len <= strlen(message.mtext)) {
            free(max_word);
            max_word = (char*)malloc(max_buffer_length * sizeof(char));

            if(max_word == NULL) {
                printf("can't allocate mem to no_procs\n");
                return NULL;
            }

            strcpy(max_word, message.mtext);
            max_len = strlen(message.mtext);
        }
    }

    free(pids);
    free(array);

    for(size_t i = 0; i < words_count; i++) {
        if(words_arr[i] != NULL)
            free(words_arr[i]);
    }
    if(words_arr != NULL)
        free(words_arr);

    return max_word;
}


