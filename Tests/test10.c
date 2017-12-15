#include<stdio.h>
#include<stdlib.h>

int main(){

    char c;
    char s[10];
    int count;
    count=scanf("%c-%s", &c, &s);


    printf("%d\n", count);
    printf("%c %s", c, s);

}
