#define _CRT_SECURE_NO_WARNINGS

#include"DoublyList.h"

/// <summary>
/// 双向带头循环链表
/// </summary>
/// <param name="pHead"></param>
DBLinkNode* DBLinkCycleListInit()
{
	DBLinkNode* pHead = (DBLinkNode*)malloc(sizeof(DBLinkNode));
	assert(pHead);

	pHead->prev = pHead;
	pHead->next = pHead;

	return pHead;
}

DBLinkNode* DBLinkCycleListFind(DBLinkNode* pHead, DBLinkNodeDataType findData)
{
	assert(pHead);

	DBLinkNode* cur = pHead->next;

	while (cur != pHead)
	{
		if (cur->data == findData)
			return cur;	//找到之后返回数据所在节点指针
		cur = cur->next;
	}
	return NULL;	//没找到返回NULL
}

DBLinkNode* BuyDBLinkListNode(DBLinkNodeDataType data)
{
	DBLinkNode* newNode = (DBLinkNode*)malloc(sizeof(DBLinkNode));
	assert(newNode);
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void DBLinkCycleListPushBack(DBLinkNode* pHead, DBLinkNodeDataType data)
{
	assert(pHead);

	//DBLinkNode* tailNode = pHead->prev;

	//DBLinkNode* newNode = BuyDBLinkListNode(data);

	//tailNode->next = newNode;
	//newNode->prev = tailNode;
	//newNode->next = pHead;
	//pHead->prev = newNode;

	DBLinkCycleListInsert(pHead, data);
}

void DBLinkCycleListPushFront(DBLinkNode* pHead, DBLinkNodeDataType data)
{
	assert(pHead);

	//DBLinkNode* firstNode = pHead->next;

	//DBLinkNode* newNode = BuyDBLinkListNode(data);

	//newNode->prev = pHead;
	//newNode->next = firstNode;
	//firstNode->prev = newNode;
	//pHead->next = newNode;

	DBLinkCycleListInsert(pHead->next, data);
}

void DBLinkCycleListPopBack(DBLinkNode* pHead) 
{
	assert(pHead);

	if (pHead->prev == pHead)
	{
		return;
	}

	//DBLinkNode* newTail = pHead->prev->prev;

	//newTail->next = pHead;
	//free(pHead->prev);
	//pHead->prev = newTail;

	DBLinkCycleListErase(pHead->prev);
}

void DBLinkCycleListPopFront(DBLinkNode* pHead)
{
	assert(pHead);

	if (pHead->next == pHead)
	{
		return;
	}

	//DBLinkNode* newFirst = pHead->next->next;

	//newFirst->prev = pHead;
	//free(pHead->next);
	//pHead->next = newFirst;

	DBLinkCycleListErase(pHead->next);
}

/// <summary>
/// 在pos前插入
/// </summary>
/// <param name="pos"></param>
/// <param name="data"></param>
void DBLinkCycleListInsert(DBLinkNode* pos, DBLinkNodeDataType data)
{
	DBLinkNode* newNode = BuyDBLinkListNode(data);
	assert(newNode);
	pos->prev->next = newNode;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev = newNode;
}

/// <summary>
/// 删除pos位置的节点
/// </summary>
/// <param name="pos"></param>
void DBLinkCycleListErase(DBLinkNode* pos)
{
	if (pos == pos->next)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

void DBLinkCycleListPrint(DBLinkNode* pHead)
{
	assert(pHead);

	DBLinkNode* curNode = pHead->next;

	if (curNode == pHead)
	{
		printf("The Lint is not have Node\n");
		return;
	}

	printf("head ->");
	while (curNode != pHead)
	{
		printf("%d ->", curNode->data);

		curNode = curNode->next;
	}
	printf("head\n");
}