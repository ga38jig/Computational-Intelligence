#include <stdio.h>

int main(){
    double a[2][3];
    scanf("%lf,%lf,%lf", &a[0][0], &a[0][1], &a[0][2]);
    scanf("%lf,%lf,%lf", &a[1][0], &a[1][1], &a[1][2]);
    printf(" %lf, %lf, %lf\n", a[0][0], a[0][1], a[0][2]);
    printf(" %lf, %lf, %lf\n", a[1][0], a[1][1], a[1][2]);
}
