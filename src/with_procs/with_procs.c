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
    char* mtext;
} Message;

char* find_max_word_procs(size_t size, size_t max_buffer_length, const size_t procs_count, const char* path_to_words, long message_t) {

    size_t parts_size = size / procs_count;

    char* array = NULL;
    char* max_word = NULL;

    key_t key = IPC_PRIVATE;
    int qid = msgget(key, (IPC_CREAT | 0660));
    pid_t* pids = (pid_t *) malloc(sizeof(pid_t *) * procs_count);

    int status;

    for(size_t i = 0; i < procs_count; ++i) {
        pids[i] = fork();

        if (pids[i] != 0) {
            continue;
        }

        array = create_array(parts_size);
        fill_array(array, 0, parts_size - 1, path_to_words, max_buffer_length);

        max_word = find_max_word(array, 0,  parts_size - 1, max_buffer_length);

        if(max_word == NULL) {
            printf("can't find max word\n");
            exit(EXIT_FAILURE);
        }

        Message msg = {message_t, max_word};
        if(-1 == msgsnd(qid, &msg, sizeof(msg.mtext), 0)) {
            printf("can't send msg\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }

    for (size_t i = 0; i < procs_count; ++i) {
        waitpid(pids[i], &status, 0);
    }

    max_word = "";

    for (size_t i = 0; i < procs_count; ++i) {
        Message message = {message_t, 0};

        if(-1 == msgrcv(qid, &message, sizeof(message.mtext), message_t, 0)) {
            printf("can't receive msg\n");
            free(pids);
            return NULL;
        }

        if(strlen(max_word) < strlen(message.mtext) && message.mtext != NULL) {
            max_word = message.mtext;
        }
    }

    free(pids);
    return max_word;
}


