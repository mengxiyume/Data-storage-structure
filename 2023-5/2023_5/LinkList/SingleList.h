#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SingleListDataType;

typedef struct SingleListNode {
	SingleListDataType data;
	struct SingleListNode* next;

}SLNode;

typedef struct SingleListNode_Random {
	SingleListDataType value;
	struct SingleListNode_Random* random;
	struct SingleListNode_Random* next;

}SLNode_Random;

void SingleListPrint(const SLNode* pList);
void SingleListPrintOneNode(const SLNode* pNode);
int SingleListFind(const SLNode* pList, SingleListDataType src);
void SingleListDestroy(SLNode** ppList);
SLNode* SingleListReverseList(SLNode* pList);
SLNode* SingleListMiddleNode(const SLNode* pList);
SLNode* SingleListFindKthToTail(SLNode* pList, size_t k);
SLNode* SingleListMergeTowList(SLNode* pL1, SLNode* pL2);
SLNode* SingleListFindTail(SLNode* pList);
SLNode* SingleListPartition(SLNode* pList, int x);
unsigned char SingleListCheckPalindrom(SLNode* pList);
SLNode* SingleListGetIntersectionNode(SLNode* headA, SLNode* headB);
unsigned char SingleListHasCycle(SLNode* pList);
SLNode* SingleListDetectCycle(SLNode* pList);
SLNode_Random* SingleListCopyRandomList(SLNode_Random* pList);
void SingleListRandomPushBack(SLNode_Random * *ppList, SingleListDataType data);
void SingleListRandomPrint(const SLNode_Random* pList);

#pragma region Push
void SingleListPushBack(SLNode** ppList, SingleListDataType data);
void SingleListPushFront(SLNode** ppList, SingleListDataType data);
void SingleListInsert(SLNode** ppList, int position, SingleListDataType data);
void SingleListInsertAfter(SLNode* position, SingleListDataType data);
#pragma endregion

#pragma region Pop
void SingleListPopBack(SLNode** ppList);
void SingleListPopFront(SLNode** ppList);
void SingleListErase(SLNode** ppList, int position);
void SingleListEraseAfter(SLNode* position);
SLNode* SingleListRemoveElments(SLNode* head, SingleListDataType val);
#pragma endregion