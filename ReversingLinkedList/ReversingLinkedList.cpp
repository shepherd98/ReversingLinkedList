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
	PNewTail = NewList;							
	HeadAddress = L->NextAddress;				//����׽ڵ�ĵ�ַ
	PTail = L;
	//�ҳ�β�ڵ�
	while (PTail->NextPosition != NULL && HeadAddress != -1)
	{
		if (HeadAddress == PTail->NextPosition->Address)		//����ڵ��Ӧ����β�����¸�һ��ַ
		{
			TempCell = (Position)malloc(sizeof(struct Node));
			//���ýڵ���ӵ��µ�����
			TempCell = PTail->NextPosition;
			HeadAddress = TempCell->NextAddress;				//��һ����ַ��Ϊͷ��ַ
			PNewTail->NextPosition = TempCell;
			PTail->NextPosition = TempCell->NextPosition;		//ɾ���ɵĽ��
			TempCell->NextPosition = NULL;
			PNewTail = TempCell;
		}
		
		//
	}

	return NewList;
}

//��������
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