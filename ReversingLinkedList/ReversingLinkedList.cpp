#include "ReversingLinkedList.h"

int main()
{
	int firstAddress;
	int length;
	int changeList;

	List L;
	L = (List)malloc(sizeof(struct Node));

	scanf("%d %d %d", &firstAddress, &length, &changeList);
	L->NextAddress = firstAddress;
	L->NextPosition = NULL;

	L = CreatLinkedList(firstAddress, length, L);
	TravalList(L);
	free(L);
	return  0;
}

List CreatLinkedList(int firstAddress, int length, List L)
{
	Position PNew;
	List LTail;

	LTail = L;

	for (int i = 0; i < length; i++)
	{
		PNew = (Position)malloc(sizeof(struct Node));
		scanf("%d %d %d", &PNew->Address, &PNew->Data, &PNew->NextAddress);

		LTail->NextPosition = PNew;
		PNew->NextPosition = NULL;
		LTail = PNew;
	}

	//free(PNew);
	return L;
}

List SortList(List L)
{
	Position PHead;
	Position PTail;
	Position TempCell;
	List NewList;
	int HeadAddress;
	int TailAddress;

	NewList = (List)malloc(sizeof(struct Node));
	
	HeadAddress = L->NextAddress;				//标记首节点的地址
	PTail = L;
	//找出尾节点
	while (PTail != NULL)
	{
		if (PTail->NextPosition->NextAddress < 0)
		{
			TailAddress = PTail->NextPosition->Address;
			NewList->NextPosition = PTail->NextPosition;

		}
		PTail = PTail->NextPosition;
	}

	return L;
}

void TravalList(List L)
{
	Position P;
	P = L->NextPosition;
	while (P != NULL)
	{
		printf("%05d %d %05d\n", P->Address, P->Data, P->NextAddress);
		P = P->NextPosition;
	}
	printf("\n");
}