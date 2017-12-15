#include <stdio.h>
#include <stdlib.h>

int *main(){

    double input_1[1000], input_2[1000], target[1000];      // TRAINING DATA
    double eva_inp_1[1000], eva_inp_2[1000];                // EVALUATION DATA
    double w_1, w_2, teta;                // WEIGHTS
    double dw_1, dw_2, dteta;                               // UPDATES
    double n=0.001;                                         // LEARNING RATE

    int count;
    int i=0, k=0, p=0, e=0;
    double n1, n2, n3;
    double outp, net;
    double G_1, G_2, G_3;
    double E;
    int training_length, evaluation_length;



    /*** READ INPUTS ***/

    do{
        scanf("%lf,%lf,%lf", &input_1[k], &input_2[k], &target[k]);
        k++;
    }while(k<1000&&target[k-1]!=0);

    training_length = k-1;
    k=0;

    do{
        count=scanf("%lf,%lf", &eva_inp_1[k], &eva_inp_2[k]);
        k++;
    }while(k<1000&&count!=-1);

    evaluation_length = k-1;

    printf("\nEntered Training Data: \n");

    for(i=0;i<training_length;i++){
        printf("%lf,%lf,%lf\n", input_1[i], input_2[i], target[i]);
    }

    printf("Training Patterns: %d\n", training_length);

    printf("\nEntered Evaluation Data: \n");

    for(i=0;i<evaluation_length;i++){
        printf("%lf,%lf\n", eva_inp_1[i], eva_inp_2[i]);
    }

    printf("Evaluation patterns: %d\n", evaluation_length);



    /*** TRAIN ARTIFICIAL NEURON ***/

    // STEP 1: PICK RANDOM INITIAL WEIGHTS.

    srand(time(NULL));
    n1=rand() % 21;
    n2=rand() % 21;
    n3=rand() % 21;
    w_1=(n1-10)/10000;
    w_2=(n2-10)/10000;
    teta=(n3-10)/10000;

    w_1=-1;
    w_2=1;
    teta=0;

    printf("\nInitialize Weights:\n");
    printf("weight 1: %.4lf\n", w_1);
    printf("weight 2: %.4lf\n", w_2);
    printf("teta: %.4lf\n", teta);

    E = 0;
    for(p=0;p<training_length;p++){
        net = input_1[p] * w_1 + input_2[p] * w_2 - teta;
        outp = net;
        printf("\nOut%d = %lf", p, outp);
        E = E + powf((target[p]-outp),2);
    }

    printf("\nError Function:");
    printf("\nE = %lf", E);

    // STEP 2: COMPUTE GRADIENT WITH RESPECT TO EACH PARAMETER.

    p=0;
//    for(p=0;p<training_length;p++){}
    net = input_1[p] * w_1 + input_2[p] * w_2 - teta;
    outp = net;

    G_1 = -2*(target[p]-outp)*input_1[p];
    G_2 = -2*(target[p]-outp)*input_2[p];
    G_3 = -2*(target[p]-outp)*(-1);

    printf("\nCompute Gradient:\n");
    printf("G_1: %.4lf\n", G_1);
    printf("G_2: %.4lf\n", G_2);
    printf("G_3: %.4lf\n", G_3);
    printf("\n");

    // STEP 3: UPDATE PARAMETERS.

    dw_1 = n * G_1;
    dw_2 = n * G_2;
    dteta = n * G_3;

    w_1 = w_1 + dw_1;
    w_2 = w_2 + dw_2;
    teta = teta + dteta;

    printf("\nUpdate Parameters:\n");
    printf("w_1 = w_1 + dw_1 = %.4lf\n", w_1);
    printf("w_2 = w_2 + dw_2 = %.4lf\n", w_2);
    printf("teta = teta + dteta = %.4lf\n", teta);
    printf("\n");


    return 0;

}
