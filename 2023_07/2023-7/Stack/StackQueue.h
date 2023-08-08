#pragma once

#include"SequenceTableStack.h"

typedef struct {
	STStack* pushSTStack;
	STStack* popSTStack;
}SQueue;

SQueue* StackQueueCreate();
void StackQueueDestroy(SQueue* stacks);
void SQueuePush(SQueue* stacks, STSDataType x);
STSDataType SQueuePop(SQueue* stacks);
STSDataType SQueueTop(SQueue* stacks);
BOOL SQueueEmpty(SQueue* stacks);