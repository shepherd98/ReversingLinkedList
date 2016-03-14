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

	//free(PNew);
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

	while ( HeadAddress != -1)
	{	
		if (HeadAddress == PTail->Address)		//����ڵ��Ӧ����β�����¸�һ��ַ
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
		
		PTail = PTail->NextPosition;
	}

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
	printf("%05d %d %d\n", P->Address, P->Data, P->NextAddress);
	printf("\n");
}