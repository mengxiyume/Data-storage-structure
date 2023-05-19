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
	//检测链表有效性
	//对比pFind->data 与src
	//相同则返回下标
	//未搜索到目标则返回-1

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
	//检测链表有效性
	//拿到第后一个节点，释放当前节点
	//到尾部时释放尾部节点

	assert(ppList);

	SLNode* current = *ppList, * previous = current;

	//链表无节点时返回
	if (!current)
		return;

	//链表有下一个节点时last节点等于当前节点，当前节点变更为下一个节点，释放last节点
	while(current->next)
	{
		previous = current;
		current = current->next;
		free(previous);
		previous = NULL;
	}
	//释放尾部节点
	free(current);
	*ppList = NULL;
}

SLNode* SingleListReverseList(SLNode* pList)
{
	//检查链表有效性
	//从头遍历,反向链接
	SLNode* current = pList, * previous = NULL;
	SLNode* ret = NULL;

	//无链表时返回NULL
	//链表只有一个节点时只将previous设置为该节点 

	while (current)
	{
		//获取当前位
		SLNode* tmpNode = current;
		//当前位迭代
		current = current->next;
		//当前位(落后)的下一位指向上一位(落后) | 翻转
		tmpNode->next = previous;
		//上一位(落后)迭代
		previous = tmpNode;
	}
	//最后一个previous则是原链表尾，也是新的链表头
	ret = previous;
	return ret;
}

SLNode* SingleListMiddleNode(const SLNode* pList)
{
	//返回中间节点，如有两个中间节点，则返回第二个中间节点

	//检测链表有效性
	//使用快慢指针，速度为2:1 | fast:slow

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
	//检测链表有效性
	//快慢指针，fast领先slow K 步
	//找到返回地址，找不到返回NULL(K不合法)

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
	//合并两个有序链表
	//升序

#define SENTINEL

#undef SNETINEL

#ifdef SENTINEL
	//带哨兵位
	//检测链表有效性
	//循环对比两个链表中元素并迭代
	//链接尾部链表
	//返回哨兵看守的链表

	//只有一个链表有效时返回该链表，无链表时返回NULL
	SLNode sentinel = { 0 };
	SLNode* tail = &sentinel;

	if (!pL1)
		return pL2;
	if (!pL2)
		return pL1;

	while (pL1 && pL2)
	{
		SLNode* tmpNode = NULL;

		//谁小谁迭代
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
	//链接尾部多余的链表
	if (pL1)
		tail->next = pL1;
	else
		tail->next = pL2;

	return sentinel.next;
#else
	//不带哨兵位
	//检测链表有效性
	//循环对比两个链表的有效部分
	//链接尾部剩余链表

	SLNode* newHead = NULL, * tail = NULL;

	//只有一个链表有效时返回该链表，无链表时返回NULL
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
		//第一次判断时创建新表
		if (!newHead)
			newHead = tail = tmpNode;
		else
			tail->next = tmpNode;
		tail = tmpNode;
	}
	//尾部残余链接
	if (pL1)
		tail->next = pL1;
	else if (pL2)
		tail->next = pL2;
	return newHead;
#endif
}

SLNode* SingleListPartition(SLNode* pList, int x)
{
	//将链表中小于X的值放在前，大于等于X的值放在后，并返回新的链表头
	//要求原相对顺序不变
	
	//检测链表有效性
	//创建两个带哨兵位的链表
	//用循环遍历链表
	//data小于X的节点放在sentinel1里，大于等于X的节点放在sentinel2里
	//循环结束链接sen1与sen2，sen2的末尾置空，返回sen1看守的节点

	SLNode* sen1Head, * sen1Tail, * sen2Head, * sen2Tail;
	SLNode* current = pList;
	SLNode sentinel1 = { 0 }, sentinel2 = { 0 };

	sen1Head = sen1Tail = &sentinel1;
	sen2Head = sen2Tail = &sentinel2;

	while (current)
	{
		//节点放置
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

		//current迭代
		current = current->next;
	}

	//结尾处理
	//链接1的尾节点与2看守的头节点,2的尾节点置空
	sen1Tail->next = sen2Head->next;
	sen2Tail->next = NULL;
	
	return sen1Head->next;
}

