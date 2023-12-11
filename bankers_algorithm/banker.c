#include "banker.h"
#include <stdio.h>

int available[NUMBER_OF_RESOURCES];

int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

// returns 0 if successful.
// returns -1 if unsuccessful.
int request_resources(int customer_num, int request[]) {
    
}

void release_resources(int customer_num, int release[]) {

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