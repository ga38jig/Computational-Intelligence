#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* link;

}Node;

typedef struct Q{   // A Queue is a structure with two pointers: head and tail.

    struct Q* head;
    struct Q* tail;

}Q;

int main(){

    Q* queue;
    queue=(Q*)malloc(sizeof(Q));
    queue->head=queue->tail=NULL;
    printf("%u %u", queue->head, queue->tail);

}


