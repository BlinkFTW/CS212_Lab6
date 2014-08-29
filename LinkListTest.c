/*
Eric Kang
Section 53
Lab 6

Description:
	Demonstrates the functions in LinkList.h

Known Issues:
	The 'first' element of the LinkedList struct cannot change
	this results in an un-ordered linked list.

*/

#include <stdio.h>
#include "LinkList.h"



int  main()
{

    LinkedList    list1;
	LinkedList	  list2;
    initList(&list1);
    showList(&list1);

	if(isEmpty(&list1))
	{
		insertItem(&list1,20);
		insertItem(&list1,50);
		insertItem(&list1,30);
		insertItem(&list1,10);
		insertItem(&list1,70);
	}
    showList(&list1);
	
	if(isEmpty(&list1))
	{
		printf("\nERROR: List is Empty\n");
		showList(&list1);
	}
	else
		showList(&list1);
	
	if(isMember(&list1,10))
		printf("\nValue 10 is in List1\n");
	else
		printf("\nValue 10 is NOT in List1\n");
	
	if(isMember(&list1,25))
		printf("\nValue 25 is in List1\n");
	else
		printf("\nValue 25 is NOT in List1\n");
	
	if(isMember(&list1,50))
		printf("\nValue 50 is in List1\n");
	else
		printf("\nValue 50 is NOT in List1\n");
	
	if(isMember(&list1,70))
		printf("\nValue 70 is in List1\n");
	else
		printf("\nValue 70 is NOT in List1\n");
// Part 7
	removeItem(&list1, 30);
	removeItem(&list1, 20);
	removeItem(&list1, 70);
// Part 8
	if(isEmpty(&list1))
	{
		printf("\nERROR: List is Empty\n");
		showList(&list1);
	}
	else
		showList(&list1);
// Part 10
	insertItem(&list1,80);
	insertItem(&list1,0);
	insertItem(&list1,35);	

// Part 11
	if(isEmpty(&list1))
	{
		printf("\nERROR: List is Empty\n");
		showList(&list1);
	}
	else
		showList(&list1);
// Part12
	removeItem(&list1, 40);
	removeItem(&list1, 10);

// Part 13
	if(isEmpty(&list1))
	{
		printf("\nERROR: List is Empty\n");
		showList(&list1);
	}
	else
		showList(&list1);

// Part 14
	removeItem(&list1, 80);
	removeItem(&list1, 50);
	removeItem(&list1, 35);	
	removeItem(&list1, 0);	
	
// Part 15
	if(isEmpty(&list1))
	{
		printf("\nERROR: List is Empty\n");
		showList(&list1);
	}
	else
		showList(&list1);
	

// Part 16 - 18
	initList(&list2);
	readInto(&list2);
	showList(&list2);

	return 0;
};
