#ifndef BANKER_H_
#define BANKER_H_

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4


// 0 if unsafe.
// 1 if safe
// -1 if error
// Determine if the request should be granted.
int request_resources(int customer_num, int request[]);

void release_resources(int customer_num, int release[]);

// Determine whether the state is safe.
// 0 if unsafe.
// 1 if safe.
int is_safe(int customer_num);

// Auxiliary function for is_safe().
// return the index i of the customer that satisfying the condition
// return -1 if cannot find such customer.
int find_i(int *work, int *finish);

// Outputs the available, maximum, allocation and need.
void output();

// Use for debug
void debug();

#endif