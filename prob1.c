//This program initializes a dynamically allocated array
//of size 16 so that each element is equal to its index.
//It then performs a cumulative sum so that result[i] is 
//set to result[0] + result[1] + ... + result[i].
//Finally, it prints out the resulting array.

//Hints: 
//      1) Use gdb to determine the line causing the segmentation
//         fault. See link to gdb help on course page.  In short,
//         you should type: gdb prob1, r, where, l prob1.c:<lineno>
//         where <lineno> is the line indicated by gdb where the seg
//         fault occurred.
//      2) Use man or google to find out what the system calls do
//         (for example, malloc and memcpy).
//      3) Use gdb to determine the values of various variables.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1 << 4

void initialize(int * array, int size);
void doWork(int * array, int size);
void printResult(int * result, int size);

int main()
{
   int result[SIZE]; 
   int numbytes = SIZE * sizeof(int);
   int * workArray = (int *) malloc(numbytes);
   initialize(workArray, SIZE);
   doWork(workArray, SIZE);
   memcpy(result, workArray, numbytes);
   printResult(result, SIZE);
}

//Prints the contents of an int array with size elements.
void printResult(int * result, int size)
{
   int i;
   for (i = 0; i < size; i++) printf("%d\n", result[i]);
}

//Initializes an int array with size elements by setting
//each element array[i] to i.
void initialize(int * array, int size)
{
   int i;
   for (i = 0; i < size; i++) array[i] = i;
}

//Performs a cumulative sum so that each element
//array[i] is set to array[0] + array[1] + ... + array[i]
void doWork(int * array, int size)
{
   int i, result = 0;
   for (i = 0; i < size; i++) 
   {
      array[i] = array[i] + result;
      result = array[i];
   }
}

