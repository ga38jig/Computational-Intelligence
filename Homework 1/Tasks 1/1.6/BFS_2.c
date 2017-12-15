/*** BREADTH FIRST SEARCH ***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 27

    char input[MAX][MAX];   // Raw User Input.
    char G[MAX][MAX];       // Graph.
    char N[MAX][2];         // Array that associates every node to the corresponding number.
    char parent[MAX];       //
    char children[MAX];     //
    int color[MAX];         // 0=White; 1=Gray; 2=Black.
    int distance[MAX];      //

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek() {
   return intArray[front];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}

void insert(int data) {

   if(!isFull()) {

      if(rear == MAX-1) {
         rear = -1;
      }

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData() {
   int data = intArray[front++];

   if(front == MAX) {
      front = 0;
   }

   itemCount--;
   return data;
}

void print_queue(){
    int i;
    printf("\nQueue: ");
    for(i=0;i<MAX;i++){
        printf("%c ", N[intArray[i]][0]);
    }
}

int number( char x, int l ) {
    int i;
    for(i=0;i<l;i++){
        if(x==N[i][0]){
            return N[i][1];
        }
    }
}

int main(){

    int count, l=0;         // Input Parameters.
    int i=0,j=0,k=1;        // Indexes.
    int q=0;
    int s;                  // Starting Node.
    int node;               // Node Index.
    int v;                  // Neighbor Index.

    /** Phase 1: Read Input **/
    // Returns input[][].

    while(count!=-1){
            count=scanf("%s", &input[l]);
            if(count==-1){
                break;
            }
            else{
                l++;
            }
    }

    /* Print some values to verify that the input is registered correctly */

    printf("You entered %d strings.\n", l);

    for(i=1;i<=l;i++){
       printf("Array number %d: %s\n", i, input[i-1]);
    }

    // Measure length of each input array in input_array_length.
    int input_array_length[l];
    printf("Length of entered arrays:\n");
    for(i=0;i<l;i++){
        input_array_length[i]=strlen(input[i]);
        printf("%d ", input_array_length[i]);
    }


    /**
    Breadth first search requires a starting node (given by the first element of the input)
    and a graph, built according to the structure of the given input. You need the graph in
    order to determine which are the neighbors of the input. So, to reduce the problem, it
    would be enough to just create a multidimensional array of neighbors instead of a proper
    adjacency matrix.
    **/


    /* Populate graph G. */
    int graph_array_length[l];

    // Element 0: Father.
    // Elements 1-N: Children.
    for(i=0;i<l;i++){
        G[i][0]=input[i][0];
        if(input_array_length[i]>2){
            for(j=2;j<input_array_length[i];j++){
                G[i][j-1]=input[i][j];
            }
            graph_array_length[i]=input_array_length[i]-3;
            printf("\n%d. Input array length: %d", i+1, input_array_length[i]);
            printf("\n   Graph array length: %d", graph_array_length[i]);
        }
        //
        // This is all superfluous. Don't waste time here.
        //
        else if(input_array_length[i]==1){
            graph_array_length[i]=1;
            printf("\n%d. Input array length: %d", i+1, input_array_length[i]);
            printf("\n   Graph array length: %d", graph_array_length[i]);
        }
        else{
            graph_array_length[i]=input_array_length[i]-1;
            printf("\n%d. Input array length: %d", i+1, input_array_length[i]);
            printf("\n   Graph array length: %d", graph_array_length[i]);
        }
        //
        // Go ahead.
        //
    }


    // Print Graph G.
    printf("\nGraph:\n");
    for(i=0;i<l;i++){
        for(j=0;j<graph_array_length[i];j++){
            printf("%c ", G[i][j]);
        }
        printf("\n");
    }

    // Populate N.
    printf("Populating N: \n");
    for(i=0;i<l;i++){
        N[i][0]=G[i][0];
        N[i][1]=i;
        printf("%c %d\n", N[i][0], N[i][1]);
    }

    for(i=0;i<l;i++){
        color[i]=0;
        parent[i]=-1;
    }

    for(i=0;i<MAX;i++){
        intArray[i]=35;
    }




    /********************************************************/
    /********************************************************/
    /***** !!!!! HERE BEGINS THE ACTUAL ALGORITHM !!!!! *****/
    /********************************************************/
    /********************************************************/

    printf("\nSTARTING BREADTH-FIRST-SEARCH ALGORITHM.\n");


    print_queue();
    printf("\nFront=%d, Rear=%d", front, rear);
    s=number(G[0][0], l);                                                                   // Starting Node.
    printf("\nStarting node: %c.", G[s][0]);
    parent[s]=-2;                                                                           // s.parent=/0
    color[s]=1;                                                                             // s.color='gray'
    distance[s]=0;                                                                          // s.distance=0

    printf("\nInsert %c", N[s][0]);
    insert(s);                                                                              // enqueue(Q,s)
    print_queue();
    printf("\nFront=%d, Rear=%d", front, rear);
    printf("\nNode %c inserted.", N[s][0]);


    while(!isEmpty()){                                                                      // while Q is not empty
        printf("\n\nInstance Number %d. ", k);
        printf("\nRemove %c", N[peek()][0]);
        node = removeData();
        print_queue();
        printf("\nFront=%d, Rear=%d", front, rear);
        printf("\nNode %c removed.", N[node][0]);                                           // n = dequeue(Q)

        printf("\nCurrent Node: %c.", N[node][0]);
                                                                        //printf("\nArray length of current line: %d.", graph_array_length[node]);
        printf("\nChecking Neighbors:");
        for(i=1;i<graph_array_length[node];i++){                                            // for v=n.all neighbors
            printf("\nStart of Iteration.");
                                                                        //printf("\ni=%d, gr_len=%d.", i, graph_array_length[node]);
            v=number(G[node][i], l);
            printf("\nIterated neighbor: %c.", N[v][0]);
            if(v!=parent[node]){
                printf("\nNeighbor: %c ", N[v][0]);
                if(color[v]==0){                                                            // if v.color='white'
                    color[v]=1;                                                            // v.color='gray'
                    distance[v]=distance[node]+1;                                           // v.distance=n.distance+1
                    parent[v]=node;                                                         // v.parent=n
                    printf("\nInsert %c", N[v][0]);
                    insert(v);                                                              // enqueue(Q,v)
                    print_queue();
                    printf("\nFront=%d, Rear=%d", front, rear);
                    printf("\nNode %c inserted.", N[v][0]);
                    printf("\nQueue: ");
                }
            }
            printf("\nEnd of Iteration.");
        }
        color[node]=2;                                                                      // n.color='black'
        printf("\nNode number %d: %c.", k, N[node][0]);
        printf("\nEnd of Instance %d.", k);
        k++;
        q++;
    }


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







