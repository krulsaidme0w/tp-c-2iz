#ifndef NO_THREAD_H
#define NO_THREAD_H

#include <stdbool.h>

char* create_array(size_t size);
FILE* open_file(char* path, char* path_to_words);
bool close_file(char* path);
size_t fill_array(char *array, size_t size, const char* path_to_words, size_t max_buffer_length);
char* find_max_word(const char* array, size_t length, size_t max_buffer_length);
bool print_array(char* array);

#endif