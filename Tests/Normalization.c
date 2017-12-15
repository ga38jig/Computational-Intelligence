#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    double a[6]={-3, 4, 7, -5, 9, -2};
    double max;
    double min;
    int i;
    int l;
    double over;
    double dist;

    // find max and min
    l=sizeof(a) / sizeof(double);

    //max
    max=a[0];
    for(i=1;i<l;i++){
        if(a[i]>max){
            max=a[i];
        }
    }

    //min
    min=a[0];
    for(i=1;i<l;i++){
        if(a[i]<min){
            min=a[i];
        }
    }

    // Centre
    dist = max - min;
    over = max - dist/2;
    for(i=0;i<l;i++){
        a[i]=a[i]-over;
    }

    // Normalize
        for(i=0;i<6;i++){
        a[i]=a[i]/(dist/2);
    }


}


