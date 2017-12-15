/**************************************/
/******** Supervised Learning *********/
/** Single Neuron for Classification **/
/**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double tf(double);

int main() {

    double input_1[1000], input_2[1000], target[1000];                  // Training Data.
    double eva_inp_1[1000], eva_inp_2[1000];                            // Evaluation Data.
    double w_1[1000], w_2[1000], teta[1000];                            // Training Parameters.
    double G1, G2, G3;                                                  // Parameter Gradients.
    double dw_1, dw_2, dteta;                                           // Parameter Updates.
    double n=0.001;                                                     // Learning Rate.

    int count;                                                          // Scan Variable.
    int i=0, k=0, p=0, e=0;                                             // Indexes.
    double n1, n2, n3;                                                  // Random Values.
    double out, net;                                                    // Output and Net of Neuron.
    int input_length, evaluation_length;                                // Length of Input Strings.



    /*** STEP 0: READ INPUT. ***/

    printf("Enter training data:\n");                                   // READ TRAINING DATA.
    do{
        scanf("%lf,%lf,%lf", &input_1[k], &input_2[k], &target[k]);
        k++;
    }while(k<1000&&target[k-1]!=0);

    input_length = k-1;                                                 // DEFINE LENGTH OF TRAINING DATA.

    k=0;
    printf("Enter evaluation data:\n");                                 // READ EVALUATION DATA.
        do{
        count=scanf("%lf,%lf", &eva_inp_1[k], &eva_inp_2[k]);
        k++;
    }while(k<1000&&count!=-1);
    printf("\n");

    evaluation_length = k-1;                                            // DEFINE LENGTH OF TRAINING DATA.

    printf("Training Objects: %d\n", input_length);
    printf("Evaluation Objects: %d\n\n",evaluation_length);

//                                    /* FOR CHECK: PRINT TRAINING DATA */
//                                    printf("Entered Training Data: \n");
//                                    for(i=0;i<input_length;i++){
//                                        printf("%lf,%lf,%lf\n", input_1[i], input_2[i], target[i]);
//                                    }
//                                    printf("Entered strings: %d\n\n", input_length);
//
//                                    /* FOR CHECK: PRINT EVALUATION DATA */
//                                    printf("Entered Evaluation Data: \n");
//                                    for(i=0;i<evaluation_length;i++){
//                                        printf("%lf,%lf\n", eva_inp_1[i], eva_inp_2[i]);
//                                    }
//                                    printf("Entered strings: %d\n\n", evaluation_length);


