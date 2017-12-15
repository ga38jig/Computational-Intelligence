#include <stdio.h>

/* function returning the addition of two numbers */
int add(n1, n2){
    int n;
    n = n1 + n2;
    return n;
}

int main(){

    int a = 5;
    int b = 2;
    int c;

    c = add(a,b);

    printf("%d", c);

}
