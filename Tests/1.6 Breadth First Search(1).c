#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{

    char parent;
    int color;
    int distance;
    char neighbors[27]

}Node;
int main(){

    int count;
    int i=0, j=0, l=0;
    int len;
    char S[30][30];
    char G[27];
    char N[27][27];

    // Read Inputs
    while(count!=-1){
        count=scanf("%s", &S[l]);
        if(count==-1){
            break;
        }
        else{
            l++;
        }
    }

    printf("l=%d\n", l);

    // Populate G and N
    for(i=0;i<l;i++){
        len=strlen(S[i]);
        for(j=0;j<len;j++){
            if(j==0){
                G[i]=S[i][0];
            } else if(j>1){
                N[i][j-2]=S[i][j];
            }
        }
        N[i][j-2]='\0';
    }
    G[i]='\0';

    printf("You entered:\n");
    for(i=0;i<l;i++){
        printf("%c-%s\n", G[i], N[i]);
    }

    for()


}
