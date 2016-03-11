#ifndef __REVERSINGLINKEDLIST_H
#define __REVERSINGLINKEDLIST_H

#include <stdio.h>
#include <malloc.h>

typedef struct Node* PtrToNode;
typedef PtrToNode	 List;
typedef PtrToNode	 Position;

List CreatLinkedList(int firstAddress, int length, List L);
void TravalList(List L);
List SortList(List L);

#endif

struct Node
{
	int Address;
	int Data;
	int NextAddress;
	Position NextPosition;
};