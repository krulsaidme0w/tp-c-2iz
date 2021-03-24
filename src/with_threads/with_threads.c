#include <pthread.h>
#include <stdio.h>

void *thread_init(void *value) {
    printf("asd");
    return NULL;
};

pthread_t create_thread() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_init, NULL);
    return thread;
};


char* find_max_len_el(void * v) {
    return NULL;
};

