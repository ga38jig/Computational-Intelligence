#include <stdio.h>

int main(){
    double a[3][3];
    scanf("%lf,%lf,%lf", &a[0][0], &a[0][1], &a[0][2]);
    printf("%lf,%lf,%lf\n", a[0][0], a[0][1], a[0][2]);
    if(a[0][2]!=0){
        printf("Pants");
    }
}
