/*
Eric Kang
Section 53
Lab 6

Description:
	Contains all definitions to functions listed in LinkList.h
	
*/

#include  <stdio.h>
#include  "LinkList.h"


/*-------------------------------------------------------------------
 * name: initList
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Initializes
 * 
 *------------------------------------------------------------------*/
void  initList(LinkedList  * p)
  {
     p->numFree = NUMNODES;		//a counter for the # of empty nodes
     p->numInList = INIT;		//a counter for # of full nodes
     p->first     = NULLVAL;	//location of first node in list
     p->free      = DEFAULT;	//location of first empty node

     int i;
     for (i=0 ; i < NUMNODES-1 ; i++)
	 {
		p->Nodes[ i ].data = 0;
		p->Nodes[ i ].next = i+1;	//sets next of node to point to next node
	 }
	 p->Nodes[NUMNODES-1].data = 0;
     p->Nodes[NUMNODES-1].next = NULLVAL;	//last node points to null
  
  
  }; 

/*-------------------------------------------------------------------
 * name: isEmpty
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Checks if linked list is empty
 * 
 * 4 ------------------------------------------------------------------*/
int    isEmpty(LinkedList * p)
{
	if(p->numInList == 0)
		return 1;
	else
		return 0;
};

/*-------------------------------------------------------------------
 * name: isMember
 * inputs: p (LinkedList ptr)
 *		   e (Element)
 * outputs: (none)
 * Returns True if element e is in linkedlist p
 * 
 * 9 ------------------------------------------------------------------*/
int    isMember(LinkedList  * p, Element e)
{
	int i;
	int eCnt = 0;

	i = p->first;
	for(i=p->first; i != NULLVAL; i = p->Nodes[i].next)
	{
		if(p->Nodes[i].data == e)
			eCnt = 1;
	}


	return eCnt;	
};

/*------------------------------------------------------------------- 
 * name: getNumFree
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Returns the value of available nodes in a given list
 * 
 * 2 ------------------------------------------------------------------*/
int    getNumFree(LinkedList * p)
{
	return p->numFree;
};

/*-------------------------------------------------------------------
 * name: getNumInList
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Returns the number of values in linkedlist p
 * 3 ------------------------------------------------------------------*/
int    getNumInList(LinkedList * p)
{
	return p->numInList;
};

/*-------------------------------------------------------------------
 * name: insertItem
 * inputs: p (LinkedList ptr)
 *		   e (Element)current
 * outputs: (none)
 * Allocates a new node. Sets data of node to e. find and insert into
 * ORDERED list
 * 10 ------------------------------------------------------------------*/
void   insertItem(LinkedList * p , Element e)
{
	int current;
	int i;
	int temp;

	if(p->numInList == NUMNODES)
		printf("\nERROR: List is Full\n");
	else
	{
		if(p->numInList == 0)
		{
			current = allocate(p);
			p->Nodes[current].data = e;
			p->Nodes[current].next = NULLVAL;
			p->first = 0;
			
		}//END Empty if
		else
		{
			current = allocate(p);
			p->Nodes[current].data = e;
			//Reorder List
			for(i=p->first; i != NULLVAL; i = p->Nodes[i].next)
			{			
				
				//is Current < First Value in Linked List
				if((p->Nodes[current].data < p->Nodes[i].data) && (i == p->first))
				{		
					p->Nodes[current].next = i;
					p->first = current;
					break; 

				}//
				//is Current > Final Value in Linked List
				else if((p->Nodes[current].data > p->Nodes[i].data) && (p->Nodes[i].next == NULLVAL))
				{		
					p->Nodes[current].next = NULLVAL;
					p->Nodes[i].next = current;
					break;	//break because manipulating p->Nodes[i].next results in infinite loop
				}
				//is Current less than Nodes[i].data
				else if(p->Nodes[current].data < p->Nodes[i].data)
				{	
					p->Nodes[current].next = i;
					temp = findPrevNode(p,p->Nodes[i].data);
					p->Nodes[temp].next = current;
					break;
				}//
			}
		}//END empty else
		
	}	
};

