#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DBLinkNodeDataType;

/// <summary>
/// 双向带头循环链表
/// </summary>
typedef struct DoublyLinkListNode {

	DBLinkNodeDataType data;

	struct DoublyLinkListNode* prev;
	struct DoublyLinkListNode* next;
}DBLinkNode;

DBLinkNode* DBLinkListInit();
void DBLinkCycleListPushBack(DBLinkNode* pHead, DBLinkNodeDataType data);
void DBLinkCycleListPushFront(DBLinkNode* pHead, DBLinkNodeDataType data);
void DBLinkCycleListPopBack(DBLinkNode* pHead);
void DBLinkCycleListPopFront(DBLinkNode* pHead);

void DBLinkCycleListPrint(DBLinkNode* pHead);