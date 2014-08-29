#Eric Kang
#makefile for lab6
#Section 53

all:LinkListTest

LinkListTest:LinkListTest.o LinkList.o
	gcc -Wall -g LinkList.o LinkListTest.o -o LinkListTest

LinkListTest.o:LinkListTest.c LinkList.h
	gcc -Wall -g -c LinkListTest.c -o LinkListTest.o

LinkList.o: LinkList.c LinkList.h
	gcc -Wall -g -c LinkList.c -o LinkList.o
