#include <stdio.h>
#include "banker.h"
#include <string.h>
#include <stdlib.h>

#define RQ "RQ"
#define RL "RL"
#define CHECK '*'
#define MAX_CHAR_COM 100

extern int available[NUMBER_OF_RESOURCES];
extern int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
extern int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
extern int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

FILE* in;

void debug_array(int *array, int n);
void update_need();

int main(int argc, char **argv) {
    for (int i = 1; i < NUMBER_OF_RESOURCES + 1; i++) {
        available[i - 1] = atoi(argv[i]);
    }
    in = fopen("max_requests.txt", "r");
    if (in == NULL) {
        perror("Error opening file.");
        return 1;
    }
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        fscanf(in, "%d,%d,%d,%d", &maximum[i][0], &maximum[i][1], &maximum[i][2], &maximum[i][3]);
    }
    fclose(in);
    
    // for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    //     for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
    //         need[i][j] = maximum[i][j] - allocation[i][j];
    //     }
    // }

    update_need();

    while (1) {
        char buf[MAX_CHAR_COM];
        char c;
        int k = 0;
        while ((c = getchar()) != (int)'\n')
            buf[k++] = c;
        int customer_index;
        // Request resources
        if (buf[0] == 'R' && buf[1] == 'Q') {
            char *pointer = (buf + 3);
            int request[NUMBER_OF_RESOURCES];
            sscanf(pointer, "%d", &customer_index);
            pointer += 2;
            for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
                sscanf(pointer, "%d", &request[i]);
                pointer += 2;
            }

            // printf("Require\n");
            // debug_array(require, 4);

            int result = request_resources(customer_index, request);

            if (result == 1) {
                printf("Safe\n");
                // Now (real) Available, Allocation and Need should be changed!
                for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
                    available[i] -= request[i];
                    allocation[customer_index][i] += request[i];
                    need[customer_index][i] -= request[i];
                }   
            } else if (result == 0){
                printf("Unsafe\n");
            } else {
                printf("Something wrong happen. Please check!\n");
            }

            update_need();

        // Release resources
        } else if (buf[0] == 'R' && buf[1] == 'L') {
            char *pointer = (buf + 3);
            int release[NUMBER_OF_RESOURCES];
            sscanf(pointer, "%d", &customer_index);
            pointer += 2;
            for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
                sscanf(pointer, "%d", &release[i]);
                pointer += 2;
            }
            release_resources(customer_index, release);
            // printf("Release\n");
            // debug_array(release, 4);
            update_need();
        // Output the value
        } else if (buf[0] == '*') {
            output();
        } else if (buf[0] == 'q' || buf[0] == 'Q') {
            return 0;
        } else {
            printf("Please enter the appropriate command\n");
        }
    }
    return 0;
}

// It is necessary to update need again after 
// requesting and releasing.
void update_need() {
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

void debug_array(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}