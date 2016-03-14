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

	L = SortList(L);
	TravalList(L);
	free(L);
	return  0;
}

//创建链表
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

//给链表排序
List SortList(List L)
{
	Position PTail;
	Position PNewTail;
	Position TempCell;
	List NewList;
	int HeadAddress;
	int TailAddress;

	NewList = (List)malloc(sizeof(struct Node));//为新的链表分配空间
	PNewTail = NewList;							
	HeadAddress = L->NextAddress;				//标记首节点的地址
	PTail = L;
	//找出尾节点
	while (PTail->NextPosition != NULL && HeadAddress != -1)
	{
		if (HeadAddress == PTail->NextPosition->Address)		//如果节点对应的是尾结点的下个一地址
		{
			TempCell = (Position)malloc(sizeof(struct Node));
			//将该节点添加到新的链表
			TempCell = PTail->NextPosition;
			HeadAddress = TempCell->NextAddress;				//下一个地址作为头地址
			PNewTail->NextPosition = TempCell;
			PTail->NextPosition = TempCell->NextPosition;		//删除旧的结点
			TempCell->NextPosition = NULL;
			PNewTail = TempCell;
		}
		
		//
	}

	return NewList;
}

//遍历链表
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