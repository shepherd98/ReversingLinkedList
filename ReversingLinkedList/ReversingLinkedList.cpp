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
	NewList->NextPosition = NULL;

	PNewTail = NewList;							
	HeadAddress = L->NextAddress;				//标记首节点的地址
	PTail = L;

	while ( HeadAddress != -1)
	{	
		if (HeadAddress == PTail->Address)		//如果节点对应的是尾结点的下个一地址
		{
			TempCell = (Position)malloc(sizeof(struct Node));
			//将该节点添加到新的链表
			TempCell = PTail;									
			HeadAddress = TempCell->NextAddress;				//下一个地址作为头地址
			PNewTail->NextPosition = TempCell;
			PNewTail = TempCell;

			DeletePosition(L, PTail->Data);
			TempCell->NextPosition = NULL;
			
			PTail = L;											//每找到一个节点，复位旧链表的指针
		}
		
		PTail = PTail->NextPosition;
	}

	return NewList;
}

//此处删除不能释放被删除节点的空间，因为被删除的节点被引用到了新的链表
void DeletePosition(List L, int Data)
{
	Position P, TempCell;

	P = FindPeriousPosition(L, Data);

	TempCell = P->NextPosition;
	P->NextPosition = TempCell->NextPosition;
	//free(TempCell);	

}

//找出被删除节点的上一个节点
Position FindPeriousPosition(List L, int Data)
{
	Position PPerious;
	
	PPerious = L;
	
	while (PPerious->NextPosition != NULL && PPerious->NextPosition->Data != Data)
		PPerious = PPerious->NextPosition;

	return PPerious;
}

//遍历链表
void TravalList(List L)
{
	Position P;
	P = L->NextPosition;
	while (P->NextPosition != NULL)
	{
		printf("%05d %d %05d\n", P->Address, P->Data, P->NextAddress);
		P = P->NextPosition;
	}
	printf("%05d %d %d\n", P->Address, P->Data, P->NextAddress);
	printf("\n");
}