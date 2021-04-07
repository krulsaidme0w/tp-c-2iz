#ifndef MENU_H
#define MENU_H

#include <stdio.h>

void menu();
char get_char();
char* get_string();
size_t menu_max_len(size_t size, size_t max_buffer_length, size_t procs_count, const char* path_to_file);

#endif
