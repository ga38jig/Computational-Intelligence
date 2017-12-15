#include <stdio.h>

int main(){

    char str[10];
    double d;
    printf("Enter number: ");
    scanf("%s", &str);
    sscanf(str, "%lf", &d);
    printf("\nYou entered: %lf", d);

}
