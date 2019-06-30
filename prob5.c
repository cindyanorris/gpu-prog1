//This program inserts two elements into a linked list.
//It then calls the getId function twice to get the id of 
//the two PersonT objects in the linked list and prints
//out those ids. 

//Hints: 1) See hints in prob1.c to see where the seg fault is.
//          However, fixing the problem involves changing code
//          elsewhere.
//       2) The fixes for this code are more significant than
//          for the previous problems.  You'll need to have some
//          understanding of linked lists and pointers in C to
//          be able to fix it completely.
//       3) When you fix the first seg fault, it may print -1 for the
//          ids (although it could also still seg fault because it
//          does have memory errors).
//       4) When you get it working completely, it should print:
//
//       Joe Smith's id is: 123
//       Carol Field's id is: 456

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{ 
   char firstNm[32];
   char lastNm[32];
   int id;
} PersonT;

typedef struct Node
{
   struct Node * next;
   PersonT * person;
} NodeT;

PersonT * makePerson(char * firstNm, char * lastNm, int id);
NodeT * insertPerson(NodeT * first, PersonT * p);
NodeT * makeNode(PersonT * p);
void getId(NodeT * first, char * firstNm, char * lastNm, int * id);

int main()
{
   NodeT * first;
   first = insertPerson(first, makePerson("Joe", "Smith", 123));   
   first = insertPerson(first, makePerson("Carol", "Field", 456));   
   int * id;
   getId(first, "Joe", "Smith", id);
   printf("Joe Smith's id is: %d\n", *id);
   getId(first, "Carol", "Field", id);
   printf("Carol Field's id is: %d\n", *id);
}

//Creates a PersonT object, initializes it, and returns 
//a pointer to it.
PersonT * makePerson(char * firstNm, char * lastNm, int id)
{
   PersonT p;
   PersonT * ptr = &p;
   strcpy(p.firstNm, firstNm);
   strcpy(p.lastNm, lastNm);
   p.id = id;
   return ptr;
}

//Creates an NodeT object, initializes, and returns 
//a pointer to it.
NodeT * makeNode(PersonT * p)
{
   NodeT node;
   NodeT * nodePtr = &node;
   node.person = p;
   node.next = NULL;
   return nodePtr;
}

//Creates a NodeT object and sets the person field to p.
//Inserts the NodeT object in the beginning of the
//linked list.
NodeT * insertPerson(NodeT * first, PersonT * p)
{
   NodeT * nodePtr = makeNode(p);
   if (first == NULL) return nodePtr;
   nodePtr->next = first;
   first = nodePtr;
   return first;
}

//Finds the PersonT object in the linked list with
//first name equal to firstNm and last name equal to lastNm.
//Sets the int pointed to by id to the id in the PersonT object.
//first - points to the first node in the linked list
void getId(NodeT * first, char * firstNm, char * lastNm, int * id)
{
   NodeT * ptr = first;
   while (ptr != NULL)
   {
      if (!strcmp(ptr->person->firstNm, firstNm) && 
          !strcmp(ptr->person->lastNm, lastNm))
      {
         *id = ptr->person->id;
         return;
      }
      ptr = ptr->next;
   }
   (*id) = -1;
   return; 
}   


