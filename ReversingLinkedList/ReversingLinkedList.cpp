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


struct Node
{
	int Address;
	int Data;
	int NextAddress;
	Position NextPosition;
};

int main()
{
	int firstAddress;
	int length;
	int changeList;

	List L;
	L = (List)malloc(sizeof(struct Node));

	//输入首地址，节点个数，第几个值反转
	scanf("%d %d %d", &firstAddress, &length, &changeList);
	L->NextAddress = firstAddress;
	L->NextPosition = NULL;

	//创建链表
	L = CreatLinkedList(firstAddress, length, L);

	//将节点链接成链表
	L = SortList(L);
	if (changeList == 1)
	{
		TravalList(L);
		return 0;
	}
	else
	{
		//反转，交换节点的地址
		printf("反转\n");
		L = ReversingList(L, changeList);
		//再次排序
		//L = SortList(L);
		//printf("\n");
		//TravalList(L);
	}
	
	free(L);
	return  0;
}

//反转链表
List ReversingList(List L, int K)
{
	Position PTail;
	int temp = 0;
	int len = 0;
	int times = 0;

	PTail = L;
	len = LengthList(L);
	
	//如果K超过了链表的长度
	if (K == 1)
	{
		return L;
	}
	else if (K >= len)
	{
		PTail = L->NextPosition;
		while (PTail->NextPosition != NULL)
		{
			temp = PTail->Address;
			PTail = PTail->NextPosition;
			PTail->NextAddress = temp;
		}

		L->NextAddress = PTail->Address;
		L->NextPosition->NextAddress = -1;
	}
	else
	{
		//还需加上每隔k个值反转一次
		times = len / K;

		for (int j = 0; j < times; j++)
		{
			for (int i = 1; i < K; i++)
			{
				PTail = PTail->NextPosition;
				temp = PTail->Address;
				PTail->NextPosition->NextAddress = temp;

				//交换完前面的地址值后，再换第一个和最后一个的地址值
#if 0
				if (i == K - 1)
				{
					PTail = PTail->NextPosition;
					L->NextAddress = PTail->Address;
					L->NextPosition->NextAddress = PTail->NextPosition->Address;
				}
#endif		
			}
		}
		TravalList(L);
	}
	return L;
}

//求链表深度
int LengthList(List L)
{
	int count = 0;
	Position PTail;

	PTail = L;
	while (PTail->NextPosition != NULL)
	{
		count++;
		PTail = PTail->NextPosition;
	}

	return count;
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

	if (1 == LengthList(L))
		return L;

	while ( HeadAddress != -1 && PTail->NextPosition != NULL)
	{	
		PTail = PTail->NextPosition;
		if (HeadAddress == PTail->Address)						//如果节点对应的是尾结点的下个一地址
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
	}

	free(L);												   //释放多余节点的空间
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
	printf("%05d %d %d", P->Address, P->Data, P->NextAddress);
	//printf("\n");
}