#include <stdio.h>
#include <string.h>

int main(){

    int l,n,i,j,keyval;
    char s[100];

    // Read Input
    n=scanf("%s", &s);
    l=strlen(s);

    // Insertion Sort
    for(i=1;i<l;i++){
        keyval=s[i];
        j=i-1;
        while(s[j]>keyval && j>=0){
            s[j + 1] = s[j];
            j=j-1;
        }
        s[j+1]=keyval;
        printf("%s\n", s);
    }

    if(l==1){
        printf("%s", s);
    }

    return 0;
}
