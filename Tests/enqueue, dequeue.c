#include <stdio.h>
#include <stdlib.h>

typedef struct Node{    // A Node is an element with data, a pointer to the next node and a pointer to the node before

    int data;
    struct Node* front;
    struct Node* back;

}Node;

typedef struct Queue{   // A Queue is a structure with two pointers: head and tail.

    struct Node* head;
    struct Node* tail;

}Queue;

int main(){

    Node* ptr;
    ptr = (Node*)malloc(sizeof(Node));

    // Initialize Queue
    Queue* Q;
    Q=(Queue*)malloc(sizeof(Queue));
    init_queue(Q);

    // Define element to enqueue
    Node* n1;
    n1 = (Node*)malloc(sizeof(Node));
    n1->data=1;

    Node* n2;
    n2 = (Node*)malloc(sizeof(Node));
    n2->data=2;

    Node* n3;
    n3 = (Node*)malloc(sizeof(Node));
    n3->data=3;

    // Enqueue element
    enqueue(Q, n1);
    enqueue(Q, n2);
    enqueue(Q, n3);

    // Print Elements
    ptr=Q->tail;
    do{
        printf("%d ", ptr->data);
        ptr=ptr->front;
    }while(ptr!=NULL);
    printf("\n");

    // Dequeue Elements
    dequeue(Q);
    dequeue(Q);

        // Print Elements
    ptr=Q->tail;
    do{
        printf("%d ", ptr->data);
        ptr=ptr->front;
    }while(ptr!=NULL);
    printf("\n");

    return 0;
}

void init_queue(Queue* Q){

    Q->head=Q->tail=NULL;

}

void enqueue(Queue* Q, Node* N){

    // if Queue is empty head and tail point to N
    if(Q->head==NULL && Q->tail==NULL){
        Q->head=Q->tail=N;
        N->front=N->back=NULL;
    }
    // else N gets attached to tail and tail gets updated
    else{
        N->front=Q->tail;
        (Q->tail)->back=N;
        Q->tail=N;
        N->back=NULL;
    }

}

void dequeue(Queue* Q){

    if(Q->head->back==NULL){
        Q->head=Q->tail=NULL;
    }
    else {
        Q->head=Q->head->back;
        Q->head->front=NULL;
    }

}