//                                    /* NORMALIZE INPUTS WITH  */
//                                    /* VALUES BETWEEN -1 AND 1*/
//                                    normalize(input_1, input_length);
//                                    normalize(input_2, input_length);
//                                    normalize(eva_inp_1,evaluation_length);
//                                    normalize(eva_inp_2,evaluation_length);
//
//
//                                    /* FOR CHECK: PRINT NORMALIZED INPUT */
//                                    printf("Normalized Input: \n");
//                                    for(i=0;i<input_length;i++){
//                                        printf("%lf,%lf\n", input_1[i], input_2[i]);
//                                    }
//                                    printf("\n");



    /*** STEP 1: INITIALIZE WEIGHTS. ***/

    srand(time(NULL));                              // Generates Random Values Between -0.001 and +0.001 for Parameters w1, w2, teta.
    n1=rand() % 21;
    n2=rand() % 21;
    n3=rand() % 21;
    w_1[0]=(n1-10)/10000;
    w_2[0]=(n2-10)/10000;
    teta[0]=(n3-10)/10000;

    printf("Initialize Weights:\n");
    printf("weight 1: %lf\n", w_1[0]);
    printf("weight 2: %lf\n", w_2[0]);
    printf("teta: %lf\n", teta[0]);
    printf("\n");



    /* TRAINING STARTS */
    printf("Training starts.\n\n");

    /* GRADIENT DESCENT */
    for(p=0;p<input_length;p++){                                        // MAIN LOOP.



    /*** STEP 2: Calculate Gradient with respect to each Parameter. ***/

        net = input_1[p]*w_1[p] + input_2[p]*w_2[p] - teta[p];          // WEIGHTED SUM OF INPUTS.
        out = tf(net);                                                  // COMPUTE OUTPUT.
        G1 = -2*input_1[p]*(target[p]-out);                             //
        G2 = -2*n*input_2[p]*(target[p]-out);                           // COMPUTE GRADIENTS (TF LINEAR).
        G3 = +2*n*(target[p]-out);                                      //
        dw_1=n*G1;                                                      //
        dw_2=n*G2;                                                      // COMPUTE PARAMETER UPDATES.
        dteta=n*G3;                                                     //



    /*** STEP 3: Update Parameters. ***/

        w_1[p+1]=w_1[p]+dw_1;                                           //
        w_2[p+1]=w_2[p]+dw_2;                                           // UPDATE PARAMETERS.
        teta[p+1]=teta[p]+dteta;                                        //

        if(p<5 || p>195){                                               // Print Updates for first and last five steps.

//    printf("Target: %lf\n", target[p]);
////    printf("net=%lf*%lf+%lf*%lf-%lf=%lf\n", input_1[p], w_1[p], input_2[p], w_2[p], teta[p], net);
//    printf("Out: %lf\n", out);
////    printf("dw_1=-2*n*%lf*(%lf-%lf)=%lf\n", input_1[p], target[p], out, dw_1);
////    printf("dw_2=-2*n*%lf*(%lf-%lf)=%lf\n", input_2[p], target[p], out, dw_2);
////    printf("dteta=-2*n*-1*(%lf-%lf)=%lf\n", target[p], out, dteta);



////    printf("w_1[%d]=w_1[%d]+dw_1;\n", p, p-1);
////    printf("w_1[%d]=%lf+%lf=%lf\n", p+1, w_1[p], dw_1, w_1[p+1]);
////    printf("w_1[%d]=%lf\n", p, w_1[p]);
//
////    printf("w_2[%d]=w_2[%d]+dw_2;\n", p, p-1);
////    printf("w_2[%d]=%lf+%lf=%lf\n", p+1, w_2[p], dw_2, w_2[p+1]);
////    printf("w_2[%d]=%lf\n", p, w_2[p]);
//
////    printf("teta[%d]=teta[%d]+dteta;\n", p, p-1);
//    printf("teta[%d]=%lf+%lf=%lf\n", p+1, teta[p], dteta, teta[p+1]);
////    printf("teta[%d]=%lf\n", p, teta[p]);
//    printf("\n");

    }

    }

//    printf("Trained weights:\n");
//    printf("Weight 1:%lf\n", w_1[p]);
//    printf("Weight 2:%lf\n", w_2[p]);
//    printf("Teta:%lf\n", teta[p]);
//    printf("\n");

    /* TRAINING COMPLETE */
//    printf("Training complete.\n\n");


    /* EVALUATION STARTS */
//    printf("Evaluation starts.\n\n");

    /* EVALUATE */
    for(e=0;e<evaluation_length;e++){
        net=eva_inp_1[e]*w_1[p-1] + eva_inp_2[e]*w_2[p-1] - teta[p-1];
        out=tf(net);
//        printf("%lf\n", out);
    }
    printf("\n");

    /* EVALUATION ENDS */
    printf("Evaluation ended.\n");


    return 0;
}

/* Function that normalizes array a */
void normalize(double a[], int l){

    int i;
    double max, min, dist, over;

                                    /* CHECK: PRINT THE INPUT */
                                //    printf("array length: %d\n", l);
                                //    printf("array:\n");
                                //    for(i=0;i<l;i++){
                                //        printf("%lf ", a[i]);
                                //    }
                                //    printf("\n\n");

    /* MAX */
    max=a[0];
    for(i=1;i<l;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
//    printf("max: %lf\n", max);

    /* MIN */
    min=a[0];
    for(i=1;i<l;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
//    printf("min: %lf\n", min);

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

/* Transfer Function */
double tf(double x){

    double y;

//    y=tanh(100000*x);           // tanh()
    y=x;                        // linear

    return y;

}
