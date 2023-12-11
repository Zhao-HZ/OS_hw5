#include <stdio.h>
#include <stdlib.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

void add(struct node** head, char *name, int priority, int burst) {
    Task* new_task = (Task *) malloc(sizeof(Task));    
    // strcpy(new_task->name, name); 
    new_task->name = name;
    new_task->priority = priority;
    new_task->burst = burst;
    insert(head, new_task);
}

void schedule(struct node* head) {
    int slice = 0;
    int max_priority_time = head->task->priority;
    int cur_priority_time;
    // Node with maximal relative priority time.
    struct node* max_node;
    struct node* temp = head;
    while (head->task != NULL) {
        max_priority_time = -1;
        temp = head;
        while (temp->task != NULL) {
            cur_priority_time = temp->task->priority;
            if (max_priority_time < cur_priority_time) {
                max_priority_time = cur_priority_time;
                max_node = temp;
            }
            temp = temp->next;
        }
        run(max_node->task, slice);
        slice += max_node->task->burst;
        delete(&head, max_node->task);
        free(max_node->task);
    }
}