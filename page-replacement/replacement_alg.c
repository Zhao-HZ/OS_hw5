#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "replacement_alg.h"

#define MALLOC(TYPE, SIZE) (TYPE *) malloc(sizeof(TYPE) * (SIZE + 1))

// This array simulates the actual page frames.
int *page_frames;
int num_page_frames;
int num_faults;
int times;

// Make sure before running the algorithm
// run the following function.
void initialize(int num, int get_times) {
    num_page_frames = num;
    page_frames = MALLOC(int, num_page_frames);
    times = get_times;
}

int binary_search(int target) {
    int left = 0;
    int right = times;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (page_frames[mid] == target) {
            return mid;
        } 
        if (page_frames[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

// Less efficient than binary search.
// However in some small cases, linear search is enough.
int linear_search(int target) {
    int index;
    for (int i = 0; i < num_page_frames; i++) {
        if (page_frames[i] == target) {
            return i;
        }
    }
    return -1;
}

void run_fifo(int *page_address_stream) {
    num_faults= 0;
    int ptr = 0;
    bool find = false;
    bool full = false;
    int index = 0;
    for (int i = 0; i < times; i++) {
        if (ptr == num_page_frames) {
            full = true;
            ptr = 0;
        } 
        // int index = binary_search(page_address_stream[i]);
        int index = linear_search(page_address_stream[i]);
        
        if (index == -1) {
            if (full) {
                num_faults++;
            }
            page_frames[ptr++] = page_address_stream[i];
        } 
        print_array();
        if (index == -1 && full) {
            printf(" F");
        }
        printf("\n");
    }
}

void run_opt(int* page_address_stream) {
    bool full = false;
    int ptr = 0;
    num_faults = 0;
    int candidate_index;
    int index = 0;
    for (int i = 0; i < times; i++) {
        index = linear_search(page_address_stream[i]);
        if (ptr == num_page_frames) {
            full = true;
            if (index == -1) {
                int candidate_index = choose_one_for_opt(i, page_address_stream);
                page_frames[candidate_index] = page_address_stream[i];
            } 
        } else {
            index = linear_search(page_address_stream[i]);
            if (index == -1) {
                page_frames[ptr++] = page_address_stream[i];         
            }
        }
        print_array();
        if (index == -1 && full) {
            printf(" F");
        }
        printf("\n");
    }
}

int choose_one_for_opt(int current_times, int *page_address_stream) {
    int time_for_next_ref; 
    int max_time_for_next_ref = 0; 
    int index_candidate = 0;
    int index_candidate_max_time = 0;
    for (int i = 0; i < num_page_frames; i++) {
        time_for_next_ref = 0;
        index_candidate = i;
        for (int j = current_times + 1; j <= times; j++) {
            if (j == times) {
                return index_candidate;
            }
            time_for_next_ref++;
            if (page_address_stream[j] == page_frames[i]) {
                time_for_next_ref++;
                if (max_time_for_next_ref < time_for_next_ref) {
                    max_time_for_next_ref = time_for_next_ref;
                    index_candidate_max_time = index_candidate;
                }
                break;
            }
        } 
    }
    return index_candidate_max_time;
}

void run_lru(int* page_address_stream) {
    // We define a mapping, record: i -> record[i]
    // where i is the index of the entry of page frames.
    // it records the time when the page is recently referenced. 
    int *record = MALLOC(int, num_page_frames);
    num_faults = 0;
    int ptr = 0;
    int index;
    bool full = false;
    int max = 0;
    int max_index = 0;
    int cur = 0;
    for (int i = 0; i < num_page_frames; i++) record[i] = 0;
    for (int i = 0; i < times; i++) {
        max = 0;
        index = linear_search(page_address_stream[i]);
        if (ptr == num_page_frames) {
            full = true;
            if (index == -1) {
                for (int j = 0; j < num_page_frames; j++) {
                    cur = i - record[j];
                    if (max < cur) {
                        max = cur;
                        max_index = j;
                    }
                }
                page_frames[max_index] = page_address_stream[i];
                record[max_index] = i;
            } else {
                record[index] = i;
            }
        } else {
            if (index == -1) {
                page_frames[ptr] = page_address_stream[i];
                record[ptr] = i;
                ptr++;
            } else {
                record[index] = i;
            }
        }
        print_array();
        if (index == -1 && full) {
            printf("F");
        }
        printf("\n");
    }
    free(record);
}

void print_array() {
    for (int i = 0; i < num_page_frames; i++) {
        printf("%d ", page_frames[i]);
    }
}

int get_num_faults() {
    return times;
}

// Clear the array.
void clear_array() {
    for (int i = 0; i <times; i++) {
        page_frames[i] = 0;
    }
} 

void delete_array() {
    free(page_frames);
}
