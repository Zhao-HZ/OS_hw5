#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "replacement_alg.h"

#define MALLOC(TYPE, SIZE) (TYPE *) malloc(sizeof(TYPE) * (SIZE + 1))

// Generate a random array, the elements which are picked from the interval [[0, 9]]. 
int* random_array(int size, int min, int max);

// Print an array of specific range ([[from, to]]). 
// Use for debug.
void print_array(int *arr, int from, int to);

int page_address_stream[13] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; 
// int *page_address_stream;

int main(int argc, char **argv) {
    // The random array does not look so random.
    // page_address_stream = random_array();
    printf("Enter the number of page frames: ");
    int num_page_frames;
    scanf("%d", &num_page_frames);    
    initialize(num_page_frames, 12);    
    printf("FIFO\n");
    run_fifo(page_address_stream);
    clear_array();
    printf("OPT\n");
    run_opt(page_address_stream);
    clear_array();
    // printf("LRU\n");
    // run_lru(page_address_stream);
    // clear_array();
    delete_array();
    return 0;
}

int* random_array(int size, int min, int max) { 
    int* arr = MALLOC(int, size + 1);
    int random_number;
    for (int i = 0; i < size; i++) {
        srand((unsigned)time(NULL));
        random_number = random() % 10;
        arr[i] = random_number;
    }
    return arr;
}