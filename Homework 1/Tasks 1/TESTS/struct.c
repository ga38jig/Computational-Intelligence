#include <stdio.h>
#include <stdlib.h>

int main(){

    struct node{

        char name[10];

    };

    int i;

    i=1;
    struct node n[i];
    strcpy( n[i].name, "banana");
    printf("%s\n", n[i].name);

    i=2;
    struct node n[i];
    strcpy( n[i].name, "potato");
    printf("%s\n", n[i].name);

}
