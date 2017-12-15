#include <stdlib.h>
#include <stdio.h>

int main(){

    int *ptr;

    ptr = (int *) malloc(10*sizeof(int));

    scanf("%d", &ptr);

    printf("%d", *ptr);


    return 0;
}
