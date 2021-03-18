#include <stdio.h>
#include "no_threads.h"
#include "with_threads.h"

const size_t SIZE = 1000000000;

int main() {
    char* m1 = create_array(SIZE);
    char* m2 = thread_create_array(SIZE);
    return 0;

}
