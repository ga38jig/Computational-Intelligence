#include <stdlib.h>
#include <time.h>

int main(){

    double n;
    int i;

    srand(time(NULL));

    for(i=0;i<10;i++){

        n=rand() % 21;
        printf("%lf\n", n);
        printf("%lf\n", (n-10)/10000);

    }

}
