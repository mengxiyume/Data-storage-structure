#define _CRT_SECURE_NO_WARNINGS

#include"SingleList.h"

void SingleListPrint(const SLNode* pList)
{
	SLNode* pData = pList;

	if (!pList)
	{
		printf("Is NULL list\n");
		return;
	}
	while (pData)
	{
		printf(" %d ->", pData->data);
		pData = pData->next;
	}
	printf(" NULL\n");
}

int SingleListFind(const SLNode* pList, SingleListDataType src)
{
	//���������Ч��
	//�Ա�pFind->data ��src
	//��ͬ�򷵻��±�
	//δ������Ŀ���򷵻�-1

	assert(pList);

	SLNode* pFind = pList;
	int subscript = 0;

	while (pFind)
	{
		if (pFind->data == src)
		{
			return subscript;
		}

		pFind = pFind->next;
		subscript++;
	}
	return -1;
}

void SingleListDestroy(SLNode** ppList)
{
	//���������Ч��
	//�õ��ں�һ���ڵ㣬�ͷŵ�ǰ�ڵ�
	//��β��ʱ�ͷ�β���ڵ�

	assert(ppList);

	SLNode* current = *ppList, * last = current;

	//�����޽ڵ�ʱ����
	if (!current)
		return;

	//��������һ���ڵ�ʱlast�ڵ���ڵ�ǰ�ڵ㣬��ǰ�ڵ���Ϊ��һ���ڵ㣬�ͷ�last�ڵ�
	while(current->next)
	{
		last = current;
		current = current->next;
		free(last);
		last = NULL;
	}
	//�ͷ�β���ڵ�
	free(current);
	*ppList = NULL;

}

#pragma region Push
void SingleListPushBack(SLNode** ppList, SingleListDataType data)
{
	//���pList��Ч��
	//���������򴴽�����
	//����β�ڵ�
	//�����µ�β�ڵ�

	assert(ppList);

	SLNode* tail = *ppList, * newNode = NULL;

	if (!tail)
	{
		if (newNode = (SLNode*)malloc(sizeof(SLNode)))
		{
			*ppList = newNode;

			newNode->data = data;
			newNode->next = NULL;
		}
		return;
	}

	while (tail->next)

	{
		tail = tail->next;
	}

	if (newNode = (SLNode*)malloc(sizeof(SLNode)))
	{
		tail->next = newNode;

		newNode->data = data;
		newNode->next = NULL;
	}
}

void SingleListPushFront(SLNode** ppList, SingleListDataType data)
{
	//���pList��Ч��
	//����ͷ�ڵ�
	//���������򴴽�����
	//����ͷ�ڵ�

	assert(ppList);

	SLNode* newNode = NULL;

	//����ʧ�����뿪���ɹ���������ݶ�
	if (newNode = (SLNode*)malloc(sizeof(SLNode)))
	{
		newNode->data = data;
	}
	else
	{
		printf("malloc Error NULL\n");
		return;
	}
	//�������򴴽�����������������������ͷ�ڵ��������ͷ�ڵ�
	if (!*ppList)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *ppList;
	}
	//����ͷ�ڵ����*ppList
	*ppList = newNode;


}

void SingleListInsert(SLNode** ppList, int position, SingleListDataType data)
{
	//���������Ч��
	//�����ڵ㣬��������data
	//�ҵ���Pos���ڵ��ǰһ���ڵ�
	//���ӽڵ�

	assert(ppList);

	int i = 0;

	SLNode* current = *ppList, * last = NULL;
	SLNode* tmpNode = NULL;

	if (position < 0)
	{
		printf("The position is NULL\n");
		return;
	}

	//�ռ俪�ټ�����¼��
	if (!(tmpNode = (SLNode*)malloc(sizeof(SLNode))))
	{
		return;
	}
	tmpNode->data = data;


	//�ҵ�ָ��Node
	for (i = 0; i < position; i++)
	{
		if (!current)
		{
			printf("The position is NULL\n");
			return;
		}
		last = current;
		current = current->next;
	}
	tmpNode->next = current;
	if (last)
		//�м�λ�ò���
		last->next = tmpNode;
	else
		//ͷ��λ�ò��� pos == 0
		*ppList = tmpNode;

}
#pragma endregion

#pragma region Pop
void SingleListPopBack(SLNode** ppList)
{
	//���������Ч��
	//�ҵ�����β
	//ɾ������β

	assert(ppList);

	SLNode* tail = *ppList;

	//û������ʱ������
	if (!tail)
	{
		return;
	}
	//��β��ǰһ��
	while (tail->next && tail->next->next)
	{
		tail = tail->next;
	}
	//�����������������Ͻڵ�ʱɾ��β�ڵ�
	//����������ֻ��һ���ڵ�ʱɾ�� ͷ��β���ڵ㣬������*ppList
	if (tail->next)
	{
		free(tail->next);
		tail->next = NULL;
	}
	else
	{
		free(tail);
		*ppList = NULL;
	}
}

void SingleListPopFront(SLNode** ppList)
{
	//���������Ч��
	//ɾ��ͷ�ڵ�

	assert(ppList);

	SLNode* pHead = *ppList, * newHead = NULL;

	//�������򲻽��в���
	if (!pHead)
	{
		return;
	}

	//�����������Ͻڵ�ʱ���õ��ڶ����ڵ�ĵ�ַ����ɾ����һ���ڵ㣬�ı�*ppList
	//����ֻ��һ���ڵ�ʱ��ɾ��ͷ(β)�ڵ㣬���ı�*ppList
	if (pHead->next)
	{
		newHead = pHead->next;
	}
	free(pHead);
	*ppList = newHead;

}

void SingleListErase(SLNode** ppList, int position)
{
	//���������Ч��
	//���Pos�Ƿ����
	//�ҵ�Pos�ڵ�ǰһ���ڵ����һ���ڵ�
	//ɾ��Pos�ڵ�
	//���ӽڵ�

	assert(ppList);

	int i = 0;
	SLNode* current = *ppList, * last = NULL;

	//�������Pos���Ϸ�����
	if (!*ppList || position < 0)
	{
		printf("The position is NULL\n");
		return;
	}

	//Ѱ�ҵ�Pos���ڵ�
	for (i = 0; i < position; i++)
	{
		if (!current)
		{
			printf("The position is NULL\n");
			return;
		}
		last = current;
		current = current->next;
	}
	if (last)
	{
		//Pos>0�ҺϷ�
		last->next = current->next;
	}
	else
	{
		//Pos=0
		*ppList = current->next;
	}
	free(current);
}
#pragma endregion