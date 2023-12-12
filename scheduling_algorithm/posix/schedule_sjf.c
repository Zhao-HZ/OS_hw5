#include <stdio.h>
#include <stdlib.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

int slice = 0;

void add(struct node** head, char *name, int priority, int burst) {
    Task* new_task = (Task *) malloc(sizeof(Task));    
    // strcpy(new_task->name, name); 
    new_task->name = name;
    new_task->priority = priority;
    new_task->burst = burst;
    insert(head, new_task);
}

void schedule(struct node* head) {
    int min_burst_time = head->task->burst;
    int cur_burst_time;
    // Node with minimal burst time.
    struct node* min_node;
    struct node* temp = head;
    while (head->task != NULL) {
        min_burst_time = 0xffffff;
        temp = head;
        // if (head->task == NULL) {
        //     break;
        // }
        while (temp->task != NULL) {
            cur_burst_time = temp->task->burst;
            if (min_burst_time > cur_burst_time) {
                min_burst_time = cur_burst_time;
                min_node = temp;
            }
            temp = temp->next;
        }
        run(min_node->task, slice);
        slice += min_burst_time;
        // free(min_node->task->name);
        delete(&head, min_node->task);
        free(min_node->task);
    }
}