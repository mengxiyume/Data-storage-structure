#define _CRT_SECURE_NO_WARNINGS

#include"StackQueue.h"

SQueue* StackQueueCreate()
{
	SQueue* newSQ = (SQueue*)malloc(sizeof(SQueue));
	assert(newSQ);
	newSQ->pushSTStack = (STStack*)malloc(sizeof(STStack));
	newSQ->popSTStack = (STStack*)malloc(sizeof(STStack));
	assert(newSQ->pushSTStack);
	assert(newSQ->popSTStack);
	STStackInit(newSQ->popSTStack);
	STStackInit(newSQ->pushSTStack);

	return newSQ;
}

void StackQueueDestroy(SQueue* stacks)
{
	assert(stacks);
	assert(stacks->pushSTStack);
	assert(stacks->popSTStack);

	STStackDestroy(stacks->pushSTStack);
	STStackDestroy(stacks->popSTStack);

	free(stacks);
}

void SQueuePush(SQueue* stacks, STSDataType x)
{
	assert(stacks);
	assert(stacks->pushSTStack);

	//向push栈填充数据
	STStackPush(stacks->pushSTStack, x);
}

STSDataType SQueuePop(SQueue* stacks)
{
	assert(stacks);
	assert(stacks->popSTStack);
	assert(stacks->pushSTStack);

	STSDataType ret = 0;

	//pop栈有数据则从pop栈弹数据
	//pop栈无数据则将puss栈数据全部压入pop栈，再将栈顶数据弹出
	//push栈始终保留最后的数据再弹出

	if (!STStackEmpty(stacks->popSTStack))
	{
		//pop栈有数据 - 弹pop栈
		ret = STStackTop(stacks->popSTStack);
		STStackPop(stacks->popSTStack);
		return ret;
	}

	if (!STStackEmpty(stacks->pushSTStack))
	{
		//pop栈无数据从push栈拿数据
		while (STStackSize(stacks->pushSTStack) > 1) 
		{
			//将push栈弹出的数据压入pop栈
			STStackPush(stacks->popSTStack, STStackTop(stacks->pushSTStack));
			STStackPop(stacks->pushSTStack);
		}
		ret = STStackTop(stacks->pushSTStack);
		STStackPop(stacks->pushSTStack);
		return ret;

	}

	//两栈都无数据则报错
	assert(0);
}

STSDataType SQueueTop(SQueue* stacks)
{
	assert(stacks);
	assert(stacks->pushSTStack);
	assert(stacks->popSTStack);

	STSDataType ret = 0;

	if (!STStackEmpty(stacks->popSTStack))
	{
		//pop栈有数据 - 弹pop栈
		ret = STStackTop(stacks->popSTStack);
		return ret;
	}

	if (!STStackEmpty(stacks->pushSTStack))
	{
		//pop栈无数据从push栈拿数据
		while (!STStackEmpty(stacks->pushSTStack))
		{
			//将push栈弹出的数据压入pop栈
			STStackPush(stacks->popSTStack, STStackTop(stacks->pushSTStack));
			STStackPop(stacks->pushSTStack);
		}
		ret = STStackTop(stacks->popSTStack);
		return ret;

	}

	//两栈都无数据则报错
	assert(0);
}

BOOL SQueueEmpty(SQueue* stacks)
{
	assert(stacks);
	assert(stacks->pushSTStack);
	assert(stacks->popSTStack);

	if (STStackEmpty(stacks->pushSTStack) && STStackEmpty(stacks->popSTStack))
		return TRUE;
	else
		return FALSE;
}