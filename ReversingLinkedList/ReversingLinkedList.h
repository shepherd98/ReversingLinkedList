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
Position FindPeriousPosition(List L, int Data);
void DeletePosition(List L, int Data);
List ReversingList(List L, int K);
int LengthList(List L);

#endif

struct Node
{
	int Address;
	int Data;
	int NextAddress;
	Position NextPosition;
};