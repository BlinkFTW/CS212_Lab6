/*
Eric Kang
Section 53
Lab 6

Description:
	Header file
	
*/

#ifndef _LINKLIST
#define _LINKLIST

typedef   int      Element;
typedef   int      Link;

#define   NUMNODES    10
#define   DEFAULT     0
#define   INIT        0
#define   NULLVAL     -1

typedef struct    {
            Element  data;
            Link     next;
          } Node; 

typedef struct    {
            int      numFree;
            int      numInList;
            Link     free;
            Link     first;
            Node     Nodes[NUMNODES];
          } LinkedList;


void   initList(LinkedList * p);
int    isEmpty(LinkedList * p);
int    isMember(LinkedList  * p, Element e);
int    getNumFree(LinkedList * p);
int    getNumInList(LinkedList * p);
void   insertItem(LinkedList * p , Element e);
void   removeItem(LinkedList * p , Element e);
void   showList(LinkedList * p);
void   readInto(LinkedList  * p);
Link   allocate(LinkedList  * p);
void   deallocate(LinkedList  * p , Link l);
Link   findPrevNode(LinkedList  * p , Element e);
Link   search(LinkedList  * p , Element e);   
             
#endif
