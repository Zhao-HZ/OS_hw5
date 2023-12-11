#ifndef FIFO_H_
#define FIFO_H_


// Initialize the page frames
void initialize();

// Simulate the replacement algorithm
// after the initialization.
void run();

// Count the number of fault.
// Invoke it after invoking run().
void num_fault();

void print_array();

void delete_array();

#endif