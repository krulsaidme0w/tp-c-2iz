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

char* find_max_word_procs(size_t size, size_t max_buffer_length, const size_t procs_count, const char* path_to_words, long message_t) {

    size_t parts_size = size / procs_count;

    int status;

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

        char* array = NULL;
        char* max_word = NULL;

        array = create_array(parts_size);
        fill_array(array, 0, parts_size - 1, path_to_words, max_buffer_length);

        if(array == NULL) {
            printf("can't fill the array\n");
            exit(EXIT_FAILURE);
        }

        max_word = find_max_word(array, 0,  parts_size - 1, max_buffer_length);

        if(max_word == NULL) {
            printf("can't find max word\n");
            exit(EXIT_FAILURE);
        }

        Message message = {message_t, ""};
        strcpy(message.mtext, max_word);

        if(-1 == msgsnd(qid, (struct msgbuf *)&message, strlen(message.mtext) + 1, 0)) {
            printf("can't send msg\n");
            exit(EXIT_FAILURE);
        }

        free(array);
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

    char* max_word = "";
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

        if(max_len < strlen(message.mtext)) {
            max_word = message.mtext;
            max_len = strlen(message.mtext);
        }
    }

    return max_word;
}


