#include <stdio.h>
#include <string.h>

int main(){

    int a[10]={1, 2, 3, 4, 5};
    int l;

    l=sizeof(a) / sizeof(int);

    printf("%d\n", l);
}
