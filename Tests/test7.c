#include <stdio.h>

int main(){

    struct Node {
        int data;
        struct Node* link;
    };

    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=3;
    temp->link=NULL;

    printf("%d", temp->data);

}
