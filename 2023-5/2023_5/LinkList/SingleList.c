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

	SLNode* current = *ppList, * last = current;

	//链表无节点时返回
	if (!current)
		return;

	//链表有下一个节点时last节点等于当前节点，当前节点变更为下一个节点，释放last节点
	while(current->next)
	{
		last = current;
		current = current->next;
		free(last);
		last = NULL;
	}
	//释放尾部节点
	free(current);
	*ppList = NULL;

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
#pragma endregion