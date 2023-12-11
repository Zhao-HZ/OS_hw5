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
    struct node* first_one = head;
    while (first_one->next->task != NULL) {
        first_one = first_one->next;
    }
    while (1) {
        run(first_one->task, slice);
        slice += first_one->task->burst;
        if (first_one->prev == NULL) {
            break;
        } else {
            first_one = first_one->prev;
            delete(&head, first_one->next->task);
            free(first_one->next->task);
        }
    }        
}