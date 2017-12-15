#include <stdio.h>
#include <stdlib.h>

int main(){
    int size=5;
    int i,j,k;
    char A[10];
    char *ptr;
    char R[size];
    char L[size];

    ptr=A;

    scanf("%s", &A);
    printf("You entered: %s\n", A);

    // populate the arrays
    for(i=0;i<size;i++){
        L[i] = *ptr;
        ptr++;
    }
    for(i=0;i<size;i++){
        R[i] = *ptr;
        ptr++;
    }

    printf("done\n");

    printf("Left string is: %s\n", L);

    printf("Right string is: %s\n", R);

    for(k=0;k<size;k++){
        printf("%c", R[k]);
    }
    printf("\n");

    return 0;
}
