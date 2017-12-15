#include <stdio.h>
#include <string.h>

int main() {

    int k=0,i,n,l;
    int swapped;
    int temp;
    char s[100];

    // Read Input
    n=scanf("%s", &s);
    l=strlen(s);

    // Check
    // printf("n=%d\nl=%d\n", n, l);

    // Bubble Sort
    do{
        swapped = 0;
        for(i=1;i<l;i++){
            if(s[i-1]>s[i]){
                // swap(s[i-1], s[i])
                temp=s[i];
                s[i]=s[i-1];
                s[i-1]=temp;
                swapped = 1;
            }
        }

        // Print String
        if(swapped==1||k==0){
            for(i=0;i<l;i++){
                printf("%c", s[i]);
            }
            printf("\n");
        }

        k++;

    }while(swapped);

    return 0;
}
