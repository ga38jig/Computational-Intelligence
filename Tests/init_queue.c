#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{   // A Queue is a structure with two pointers: head and tail.

    struct Queue* head;
    struct Queue* tail;

}Queue;

int main(){

    Queue* A;
    A=(Queue*)malloc(sizeof(Queue));
    init_queue(A);
    printf("%u %u", A->head, A->tail);



}

void init_queue(Queue* Q){

    Q->head=Q->tail=NULL;

}

