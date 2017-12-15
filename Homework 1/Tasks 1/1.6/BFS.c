/*** BREADTH FIRST SEARCH ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char input[27][27];     // Raw User Input.
    char A[27][27];         // Adjacency Matrix.
    char L[27];             // List of Node Names.
    int array_length[27];   // Array of Input Lengths.
    int count, l=0;         // Input Parameters.
    int i,j, k;             // Indexes.
    int length;             // Temporary Array Length Value.

    /** Phase 1: Read Input **/
    // Returns input[][]

    while(count!=-1){
            count=scanf("%s", &input[l]);
            if(count==-1){
                break;
            }
            else{
                l++;
            }
    }


    /** Phase 2: Produce Adjacency Matrix A **/

    printf("\n");
    printf("List of Nodes: ");
    // Produce list L.
    for(i=0;i<l;i++){
        L[i]=input[i][0];
        printf("%c",L[i]);
    }
    L[i]=EOF;
    printf(".\n");


    // Produce Matrix A l*l.
    printf("\n");
    printf("Producing Matrix A.\n");
    for(i=0;i<l;i++){
        length=strlen(input[i]);
        if(length<=2 && input[i][length-2]=='\\'){
            array_length[i]=strlen(input[i])-2;
        }
        else{
            array_length[i]=strlen(input[i]);
        }
        printf("Length of array %d = %d.\n", i+1, array_length);
        k=2;
        for(j=0;j<l;j++){
            if(L[j]==input[i][k]){
                A[i][j]=1;
                k++;
            }
            else{
                A[i][j]=0;
            }
        }
    }

//    printf("\n%c %c %c", A[0][0], A[0][1], A[0][2]);

//    printf("\n");
//    printf("Adjacency Matrix: \n");
//    for(i=0;i<l;i++){
//        for(j=0;j<l;j++){
//            printf("%c ", A[i][j]);
//        }
//        printf("\n");
//    }



    /* Phase 3: Explore Graph */


    return 0;
}

/*** BFS PSEUDOCODE ***/

//function BFS(G,s){
//
//    s.parent=/0
//    s.color='gray'
//    s.distance=0
//
//    enqueue(Q,s)
//
//    while Q is not empty
//        n = dequeue(Q)
//        n.children={}
//        for v=n.all neighbors
//            if v.color='white'
//                v.color='gray'
//                v.distance=n.distance+1
//                v.parent=n
//                enqueue(Q,v) || Q={Q,v}
//                n.children=add v || n.children={n.children, v}
//            end
//        end
//        n.color='black'
//        print(n)
//    end
//
//}


//    // Print some values to verify that the input is registered correctly
//
//    printf("You entered %d strings.\n", l);
//
//    for(i=1;i<=l;i++){
//       printf("Array number %d: %s\n", i, S[i-1]);
//    }


