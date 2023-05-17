#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define SEQ_LIST_INCREASE 2
#define SEQ_LIST_CAPACITY_BASE 4


typedef int SeqListDataType;

typedef struct SeqList {

	SeqListDataType* data;
	int size;
	int capacity;

}SL;

typedef enum EnumMenuSelect {
	Exit, PushFront, PushBack,
	PopFront, PopBack,
	PrintList, FindData,
	PushInsert, Erase
}EnumMenuSelect;

void SeqListMenu(SL* pSeqList);
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPrint(SL* pSeqList);
void SeqListCheckCapacity(SL* pSeqList);
int SeqListFind(SL* sourse, SeqListDataType* data, unsigned char Contrastf(SeqListDataType* d1, SeqListDataType* d2));
unsigned char SeqListDataTypeContrastf(SeqListDataType* d1, SeqListDataType* d2);

#pragma region Push
void SeqListPushBack(SL* pSeqList, SeqListDataType* data);
void SeqListPushFront(SL* pSeqList, SeqListDataType* data);
void SeqListInsert(SL* pSeqList, int position, SeqListDataType* data);
#pragma endregion

#pragma region Pop
void SeqListPopBack(SL* pSeqList);
void SeqListPopFront(SL* pSeqList);
void SeqListErase(SL* pSeqList, int position);
#pragma endregion