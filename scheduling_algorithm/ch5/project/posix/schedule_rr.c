#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <setjmp.h>
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

#define TIME_QUANTUM 10
void schedule(struct node* head) {
    int slice = 0;
    struct node* end = head;
    while (end->task != NULL) {
        end = end->next;
    }
    // Get the "end" node of the link list.
    // which is indeed an empty node.
    // i.e. end->task == NULL
    struct node* temp;
    // struct node* mark;
    // jmp_buf buf;
    while (end->prev != NULL && end->prev->task != NULL && end->prev->task->name != NULL) {
        temp = end->prev;
        if (temp->task->name == NULL) {
            break;
        }
        while (temp != NULL) {
            if (temp->task->burst > TIME_QUANTUM) {
                run(temp->task, slice);
                slice += TIME_QUANTUM;
                temp->task->burst -= TIME_QUANTUM;
                temp = temp->prev;
            } else {
                run(temp->task, slice);
                slice += temp->task->burst;
                delete(&head, temp->task);
                temp->task->name = NULL;
                temp = temp->prev;
            }
        }
    }
}