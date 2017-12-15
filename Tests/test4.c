#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int size_a = 10;
    int size_b = 10;
    char a[size_a], b[size_b];
    //char b[size_b];

    scanf("%s", &a);
    scanf("%s", &b);

    printf("string a is %s\n", a);
    printf("string b is %s\n", b);

    a[0]=b[0];

    printf("now string a is %s\n", a);

    return 0;
}
