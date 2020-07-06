#include <SimpleScheduler.h>
#include <Arduino.h>

void __append(Node** head_ref, unsigned long t, unsigned long m, void (*fn)() )  
{  
    Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    Node *last = *head_ref; 
  
    new_node->millis = m;  
    new_node->time = t;
    new_node->fn = fn;
  
    new_node->next = NULL;  
  
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
  
    while (last->next != NULL)  
        last = last->next;  
  
    last->next = new_node;  
    return;  
}

struct Node *mylist;
struct Node *microslist;

void scheduler_run() {
  schedule_run();
}

void schedule_run() {
    Node *head = mylist;
    while(head != NULL) {
        if(millis() - head->millis >= head->time) {
            head->fn();
             __delete(&mylist, head);
        } 
        head = head->next;
    }
}



void scheduler_run_micros() {
  schedule_run_micros();
}

void schedule_run_micros() {
    Node *head = microslist;
    while(head != NULL) {
        if(micros() - head->millis >= head->time) {
            head->fn();
             __delete(&microslist, head);
        } 
        head = head->next;
    }
}


void schedule(unsigned long dl, func_t fn) {
    __append(&mylist, dl, millis(), fn);
}

void schedule_micros(unsigned long dl, func_t fn) {
    __append(&microslist, dl, micros(), fn);
}

int __delete(struct Node **mainlist, struct Node *item)  {

    struct Node* temp = *mainlist, *prev; 

    if (temp != NULL && temp->fn == item->fn) { 
        *mainlist = temp->next;  
        free(temp);              
        return 1;  
    } 
    while (temp != NULL && temp->fn != item->fn) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) {
        return 1;  
    }
    prev->next = temp->next;
    free(temp);
    return 0;
}