unsigned char SingleListCheckPalindrom(SLNode* pList)
{
	//检查pList是否回文结构，返回真值，时间复杂度O(N),空间复杂的O(1)

	//检测链表有效性
	//拿到中间节点，从中间节点开始倒置
	//逐一对比是否相同
	//重链接链表并返回结果

	assert(pList);

	unsigned char ret = 1;
	SLNode* pListBack = SingleListMiddleNode(pList);
	SLNode* currentFront = pList, * currentBack = pListBack;

	pListBack = SingleListReverseList(pListBack);

	while (currentBack)
	{
		if (currentFront->data != currentBack->data)
			//有不同时置为0，离开循环时重链接链表，返回结果
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

	//判断两个链表是否相交，如相交则返回相交点的地址，否则返回NULL

	//判断链表有效性
	//找尾并计算出两链表相差距离
	//如尾地址不同则无交点
	//如尾相同则有交点
	//长的链表先迭代，再同时迭代
	//next相同时则找到交点

	if (!(headA && headB))
		return NULL;

	char dir = '\0';
	size_t gap = 0;

	SLNode* tailA = headA, * tailB = headB;
	SLNode* longList = NULL, * shortList = NULL;
	SLNode* pListTailA = headA, * pListTailB = headB;

	while (tailA || tailB)
	{
		//其中一个走到头开始计算差距，直到两个都走到头结束
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
	//无交尾则无节点相交
	if (pListTailA != pListTailB)
		return NULL;

	//同样长度时默认B长
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

	//统一链表长度
	while (gap--)
	{
		longList = longList->next;
	}

	//同步迭代，直到相同
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
	//检测pList有效性
	//如无链表则创建链表
	//来到尾节点
	//插入新的尾节点

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
	//检测pList有效性
	//创建头节点
	//如无链表则创建链表
	//插入头节点

	assert(ppList);

	SLNode* newNode = NULL;

	//创建失败则离开，成功则填充数据段
	if (newNode = (SLNode*)malloc(sizeof(SLNode)))
	{
		newNode->data = data;
	}
	else
	{
		printf("malloc Error NULL\n");
		return;
	}
	//无链表则创建链表，有链表则链接新链表头节点与旧链表头节点
	if (!*ppList)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *ppList;
	}
	//将新头节点给到*ppList
	*ppList = newNode;


}

void SingleListInsert(SLNode** ppList, int position, SingleListDataType data)
{
	//检测链表有效性
	//创建节点，插入数据data
	//找到第Pos个节点的前一个节点
	//链接节点

	assert(ppList);

	int i = 0;

	SLNode* current = *ppList, * last = NULL;
	SLNode* tmpNode = NULL;

	if (position < 0)
	{
		printf("The position is NULL\n");
		return;
	}

	//空间开辟及数据录入
	if (!(tmpNode = (SLNode*)malloc(sizeof(SLNode))))
	{
		return;
	}
	tmpNode->data = data;


	//找到指定Node
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
		//中间位置插入
		last->next = tmpNode;
	else
		//头部位置插入 pos == 0
		*ppList = tmpNode;

}

void SingleListInsertAfter(SLNode* position, SingleListDataType data)
{
	//检查pos有效性
	//创建节点并链接下一个节点
	//链接pos节点与new节点

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
	//检测链表有效性
	//找到链表尾
	//删除链表尾

	assert(ppList);

	SLNode* tail = *ppList;

	//没有链表时不操作
	if (!tail)
	{
		return;
	}
	//找尾的前一个
	while (tail->next && tail->next->next)
	{
		tail = tail->next;
	}
	//当链表有两个及以上节点时删除尾节点
	//当链表有且只有一个节点时删除 头（尾）节点，并更改*ppList
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
	//检测链表有效性
	//删除头节点

	assert(ppList);

	SLNode* pHead = *ppList, * newHead = NULL;

	//无链表则不进行操作
	if (!pHead)
	{
		return;
	}

	//有两个及以上节点时，拿到第二个节点的地址，并删除第一个节点，改变*ppList
	//有且只有一个节点时，删除头(尾)节点，并改变*ppList
	if (pHead->next)
	{
		newHead = pHead->next;
	}
	free(pHead);
	*ppList = newHead;

}

void SingleListErase(SLNode** ppList, int position)
{
	//检测链表有效性
	//检测Pos是否存在
	//找到Pos节点前一个节点与后一个节点
	//删除Pos节点
	//链接节点

	assert(ppList);

	int i = 0;
	SLNode* current = *ppList, * last = NULL;

	//无链表或Pos不合法返回
	if (!*ppList || position < 0)
	{
		printf("The position is NULL\n");
		return;
	}

	//寻找第Pos个节点
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
		//Pos>0且合法
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
	//检测pos有效性
	//检测需删除节点有效性
	//链接两侧节点
	//删除节点
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
	//检查head有效性
	//逐一对比val与head->data
	//相同则删除节点并链接上下节点

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
				//非头节点链接
				pervious->next = current->next;
			else
				//头节点链接
				ret = current->next;
			//指针迭代0，释放原指针位置的空间
			current = current->next;
			free(tmpD);
		}
		else
		{
			//指针迭代
			pervious = current;
			current = current->next;
		}
	}

	return ret;
}
#pragma endregion