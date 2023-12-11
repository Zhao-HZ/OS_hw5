#ifndef REPLACEMENT_ALG_H_
#define REPLACEMENT_ALG_H_


// Initialize the page frames
void initialize(int num, int times);

// The aim of the following replacement algorithm
// is to simulate the replacement algorithm
// after the initialization.

// Run the FIFO algorithm.
void run_fifo(int* page_address_stream);

// Run the OPT algorithm.
void run_opt(int* page_address_stream);

// Auxiliary function for OPT.
// Return the index that is needed to be replaced.
int choose_one_for_opt(int current_times, int *page_address_stream);

// Run the LRU algorithm.
void run_lru(int* page_address_stream);

// Count the number of fault.
// Invoke it after invoking run().
int get_num_faults();

void print_array();

void clear_array();

void delete_array();

int binary_search(int target);

int linear_search(int target);
#endif
