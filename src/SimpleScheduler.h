#include <stdlib.h>

typedef void(*func_t)();
struct Node {
    unsigned long time;
    unsigned long millis;
    func_t fn;
    struct Node *next;
};

void __append(struct Node**, unsigned long , unsigned long , void(*)() );
int __delete(struct Node **, struct Node *);
void schedule_run();
void schedule(unsigned long , func_t);

