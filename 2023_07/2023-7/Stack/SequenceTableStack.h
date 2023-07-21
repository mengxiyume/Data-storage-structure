#pragma once

#include"IncludeLib.h"

typedef int SequenceTableStackDataType;
typedef SequenceTableStackDataType STSDataType;

typedef struct SequenceTableStack {
	STSDataType* arrData;
	int top;
	int capacity;
}STStack;

void STStackInit(STStack* ps);
void STStackDestroy(STStack* ps);
void STStackPush(STStack* ps, STSDataType data);
void STStackPop(STStack* ps);
STSDataType STStackTop(STStack* ps);
int STStackSize(STStack* ps);
BOOL STStackEmpty(STStack* ps);
void STStackPrint(STStack* ps);