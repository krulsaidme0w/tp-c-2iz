#ifndef NO_THREAD_H
#define NO_THREAD_H

#include <stdbool.h>

char* create_array(size_t size);
FILE* open_file(const char* path);
bool close_file(FILE *f);
size_t fill_array(char *array, size_t begin, size_t end, const char* path_to_words, size_t max_buffer_length);
bool print_array(char* array);
char** create_matrix(const char* array, const char* path_to_words, size_t max_buffer_length, size_t words_count);
char* find_max_word(char** array, size_t words_count);
char* find_max_word_no_threads(size_t size, size_t max_buffer_length, const size_t procs_count, const char* path_to_words);

#endif
