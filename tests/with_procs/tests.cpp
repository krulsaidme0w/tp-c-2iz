#include <gtest/gtest.h>

extern "C" {
    #include "menu.h"
    #include "no_procs.h"
    #include "with_procs.h"

    #include <cstring>
}

//consts
#define SIZE 1024
#define MAX_BUFFER_LENGTH 400
#define FILE_PATH "words.txt"

//consts for with_procs
#define PROCS_COUNT1 2

TEST(FIND, MAX_WORD_WITH_PROCS) {
    char* max_word = find_max_word_procs(SIZE, MAX_BUFFER_LENGTH, PROCS_COUNT1, FILE_PATH);
    ASSERT_EQ(max_word != nullptr, 1);
    free(max_word);
}


