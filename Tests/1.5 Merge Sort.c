#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    char s[100];
    int l;

    // Read Input
    scanf("%s", &s);
    l=strlen(s);
    if(l==1){
        printf("%c", s[0]);
    }
    else{
        merge_sort(s, 0, l-1);
    }
    return 0;

}

void merge_sort(char a[], int p, int r){

    int q;
    int i;
    if(p!=r){
        q=(p+r+1)/2;
        // Divide
        merge_sort(a, p, q-1);
        merge_sort(a, q, r);
        // Combine
        merge(a, p, r);
    }

}

void merge(char a[], int p, int r){

    //Determine length of the divided strings
    int length;
    int i,j,k;
    length=(r-p+1)/2;
    char L[length], R[length];

    //Populate Left and Right string
    for(i=0;i<length;i++){
        L[i]=a[p+i];
    }
    for(j=0;j<length;j++){
        R[j]=a[p+length+j];
    }

    //Merge
    i=0;
    j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j] && i<length || j>=length){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
    }

    // Print
    for(i=p;i<=r;i++){
        printf("%c", a[i]);
    }
    printf("\n");
}

