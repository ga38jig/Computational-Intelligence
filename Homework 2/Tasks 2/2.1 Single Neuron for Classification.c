/**************************************/
/******** Supervised Learning *********/
/** Single Neuron for Classification **/
/**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    /* Training Data */
    double input1[1000], input2[1000], target[1000];
    /* Weights */
    double w1[1000], w2[1000], teta[1000];
    /* Updates */
    double dw1, dw2, dteta;
    /* Learning Rate */
    double n=0.001;

    int i=0, k=0, p;
    double n1, n2, n3;
    double out;
    int input_length;

    /* READ INPUT */
    printf("Enter input: \n");
    do{
        scanf("%lf,%lf,%lf", &input1[k], &input2[k], &target[k]);
        k++;
    }while(k<1000&&target[k-1]!=0);
    printf("\n");

    /* DEFINE QUANTITY OF TRAINING DATA */
    input_length = k-1;

    /* FOR CHECK: PRINT INPUT */
    printf("You entered: \n");
    for(i=0;i<input_length;i++){
        printf("%lf,%lf,%lf\n", input1[i], input2[i], target[i]);
    }
    printf("Entered strings: %d\n\n", input_length);


    /* NORMALIZE INPUTS WITH  */
    /* VALUES BETWEEN -1 AND 1*/
    normalize(input1, input_length);
    printf("\n");
    normalize(input2, input_length);
    printf("\n");

    /* FOR CHECK: PRINT NORMALIZED INPUT */
    printf("Normalized Input: \n");
    for(i=0;i<input_length;i++){
        printf("%lf,%lf\n", input1[i], input2[i]);
    }
    printf("\n");


    /* INITIALIZE WEIGHTS */
    srand(time(NULL));
    n1=rand() % 2100;
    n2=rand() % 2100;
    n3=rand() % 2100;
    w1[0]=(n1-1000)/1000000;
    w2[0]=(n2-1000)/1000000;
    teta[0]=(n3-1000)/1000000;

    printf("Initialize Weights:\n");
    printf("weight 1: %lf\n", w1[0]);
    printf("weight 2: %lf\n", w2[0]);
    printf("teta: %lf\n", teta[0]);


    /* GRADIENT DESCENT */

    // 1. Calculate gradient with respect to each model parameter
    // dwi = n * ( - 2 * ( tp - outp ) ) * pi

    // tp: desired output, a[p][2]
    // outp: actual output
    // outp = inp1 * w1 + inp2 * w2 + teta (linear)
    //      = a[p][0] * w1[p-1] + a[p][1] * w2[p-1] + teta[p-1]
    // pi: input i, a[p][i-1]

//    dw1=n*( - 2 * (a[p][2] - (a[p][0]*w1[p-1]+a[p][1]*w2[p-1]+teta[p-1])))*a[p][0];
//    dw2=n*( - 2 * (a[p][2] - (a[p][0]*w1[p-1]+a[p][1]*w2[p-1]+teta[p-1])))*a[p][1];


    return 0;
}

/* Function that normalizes array a */
void normalize(double a[], int l){

    int i;
    double max, min, dist, over;

    /* CHECK: PRINT THE INPUT */
    printf("array length: %d\n", l);
    printf("array:\n");
    for(i=0;i<l;i++){
        printf("%lf ", a[i]);
    }
    printf("\n\n");

    /* MAX */
    max=a[0];
    for(i=1;i<l;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    printf("max: %lf\n", max);

    /* MIN */
    min=a[0];
    for(i=1;i<l;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("min: %lf\n", min);

    /* Centre the array */
    dist = max - min;
    over = max - dist/2;
    for(i=0;i<l;i++){
        a[i]=a[i]-over;
    }

    /* Normalize */
    for(i=0;i<l;i++){
        a[i]=a[i]/(dist/2);
    }

}

