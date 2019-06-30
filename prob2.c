//This program concatenates two strings and prints the result.

//Hints: see hints in prob1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concat(char *, char *);

int main()
{
   char * str1 = "C programming is ";
   char * str2 = "challenging and fun.";
   printf("%s\n", concat(str1, str2));
}

//Concatenates str1 and str2 and performs
//the concatenation.
char * concat(char * str1, char * str2)
{
   char * dest;
   strcpy(dest, str1);
   strcpy(&dest[strlen(str1)], str2);
   return dest;
}
