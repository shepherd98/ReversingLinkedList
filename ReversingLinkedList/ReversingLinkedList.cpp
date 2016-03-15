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

	//�����׵�ַ���ڵ�������ڼ���ֵ��ת
	scanf("%d %d %d", &firstAddress, &length, &changeList);
	L->NextAddress = firstAddress;
	L->NextPosition = NULL;

	//��������
	L = CreatLinkedList(firstAddress, length, L);

	//���ڵ����ӳ�����
	L = SortList(L);
	if (changeList == 1)
	{
		TravalList(L);
		return 0;
	}
	else
	{
		//��ת�������ڵ�ĵ�ַ
		printf("��ת\n");
		L = ReversingList(L, changeList);
		//�ٴ�����
		//L = SortList(L);
		//printf("\n");
		//TravalList(L);
	}
	
	free(L);
	return  0;
}

//��ת����
List ReversingList(List L, int K)
{
	Position PTail;
	int temp = 0;
	int len = 0;
	int times = 0;

	PTail = L;
	len = LengthList(L);
	
	//���K����������ĳ���
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
		//�������ÿ��k��ֵ��תһ��
		times = len / K;

		for (int j = 0; j < times; j++)
		{
			for (int i = 1; i < K; i++)
			{
				PTail = PTail->NextPosition;
				temp = PTail->Address;
				PTail->NextPosition->NextAddress = temp;

				//������ǰ��ĵ�ֵַ���ٻ���һ�������һ���ĵ�ֵַ
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

//���������
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

//��������
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

//����������
List SortList(List L)
{
	Position PTail;
	Position PNewTail;
	Position TempCell;
	List NewList;
	int HeadAddress;
	int TailAddress;

	NewList = (List)malloc(sizeof(struct Node));//Ϊ�µ��������ռ�
	NewList->NextPosition = NULL;

	PNewTail = NewList;							
	HeadAddress = L->NextAddress;				//����׽ڵ�ĵ�ַ
	PTail = L;

	if (1 == LengthList(L))
		return L;

	while ( HeadAddress != -1 && PTail->NextPosition != NULL)
	{	
		PTail = PTail->NextPosition;
		if (HeadAddress == PTail->Address)						//����ڵ��Ӧ����β�����¸�һ��ַ
		{
			TempCell = (Position)malloc(sizeof(struct Node));
			//���ýڵ���ӵ��µ�����
			TempCell = PTail;									
			HeadAddress = TempCell->NextAddress;				//��һ����ַ��Ϊͷ��ַ
			PNewTail->NextPosition = TempCell;
			PNewTail = TempCell;

			DeletePosition(L, PTail->Data);
			TempCell->NextPosition = NULL;
			
			PTail = L;											//ÿ�ҵ�һ���ڵ㣬��λ�������ָ��
		}	
	}

	free(L);												   //�ͷŶ���ڵ�Ŀռ�
	return NewList;
}

//�˴�ɾ�������ͷű�ɾ���ڵ�Ŀռ䣬��Ϊ��ɾ���Ľڵ㱻���õ����µ�����
void DeletePosition(List L, int Data)
{
	Position P, TempCell;

	P = FindPeriousPosition(L, Data);

	TempCell = P->NextPosition;
	P->NextPosition = TempCell->NextPosition;
	//free(TempCell);	
}

//�ҳ���ɾ���ڵ����һ���ڵ�
Position FindPeriousPosition(List L, int Data)
{
	Position PPerious;

	PPerious = L;
	
	while (PPerious->NextPosition != NULL && PPerious->NextPosition->Data != Data)
		PPerious = PPerious->NextPosition;

	return PPerious;
}

//��������
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