/*-------------------------------------------------------------------
 * name: removeItem
 * inputs: p (LinkedList ptr)
 *		   e (Element)
 * outputs: (none)
 * Find and delete the node in list(if in list) and deallocate the node
 * 11 ------------------------------------------------------------------*/
void   removeItem(LinkedList * p , Element e)
{
	Link l;
	if(isMember(p,e))
	{
		l = search(p,e);
		p->Nodes[findPrevNode(p,e)].next = p->Nodes[l].next;
		p->Nodes[l].data = 0;
		deallocate(p,l);
	}
	else
		printf("\nERROR: %d not found in List\n", e);
};


/*-------------------------------------------------------------------
 * name: showList
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * prints linked list
 *------------------------------------------------------------------*/
void showList(LinkedList  *  p)
  {
    printf(" numFree = %d \n", p->numFree);
    printf(" numInList = %d \n", p->numInList);
    printf(" free = %d \n", p->free);
    printf(" first = %d \n", p->first);
    int i;
    for (i=0 ; i < NUMNODES-1 ; i++)
      {
         printf("[%d |%d]  ",p->Nodes[i].data,p->Nodes[i].next);
      };
     printf("[%d |%d] \n",p->Nodes[NUMNODES-1].data,p->Nodes[NUMNODES-1].next);  
  };

/*-------------------------------------------------------------------
 * name: readInto
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Inserts a series of numbers into a Linked List
 * 12 ------------------------------------------------------------------*/
void   readInto(LinkedList  * p)
{
	int e;
	int i;

	for(i=0; i<5; i++)
	{
		printf("\nEnter a value to store in the List: ");
		scanf("%d",&e);
		insertItem(p,e);
	}
};

/*-------------------------------------------------------------------
 * name: allocate
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Returns the location of the first free node. Then adjusts the values of 
 * numFree and numInList and free to indicate location of new first free node
 * 7 ------------------------------------------------------------------*/
Link   allocate(LinkedList  * p)
{
	int tempFree = p->free;
	p->numFree--;
	p->numInList++;
	p->free = p->Nodes[tempFree].next;	//Update p->free

	return tempFree;
	
};

/*-------------------------------------------------------------------
 * name: deallocate
 * inputs: p (LinkedList ptr)
 * outputs: (none)
 * Given the location of a node to delete, it sould set NEXT of deleted node
 * to free. Adjust value of numFree and numInList and set FREE to location of
 * deleted node
 * 8 ------------------------------------------------------------------*/
void   deallocate(LinkedList  * p , Link l)
{
	p->Nodes[l].next = p->free;
	p->numFree++;
	p->numInList--;
	p->free = l;
};

/*-------------------------------------------------------------------
 * name: findPrevNode
 * inputs: p (LinkedList ptr)
 *		   e (Element)
 * outputs: (none)
 * Given an element(to insert or delete) return the location of the node
 * already in the list that should precede the given element in the list.
 * If there is none then return NULLVAL
 * 5 ------------------------------------------------------------------*/
Link   findPrevNode(LinkedList  * p , Element e)
{
	int i;
	int current;
	int prevNod;

	//First check if element is in list
	if(isMember(p,e))
	{
		current = search(p,e);
		//check if element is first value in list
		if(current == p->first)
			prevNod = NULLVAL;
		else
		{
			i = p->first;
			do
			{
				if(p->Nodes[i].next == current)
				{
					prevNod = i;
					break;
				}
				i = p->Nodes[i].next;
			}while(p->Nodes[i].next != NULLVAL);
		
		}
	}
	else
	{
		prevNod = NULLVAL;
	}

	return prevNod;
};

/*-------------------------------------------------------------------
 * name: search
 * inputs: p (LinkedList ptr)
 *		   e (Element)
 * outputs: (none)
 * Given an element find the location of the node containing the given
 * element on the list. If none return NULLVAL
 * 6 ------------------------------------------------------------------*/
Link   search(LinkedList  * p , Element e)  
{
	int i;
	int location;
	int present = 0;

	for(i=p->first; i != NULLVAL; i = p->Nodes[i].next)
	{
		if(p->Nodes[i].data == e)
		{
			location = i;
			present++;
		}
	}
	if(present == 0){
		location = NULLVAL;
	}
	return location;

};
