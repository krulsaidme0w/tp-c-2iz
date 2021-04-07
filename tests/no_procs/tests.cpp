#include <gtest/gtest.h>
#include <cstring>

extern "C" {
    #include "menu.h"
    #include "no_procs.h"
    #include "with_procs.h"

}

//consts
#define SIZE 1024
#define MAX_BUFFER_LENGTH 400
#define FILE_PATH "words.txt"

//consts for with_procs
#define PROCS_COUNT 2


//files tests
TEST(FILE, OPEN_CLOSE_FILE) {
    FILE* f = open_file(FILE_PATH);
    EXPECT_TRUE(f);
    bool cls_f = close_file(f);
    EXPECT_TRUE(cls_f);
}

//array tests
TEST(ARRAY, FILL_ARRAY) {
    char* array = create_array(SIZE);
    ASSERT_EQ(strlen(array), 0);

    size_t words_count = fill_array(array, 0, SIZE - 1, FILE_PATH, MAX_BUFFER_LENGTH);
    EXPECT_TRUE(words_count);
    EXPECT_TRUE(strlen(array));

    free(array);
}
//
TEST(ARRAY, MATRIX) {
    char* array = create_array(SIZE);

    size_t words_count = fill_array(array, 0, SIZE - 1, FILE_PATH, MAX_BUFFER_LENGTH);

    char** words = create_matrix(array, FILE_PATH, MAX_BUFFER_LENGTH, words_count);

    for(size_t i = 0; i < words_count; i++) {
        ASSERT_EQ(words[i] != nullptr, 1);
    }
    ASSERT_EQ(words != nullptr, 1);

    for(size_t i = 0; i < words_count; i++) {
        free(words[i]);
    }
    free(words);

    free(array);
}

TEST(ARRAY, FIND_MAX) {
    char* array = create_array(SIZE);

    size_t words_count = fill_array(array, 0, SIZE - 1, FILE_PATH, MAX_BUFFER_LENGTH);

    char** words = create_matrix(array, FILE_PATH, MAX_BUFFER_LENGTH, words_count);

    char* max_word = find_max_word(words, words_count, MAX_BUFFER_LENGTH);

    ASSERT_EQ(max_word != nullptr, 1);

    for(size_t i = 0; i < words_count; i++) {
    free(words[i]);
    }
    free(words);

    free(max_word);
    free(array);
}
