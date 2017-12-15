#include <stdio.h>

int main(){
    int count = 1;
    int number;

    /* Loop repeats as long as input is valid (count!=0) and EOF is not reached (count!=-1) */
    while(1){

        /* Step 1: Read input data */
        count=scanf("%d", &number);

        /* Step 2: Multiply input by 2 */
        if(count==1){
            printf("%d\n", number * 2);
            //printf("%d\n", count);
        } else {
            return 0;
        }
    }
}
