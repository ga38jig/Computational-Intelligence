#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char G[27];

    G[0]='c';
    G[1]='i';
    G[2]='a';
    G[3]='\0';
    G[4]='o';

    printf("%c", G[0]);
    printf("\n%c", G[1]);
    printf("\n%c", G[2]);
    printf("\n%c", G[3]);
    printf("\n%s", G);
    printf("\n%d", strlen(G));

    return 0;

}
