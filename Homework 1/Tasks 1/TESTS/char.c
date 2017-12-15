#include <stdio.h>

int main(){

    char N[3][2];
    int i=1;
    int a;

    N[0][0]='a';
    N[0][1]=i;
    a=N[0][1];

    printf("%c\n", N[0][0]);
    printf("%d\n", a);

}
