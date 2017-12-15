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

    // Measure length of each input array in input_array_length.
    int input_array_length[l];
    for(i=0;i<l;i++){
        input_array_length[i]=strlen(input[i]);
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
            graph_array_length[i]=input_array_length[i]-1;
        }
        //
        // This is all superfluous. Don't waste time here.
        //
        else if(input_array_length[i]==1){
            graph_array_length[i]=1;
        }
        else{
            graph_array_length[i]=input_array_length[i]-1;
        }
        //
        // Go ahead.
        //
    }

    // Populate N.
    for(i=0;i<l;i++){
        N[i][0]=G[i][0];
        N[i][1]=i;
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


    s=number(G[0][0], l);                                                                   // Starting Node.
    parent[s]=-2;                                                                           // s.parent=/0
    color[s]=1;                                                                             // s.color='gray'
    distance[s]=0;                                                                          // s.distance=0

    insert(s);                                                                              // enqueue(Q,s)


    while(!isEmpty()){                                                                      // while Q is not empty
        node = removeData();                                                                // n = dequeue(Q)
        for(i=1;i<graph_array_length[node];i++){                                            // for v=n.all neighbors
            v=number(G[node][i], l);
            if(v!=parent[node]){
                if(color[v]==0){                                                            // if v.color='white'
                    color[v]=1;                                                             // v.color='gray'
                    distance[v]=distance[node]+1;                                           // v.distance=n.distance+1
                    parent[v]=node;                                                         // v.parent=n
                    insert(v);                                                              // enqueue(Q,v)
                }
            }
        }
        color[node]=2;                                                                      // n.color='black'
        k++;
        printf("%c", N[node][0]);
    }
    printf("\n");

    return 0;
}

