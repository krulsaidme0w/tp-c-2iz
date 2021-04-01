#include <gtest/gtest.h>

extern "C" {
    #include "menu.h"
    #include "no_procs.h"
    #include "with_procs.h"

    #include <cstring>
}

//consts
const size_t SIZE = 1024;
const size_t MAX_BUFFER_LENGTH = 400;
const char* FILE_PATH = "words.txt";

//consts for with_procs
const size_t PROCS_COUNT1 = 2;
const size_t PROCS_COUNT2 = 4;

TEST(FIND, MAX_WORD_WITH_PROCS) {
    char* max_word = find_max_word_procs(SIZE, MAX_BUFFER_LENGTH, PROCS_COUNT1, FILE_PATH);
    ASSERT_EQ(max_word != NULL, 1);
    free(max_word);
}

//TEST(COMPARE, MAX_WORDS_WITH_PROCS_2_4) {
//    char* max_word1 = find_max_word_procs(SIZE, MAX_BUFFER_LENGTH, PROCS_COUNT1, FILE_PATH);
//    char* max_word2 = find_max_word_procs(SIZE, MAX_BUFFER_LENGTH, PROCS_COUNT2, FILE_PATH);
//    ASSERT_EQ(!strcmp(max_word1, max_word2), 1);
//    free(max_word1);
//    free(max_word2);
//}

