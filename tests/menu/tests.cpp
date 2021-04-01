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
const size_t COUNT_PROCS = 2;

//consts
const size_t SIZE1 = 1024;
const size_t SIZE2 = 4096;
const size_t SIZE3 = 8192;
const size_t SIZE4 = 131072;
const size_t SIZE5 = 1024 * 2;
const size_t SIZE6 = 1024 * 1024;

//tests for no_procs
TEST(FIND, MAX_WORD_NO_PROCS) {
    size_t max_len = menu_max_len(SIZE, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    ASSERT_EQ(max_len != 0, 1);
}

//tests for procs
TEST(FIND, MAX_WORD_WITH_PROCS) {
    size_t max_len = menu_max_len(SIZE, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);
    ASSERT_EQ(max_len != 0, 1);
}

TEST(COMPARE, WITH_PROCS_NO_PROCS_SIZE1) {
    size_t max_len1 = menu_max_len(SIZE1, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    size_t max_len2 = menu_max_len(SIZE1, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);

    ASSERT_EQ(max_len1, max_len2);
}

TEST(COMPARE, WITH_PROCS_NO_PROCS_SIZE2) {
    size_t max_len1 = menu_max_len(SIZE2, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    size_t max_len2 = menu_max_len(SIZE2, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);

    ASSERT_EQ(max_len1, max_len2);
}

TEST(COMPARE, WITH_PROCS_NO_PROCS_SIZE3) {
    size_t max_len1 = menu_max_len(SIZE3, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    size_t max_len2 = menu_max_len(SIZE3, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);

    ASSERT_EQ(max_len1, max_len2);
}

TEST(COMPARE, WITH_PROCS_NO_PROCS_SIZE4) {
    size_t max_len1 = menu_max_len(SIZE4, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    size_t max_len2 = menu_max_len(SIZE4, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);

    ASSERT_EQ(max_len1, max_len2);
}

TEST(COMPARE, WITH_PROCS_NO_PROCS_SIZE5) {
    size_t max_len1 = menu_max_len(SIZE5, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    size_t max_len2 = menu_max_len(SIZE5, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);

    ASSERT_EQ(max_len1, max_len2);
}

TEST(COMPARE, WITH_PROCS_NO_PROCS_SIZE6) {
    size_t max_len1 = menu_max_len(SIZE6, MAX_BUFFER_LENGTH, 0, FILE_PATH);
    size_t max_len2 = menu_max_len(SIZE6, MAX_BUFFER_LENGTH, COUNT_PROCS, FILE_PATH);

    ASSERT_EQ(max_len1, max_len2);
}