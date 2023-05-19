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

void SingleListPrintOneNode(const SLNode* pNode)
{
	if (pNode)
		printf("%d\n", pNode->data);
	else
		printf("\nThe Node is Not have\n");
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

	SLNode* current = *ppList, * previous = current;

	//�����޽ڵ�ʱ����
	if (!current)
		return;

	//��������һ���ڵ�ʱlast�ڵ���ڵ�ǰ�ڵ㣬��ǰ�ڵ���Ϊ��һ���ڵ㣬�ͷ�last�ڵ�
	while(current->next)
	{
		previous = current;
		current = current->next;
		free(previous);
		previous = NULL;
	}
	//�ͷ�β���ڵ�
	free(current);
	*ppList = NULL;
}

SLNode* SingleListReverseList(SLNode* pList)
{
	//���������Ч��
	//��ͷ����,��������
	SLNode* current = pList, * previous = NULL;
	SLNode* ret = NULL;

	//������ʱ����NULL
	//����ֻ��һ���ڵ�ʱֻ��previous����Ϊ�ýڵ� 

	while (current)
	{
		//��ȡ��ǰλ
		SLNode* tmpNode = current;
		//��ǰλ����
		current = current->next;
		//��ǰλ(���)����һλָ����һλ(���) | ��ת
		tmpNode->next = previous;
		//��һλ(���)����
		previous = tmpNode;
	}
	//���һ��previous����ԭ����β��Ҳ���µ�����ͷ
	ret = previous;
	return ret;
}

SLNode* SingleListMiddleNode(const SLNode* pList)
{
	//�����м�ڵ㣬���������м�ڵ㣬�򷵻صڶ����м�ڵ�

	//���������Ч��
	//ʹ�ÿ���ָ�룬�ٶ�Ϊ2:1 | fast:slow

	assert(pList);

	SLNode* pSlow = pList, *pFast = pList;

	//while (pFast)
	//{
	//	pFast = pFast->next;
	//	if (!pFast)
	//		break;
	//	pFast = pFast->next;
	//	pSlow = pSlow->next;
	//}

	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}

SLNode* SingleListFindKthToTail(SLNode* pList, size_t k)
{
	//���������Ч��
	//����ָ�룬fast����slow K ��
	//�ҵ����ص�ַ���Ҳ�������NULL(K���Ϸ�)

	if (!(pList && k))
	{
		return NULL;
	}

	SLNode* pFast = pList, * pSlow = pList;

	while (pFast)
	{
		if (k > 0)
			k--;
		else
			pSlow = pSlow->next;
		pFast = pFast->next;
	}
	if (k > 0)
		return NULL;
	return pSlow;
}

SLNode* SingleListMergeTowList(SLNode* pL1, SLNode* pL2)
{
	//�ϲ�������������
	//����

#define SENTINEL

#undef SNETINEL

#ifdef SENTINEL
	//���ڱ�λ
	//���������Ч��
	//ѭ���Ա�����������Ԫ�ز�����
	//����β������
	//�����ڱ����ص�����

	//ֻ��һ��������Чʱ���ظ�����������ʱ����NULL
	SLNode sentinel = { 0 };
	SLNode* tail = &sentinel;

	if (!pL1)
		return pL2;
	if (!pL2)
		return pL1;

	while (pL1 && pL2)
	{
		SLNode* tmpNode = NULL;

		//˭С˭����
		if (pL1->data < pL2->data)
		{
			tmpNode = pL1;
			pL1 = pL1->next;
		}
		else
		{
			tmpNode = pL2;
			pL2 = pL2->next;
		}
		tail->next = tmpNode;
		tail = tail->next;
	}
	//����β�����������
	if (pL1)
		tail->next = pL1;
	else
		tail->next = pL2;

	return sentinel.next;
#else
	//�����ڱ�λ
	//���������Ч��
	//ѭ���Ա������������Ч����
	//����β��ʣ������

	SLNode* newHead = NULL, * tail = NULL;

	//ֻ��һ��������Чʱ���ظ�����������ʱ����NULL
	if (!pL1)
		return pL2;
	if (!pL2)
		return pL1;

	while (pL1 && pL2)
	{
		SLNode* tmpNode = NULL;
		if (pL1->data < pL2->data)
		{
			tmpNode = pL1;
			pL1 = pL1->next;
		}
		else
		{
			tmpNode = pL2;
			pL2 = pL2->next;
		}
		//��һ���ж�ʱ�����±�
		if (!newHead)
			newHead = tail = tmpNode;
		else
			tail->next = tmpNode;
		tail = tmpNode;
	}
	//β����������
	if (pL1)
		tail->next = pL1;
	else if (pL2)
		tail->next = pL2;
	return newHead;
#endif
}

