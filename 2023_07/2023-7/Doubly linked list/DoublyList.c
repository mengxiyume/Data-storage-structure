#define _CRT_SECURE_NO_WARNINGS

#include"DoublyList.h"

/// <summary>
/// 双向带头循环链表
/// </summary>
/// <param name="pHead"></param>
DBLinkNode* DBLinkListInit()
{
	DBLinkNode* pHead = (DBLinkNode*)malloc(sizeof(DBLinkNode));
	assert(pHead);

	pHead->prev = pHead;
	pHead->next = pHead;

	return pHead;
}

void DBLinkCycleListPushBack(DBLinkNode* pHead, DBLinkNodeDataType data)
{
	assert(pHead);

	DBLinkNode* tailNode = pHead->prev;

	DBLinkNode* newNode = (DBLinkNode*)malloc(sizeof(DBLinkNode));
	assert(newNode);

	newNode->data = data;
	tailNode->next = newNode;
	newNode->prev = tailNode;
	newNode->next = pHead;
	pHead->prev = newNode;

}

void DBLinkCycleListPushFront(DBLinkNode* pHead, DBLinkNodeDataType data)
{
	assert(pHead);

	DBLinkNode* firstNode = pHead->next;

	DBLinkNode* newNode = (DBLinkNode*)malloc(sizeof(DBLinkNode));
	assert(newNode);

	newNode->data = data;
	newNode->prev = pHead;
	newNode->next = firstNode;
	firstNode->prev = newNode;
	pHead->next = newNode;
}

void DBLinkCycleListPopBack(DBLinkNode* pHead) 
{
	assert(pHead);

	if (pHead->prev == pHead)
	{
		return;
	}

	DBLinkNode* newTail = pHead->prev->prev;

	newTail->next = pHead;
	free(pHead->prev);
	pHead->prev = newTail;
}

void DBLinkCycleListPopFront(DBLinkNode* pHead)
{
	assert(pHead);

	if (pHead->next == pHead)
	{
		return;
	}

	DBLinkNode* newFirst = pHead->next->next;

	newFirst->prev = pHead;
	free(pHead->next);
	pHead->next = newFirst;
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