//This program takes a command line argument that specifies
//the number of integers to sort.
//It then randomly generates those integers and sorts them.
//Finally, it prints out the sorted list.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initialize(int *, int);
void bubblesort(int *, int);
void printNums(int *, int);
void printUsage();

int main(int argc, char * argv[])
{
   if (argc < 2) printUsage();
   int size = atoi(argv[1]);
   int * array = malloc(sizeof(int) * size);
   initialize(array, size);
   bubblesort(array, size);
   printNums(array, size);
}

//Initializes an array of size elements to
//randomly generated ints between the values 0 and 99.
void initialize(int * array, int size)
{
   int i;
   int * ptr = &array[0];
   srand(time(NULL));
   for (; ptr != &array[size]; ptr++)
      (*ptr) = rand() % 100;
}  

//Performs a bubblesort of an array containing size elements.
void bubblesort(int * array, int size)
{
   int i, j;
   for (int i = 0; i < size; i++)
   {
      for (j = 0; j < size - i - 1; j++)
      {
         if (array[j] > array[j+1])
         {
            array[j] = array[j] ^ array[j+1];   
            array[j + 1] = array[j] ^ array[j+1];  
            array[j] = array[j] ^ array[j+1];  
         }
      }
   }
}

//Prints the contents of an array containing size elements.
void printNums(int * array, int size)
{
   int * ptr = &array[0];
   while (ptr <= &array[size])
   {
      printf("%d\n", *ptr);
      ptr++;
   }
}

//Prints information about how to run this program.
void printUsage()
{
   printf("usage: prob4 <n>\n");
   printf("       Performs a bubble sort of n randomly generated ints.\n");
   exit(0);
}

