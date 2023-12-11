#include "banker.h"
#include <stdio.h>

int available[NUMBER_OF_RESOURCES];

int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

int fake_available[NUMBER_OF_RESOURCES];

int fake_allocation[NUMBER_OF_RESOURCES];

int fake_need[NUMBER_OF_RESOURCES];

// returns 0 if successful.
// returns -1 if unsuccessful.
// request: request vector(len = NUMBER_OF_RESOURCES).
// customer_num: index of the customer.
int request_resources(int customer_num, int request[]) {
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        fake_available[i] = available[i];
        fake_allocation[i] = allocation[customer_num][i];
        fake_need[i] = need[customer_num][i];
    }


    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        if (request[i] > need[customer_num][i]) {
            flag = 0;
            printf("Error!\n");
            return -1;
        }
    }
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        printf("Please wait!\n");
        printf("Thank you for your patience!\n");
        if (request[i] > available[i])
            return -1;
    } 
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        fake_available[i] -= request[i];
        fake_allocation[i] += request[i];
        fake_need[i] -= request[i];
    }   
    int result = is_safe(customer_num);
    return result;
}

void release_resources(int customer_num, int release[]) {

}

int is_safe(int customer_num) {
    int work[NUMBER_OF_RESOURCES];
    int finish[NUMBER_OF_CUSTOMERS];
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        work[i] = fake_available[i];
    }
    int i;
    while (1) {
        i = find_i(work, finish);
        if (i == -1) break;
        else {
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
                work[j] += fake_allocation[i][j];
            }
            finish[i] = 1;
        }
    } 
    // Final check.
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        if (finish[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int find_i(int *work, int* finish) {
    int i = 0;
    int find = 1;
    for (i; i < NUMBER_OF_CUSTOMERS; i++) {
        if (finish[i] == 0) {
            find = 1;
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
                // At least one does not
                // fulfill the condition Need_i <= Work
                if (fake_need[i][j] > work[j]) {  
                    find = 0;
                    break;
                } 
            } 
            if (find == 1) {
                return i;
            }
        } else {
            find = 0;
        }
    }
    return -1;
}

void debug() {
    // for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    //     for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
    //         printf("%d ", maximum[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("\n");
}


void output() {
    printf("available\n");
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
        printf("%d ", available[i]);
    printf("\n");

    printf("maximum\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
            printf("%d ", maximum[i][j]);
        printf("\n");
    }

    printf("allocation\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("need\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
}