SLNode* SingleListPartition(SLNode* pList, int x)
{
	//��������С��X��ֵ����ǰ�����ڵ���X��ֵ���ں󣬲������µ�����ͷ
	//Ҫ��ԭ���˳�򲻱�
	
	//���������Ч��
	//�����������ڱ�λ������
	//��ѭ����������
	//dataС��X�Ľڵ����sentinel1����ڵ���X�Ľڵ����sentinel2��
	//ѭ����������sen1��sen2��sen2��ĩβ�ÿգ�����sen1���صĽڵ�

	SLNode* sen1Head, * sen1Tail, * sen2Head, * sen2Tail;
	SLNode* current = pList;
	SLNode sentinel1 = { 0 }, sentinel2 = { 0 };

	sen1Head = sen1Tail = &sentinel1;
	sen2Head = sen2Tail = &sentinel2;

	while (current)
	{
		//�ڵ����
		if (current->data < x)
		{
			sen1Tail->next = current;
			sen1Tail = current;
		}
		else
		{
			sen2Tail->next = current;
			sen2Tail = current;
		}

		//current����
		current = current->next;
	}

	//��β����
	//����1��β�ڵ���2���ص�ͷ�ڵ�,2��β�ڵ��ÿ�
	sen1Tail->next = sen2Head->next;
	sen2Tail->next = NULL;
	
	return sen1Head->next;
}

unsigned char SingleListCheckPalindrom(SLNode* pList)
{
	//���pList�Ƿ���Ľṹ��������ֵ��ʱ�临�Ӷ�O(N),�ռ临�ӵ�O(1)

	//���������Ч��
	//�õ��м�ڵ㣬���м�ڵ㿪ʼ����
	//��һ�Ա��Ƿ���ͬ
	//�������������ؽ��

	assert(pList);

	unsigned char ret = 1;
	SLNode* pListBack = SingleListMiddleNode(pList);
	SLNode* currentFront = pList, * currentBack = pListBack;

	pListBack = SingleListReverseList(pListBack);

	while (currentBack)
	{
		if (currentFront->data != currentBack->data)
			//�в�ͬʱ��Ϊ0���뿪ѭ��ʱ�������������ؽ��
			ret = 0;
		currentFront = currentFront->next;
		currentBack = currentBack->next;
	}
	SingleListReverseList(pListBack);
	return ret;
}

SLNode* SingleListFindTail(SLNode* pList)
{
	assert(pList);

	while (pList->next)
	{
		pList = pList->next;
	}
	return pList;
}

SLNode* SingleListGetIntersectionNode(SLNode* headA, SLNode* headB)
{

	//�ж����������Ƿ��ཻ�����ཻ�򷵻��ཻ��ĵ�ַ�����򷵻�NULL

	//�ж�������Ч��
	//��β�������������������
	//��β��ַ��ͬ���޽���
	//��β��ͬ���н���
	//���������ȵ�������ͬʱ����
	//next��ͬʱ���ҵ�����

	if (!(headA && headB))
		return NULL;

	char dir = '\0';
	size_t gap = 0;

	SLNode* tailA = headA, * tailB = headB;
	SLNode* longList = NULL, * shortList = NULL;
	SLNode* pListTailA = headA, * pListTailB = headB;

	while (tailA || tailB)
	{
		//����һ���ߵ�ͷ��ʼ�����ֱ࣬���������ߵ�ͷ����
		if (!(tailA && tailB))
			gap++;

		if (tailA)
		{
			if (tailA->next)
				pListTailA = tailA;
			tailA = tailA->next;
			dir = 'A';
		}
		if (tailB)
		{
			if (tailB->next)
				pListTailB = tailB;
			tailB = tailB->next;
			dir = 'B';
		}
	}
	//�޽�β���޽ڵ��ཻ
	if (pListTailA != pListTailB)
		return NULL;

	//ͬ������ʱĬ��B��
	switch (dir)
	{
	case 'A':
		longList = headA;
		shortList = headB;
		break;
	case 'B':
		longList = headB;
		shortList = headA;
		break;
	}

	//ͳһ������
	while (gap--)
	{
		longList = longList->next;
	}

	//ͬ��������ֱ����ͬ
	while (longList)
	{
		if (longList->next == shortList->next)
			return longList->next;
		longList = longList->next;
		shortList = shortList->next;
	}
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

void SingleListInsertAfter(SLNode* position, SingleListDataType data)
{
	//���pos��Ч��
	//�����ڵ㲢������һ���ڵ�
	//����pos�ڵ���new�ڵ�

	assert(position);

	SLNode* newNode = NULL;
	if (!(newNode = (SLNode*)malloc(sizeof(SLNode))))
	{
		perror("");
		return;
	}
	newNode->data = data;
	newNode->next = position->next;
	position->next = newNode;
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

void SingleListEraseAfter(SLNode* position)
{
	//���pos��Ч��
	//�����ɾ���ڵ���Ч��
	//��������ڵ�
	//ɾ���ڵ�
	assert(position);

	SLNode* eraseNode = position->next;
	if (!eraseNode)
	{
		printf("Erase Node is NULL\n");
		return;
	}
	position->next = eraseNode->next;
	free(eraseNode);
	eraseNode = NULL;
}

SLNode* SingleListRemoveElments(SLNode* head, SingleListDataType val)
{
	//���head��Ч��
	//��һ�Ա�val��head->data
	//��ͬ��ɾ���ڵ㲢�������½ڵ�

	if (!head)
		return (SLNode*)NULL;

	SLNode* current = head, * pervious = NULL;
	SLNode* ret = head;

	while (current)
	{
		if (current->data == val)
		{
			SLNode* tmpD = current;
			if (pervious)
				//��ͷ�ڵ�����
				pervious->next = current->next;
			else
				//ͷ�ڵ�����
				ret = current->next;
			//ָ�����0���ͷ�ԭָ��λ�õĿռ�
			current = current->next;
			free(tmpD);
		}
		else
		{
			//ָ�����
			pervious = current;
			current = current->next;
		}
	}

	return ret;
}
#pragma endregion