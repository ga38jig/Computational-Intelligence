#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n, count;

    // Loop

    while(1){

        count=scanf("%d", &n);
        if (count==0 || count==-1){   // Breaks Loop when Input invalid or EOF
            return 0;
        }
        else{
            printf("%d\n", n*2);      // Prints Input multiplied by 2
        }

    }

}
