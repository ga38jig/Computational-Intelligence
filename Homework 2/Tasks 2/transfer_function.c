#include <stdio.h>

double tf(double);

int main(){

    double out;
    double net=4.5;

    out=tf(net);
    printf("out: %lf\n", out);



}

double tf(double x){

    double y;

    y=x; // linear function

    return y;

}


