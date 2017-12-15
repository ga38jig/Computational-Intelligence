/*********************************************************************/
/** Demonstrates the usage of a void function to normalize an array **/
/*********************************************************************/
#include <stdio.h>

int main(){

    double a[] = {-3, 4, 7, -5, 9, -2};
    int i, l;

    l=sizeof(a) / sizeof(double);

    printf("Entered Array:\n");
    printf("[");
    for(i=0;i<l;i++){
        printf("%lf ", a[i]);
    }
    printf("]\n");


    normalize(a, l);


    printf("Normalized Array:\n");
    printf("[");
    for(i=0;i<l;i++){
        printf("%lf ", a[i]);
    }
    printf("]\n");

    return 0;

}

/* Function that normalizes array a */
void normalize(double a[], int l){

    int i;
    double max, min, dist, over;

    /* MAX */
    max=a[0];
    for(i=1;i<l;i++){
        if(a[i]>max){
            max=a[i];
        }
    }

    /* MIN */
    min=a[0];
    for(i=1;i<l;i++){
        if(a[i]<min){
            min=a[i];
        }
    }

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
