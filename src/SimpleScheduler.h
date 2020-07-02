#include <stdlib.h>

typedef void(*func_t)();

struct Node {
    unsigned long time;
    unsigned long millis;
    func_t fn;
    struct Node *next;
    struct Node *prev;
};

struct Node *mylist;


void scheduler_run() {
    struct Node *n = mylist;
    while(n) {
        if(millis() - n->millis >= n->time) {
            n->fn();
           mylist->next = n->next;
           free(n);
        }
        n = mylist->next;
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

