#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SingleListDataType;

typedef struct SingleListNode {
	SingleListDataType data;
	struct SingleListNode* next;

}SLNode;

void SingleListPrint(const SLNode* pList);
int SingleListFind(const SLNode* pList, SingleListDataType src);
void SingleListDestroy(SLNode** ppList);

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