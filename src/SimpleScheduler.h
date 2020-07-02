#include <stdlib.h>

void __delete(struct Node **, struct Node *);
void schedule_run();
void schedule(unsigned long , func_t);

typedef void(*func_t)();

struct Node {
    unsigned long time;
    unsigned long millis;
    func_t fn;
    struct Node *next;
};

struct Node *mylist;

void schedule_run() {
    struct Node *n = mylist;
    while(n) {
        if(millis() - n->millis >= n->time) {
            n->fn();
            __delete(&mylist, n);
        }
        n = n->next;
    }
}

void schedule(unsigned long dl, func_t fn) {
    struct Node *node;
    node = (struct Node*) malloc(sizeof(struct Node));
    node->millis = millis();
    node->time = dl;
    node->fn = fn;
    node->next = mylist;
    mylist = node;
}

void __delete(struct Node **mainlist, struct Node *item)  {

    struct Node* temp = *mainlist, *prev; 

    if (temp != NULL && temp->millis == item->millis) { 
        *mainlist = temp->next;  
        free(temp);              
        return; 
    } 
    while (temp != NULL && temp->millis != item->millis) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) {
        return;  
    }
    prev->next = temp->next;
    free(temp);
}
