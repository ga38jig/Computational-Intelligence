#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

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

int main() {

    int i;
    int data;

   // peek
   // isEmpty
   // isFull
   // size
   // insert
   // removeData

   insert(5);
   insert(6);
   insert(7);

   // Print Queue
   for(i=0;i<MAX;i++){
        printf("%d ", intArray[i]);
   }

   printf("\n");
   data=removeData();

   printf("\nRemoved data: %d \n", data);

   // Print Queue
   for(i=0;i<MAX;i++){
        printf("%d ", intArray[i]);
   }


}
