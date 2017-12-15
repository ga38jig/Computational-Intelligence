#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    char s[100];
    int l;

    // Read Input
    scanf("%s", &s);
    l=strlen(s);
    printf("length: %d\n", l);

    merge_sort(s, 0, l-1);
    return 0;

}

void merge_sort(char a[], int p, int r){

    printf("Entered merge_sort.\n");

    int q;
    int i;
    if(p!=r){
        q=(p+r+1)/2;
        printf("q=%d\n", q);
        //return 0;
        // Divide
        merge_sort(a, p, q-1);
        merge_sort(a, q, r);
        // Combine
        merge(a, p, r);
    }

}

void merge(char a[], int p, int r){

    printf("Entered merge.\n");
    printf("p=%d, r=%d\n", p, r);

    //Determine length of the divided strings
    int length;
    int i,j,k;
    length=(r-p+1)/2;
    //
    printf("length=%d\n", length);
    //
    char L[length], R[length];

    //Populate Left and Right string
    for(i=0;i<length;i++){
        L[i]=a[p+i];
    }
    for(j=0;j<length;j++){
        R[j]=a[p+length+j];
    }

    //
    printf("L is: ");
    for(i=0;i<length;i++){
        printf("%c", L[i]);
    }
    printf("\n");

    printf("R is: ");
    for(i=0;i<length;i++){
        printf("%c", R[i]);
    }
    printf("\n");
    //

    //Merge
    i=0;
    j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j] && i<length || j>=length){
            a[k]=L[i];
            i++;
            printf("L\n");
        }
        else{
            a[k]=R[j];
            j++;
            printf("R\n");
        }
    }

    // Print
    printf("Merge: ");
    for(i=p;i<=r;i++){
        printf("%c", a[i]);
    }
    printf("\n");

}
