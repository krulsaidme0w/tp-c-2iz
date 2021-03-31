#include <gtest/gtest.h>

extern "C" {
    #include "menu.h"
    #include "no_procs.h"
    #include "with_procs.h"

    #include <cstring>
}

//consts
const size_t SIZE = 800;
const size_t MAX_BUFFER_LENGTH = 400;
const char* FILE_PATH = "words.txt";

//consts for with_procs
const size_t PROCS_COUNT = 2;


//tests for no procs
TEST(FIND, MAX_WORD_NO_THREADS) {
    size_t max_len = menu_max_len(SIZE, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    ASSERT_EQ(max_len != 0, 1);
}

//tests for procs
TEST(FIND, MAX_WORD_WITH_THREADS) {
    size_t max_len = menu_max_len(SIZE, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    ASSERT_EQ(max_len != 0, 1);
}

