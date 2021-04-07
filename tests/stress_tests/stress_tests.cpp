#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

extern "C" {
#include "menu.h"
#include "no_procs.h"
#include "with_procs.h"
}

#define SIZE 1048576 * 2
#define MAX_BUFFER_LENGTH 400
#define FILE_PATH "words.txt"
#define PROCS_COUNT 4
#define COUNT 1000

int main() {

    double time_with_procs = 0;
    double time_no_procs = 0;

    for(size_t i = 0; i < COUNT; i++) {


        clock_t begin1 = clock();
        char* max_w1 = find_max_word_no_procs(SIZE, MAX_BUFFER_LENGTH, 0, FILE_PATH);
        clock_t end1 = clock();

        time_no_procs += (double)(end1 - begin1) / CLOCKS_PER_SEC;

        clock_t begin2 = clock();
        char* max_w2 = find_max_word_procs(SIZE, MAX_BUFFER_LENGTH, PROCS_COUNT, FILE_PATH);
        clock_t end2 = clock();

        time_with_procs += (double)(end2 - begin2) / CLOCKS_PER_SEC;

        free(max_w1);
        free(max_w2);

    }

    double sr_time_with_procs = time_with_procs / COUNT;
    double sr_time_no_procs = time_no_procs / COUNT;

    cout << "average with procs " << sr_time_with_procs << endl;
    cout << "average no procs " << sr_time_no_procs << endl;

}

