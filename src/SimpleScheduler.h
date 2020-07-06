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

void schedule(unsigned long , func_t);
void schedule_run();
void scheduler_run();

void schedule_micros(unsigned long , func_t);
void schedule_run_micros();
void scheduler_run_micros();
