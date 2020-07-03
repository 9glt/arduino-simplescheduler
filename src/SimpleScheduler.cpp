#include <SimpleScheduler.h>
#include <Arduino.h>

void __append(Node** head_ref, unsigned long t, unsigned long m, void (*fn)() )  
{  
    /* 1. allocate node */
    Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    Node *last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data */
    new_node->millis = m;  
    new_node->time = t;
    new_node->fn = fn;
  
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
    new_node->next = NULL;  
  
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)  
        last = last->next;  
  
    /* 6. Change the next of last node */
    last->next = new_node;  
    return;  
}

struct Node *mylist;

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

void schedule(unsigned long dl, func_t fn) {
    __append(&mylist, dl, millis(), fn);
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
