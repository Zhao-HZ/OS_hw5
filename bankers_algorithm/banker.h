#ifndef BANKER_H_
#define BANKER_H_

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4


// 0 if successful.
// -1 if unsuccessful.
int request_resources(int customer_num, int request[]);

void release_resources(int customer_num, int release[]);


// Outputs the available, maximum, allocation and need.
void output();

void debug();

#endif