#include <stdio.h>
#include <math.h>

int main(){

    double y;
    double x;

    x=0.000001;

    y=tanh(100000000*x);
    printf("%lf\n", y);

    // tanh(x)' = 1-tanh(x)^2

}
