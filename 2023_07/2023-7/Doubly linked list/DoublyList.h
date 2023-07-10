#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DBLinkNodeDataType;

/// <summary>
/// 双向带头循环链表节点
/// </summary>
typedef struct DoublyLinkListNode {

	DBLinkNodeDataType data;

	struct DoublyLinkListNode* prev;
	struct DoublyLinkListNode* next;
}DBLinkNode;

DBLinkNode* BuyDBLinkListNode(DBLinkNodeDataType data);
DBLinkNode* DBLinkCycleListInit();
DBLinkNode* DBLinkCycleListFind(DBLinkNode* pHead, DBLinkNodeDataType findData);
void DBLinkCycleListPushBack(DBLinkNode* pHead, DBLinkNodeDataType data);
void DBLinkCycleListPushFront(DBLinkNode* pHead, DBLinkNodeDataType data);
void DBLinkCycleListPopBack(DBLinkNode* pHead);
void DBLinkCycleListPopFront(DBLinkNode* pHead);
void DBLinkCycleListInsert(DBLinkNode* pos, DBLinkNodeDataType data);
void DBLinkCycleListErase(DBLinkNode* pos);

void DBLinkCycleListPrint(DBLinkNode* pHead);