#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

void add(struct node** head, char *name, int priority, int burst) {
    Task* new_task = (Task *) malloc(sizeof(Task));    
    // new_task->name = (char *) malloc(100 * sizeof(char));
    // strcpy(new_task->name, name); 
    new_task->name = name;
    new_task->priority = priority;
    new_task->burst = burst;
    insert(head, new_task);
}

int get_max_priority(struct node* head) {
    int cur_priority_time = 0;
    int max_priority_time = -1;
    // struct node* max_node;
    struct node* temp = head;

    while (temp->task != NULL) {
        cur_priority_time = temp->task->priority;
        if (max_priority_time < cur_priority_time) {
            max_priority_time = cur_priority_time;
        }
        temp = temp->next;
    }
    return max_priority_time;    
} 

#define TIME_QUANTUM 10
void schedule(struct node* head) {
    int slice = 0;
    int max_priority_time;
    struct node* max_node;
    struct node* end = head;
    // struct node* end_same_priority;
    struct node* temp1;
    struct node* temp2;

    // struct node head_same_priority = {NULL, NULL, NULL};
    
    while (end->task != NULL && end->task->name != NULL) {
        end = end->next;
    }

    // temp2 = end->prev;

    while (end->prev != NULL && end->prev->task != NULL && end->prev->task->name != NULL) {
        max_priority_time = get_max_priority(head);
        temp2 = end->prev;
        while (temp2 != NULL && temp2->task != NULL) {
            if (max_priority_time == temp2->task->priority) {
                if (temp2->task->burst > TIME_QUANTUM) {
                    run(temp2->task, slice);
                    slice += TIME_QUANTUM;
                    temp2->task->burst -= TIME_QUANTUM;
                    temp2 = temp2->prev;
                } else {
                    run(temp2->task, slice);
                    slice += temp2->task->burst;
                    delete(&head, temp2->task);
                    temp2->task->name = NULL;
                    temp2 = temp2->prev;
                }
            } else {
                temp2 = temp2->prev;
            }
        }
    }
} 