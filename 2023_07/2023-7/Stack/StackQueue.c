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

	//��pushջ�������
	STStackPush(stacks->pushSTStack, x);
}

STSDataType SQueuePop(SQueue* stacks)
{
	assert(stacks);
	assert(stacks->popSTStack);
	assert(stacks->pushSTStack);

	STSDataType ret = 0;

	//popջ���������popջ������
	//popջ��������pussջ����ȫ��ѹ��popջ���ٽ�ջ�����ݵ���
	//pushջʼ�ձ������������ٵ���

	if (!STStackEmpty(stacks->popSTStack))
	{
		//popջ������ - ��popջ
		ret = STStackTop(stacks->popSTStack);
		STStackPop(stacks->popSTStack);
		return ret;
	}

	if (!STStackEmpty(stacks->pushSTStack))
	{
		//popջ�����ݴ�pushջ������
		while (STStackSize(stacks->pushSTStack) > 1) 
		{
			//��pushջ����������ѹ��popջ
			STStackPush(stacks->popSTStack, STStackTop(stacks->pushSTStack));
			STStackPop(stacks->pushSTStack);
		}
		ret = STStackTop(stacks->pushSTStack);
		STStackPop(stacks->pushSTStack);
		return ret;

	}

	//��ջ���������򱨴�
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
		//popջ������ - ��popջ
		ret = STStackTop(stacks->popSTStack);
		return ret;
	}

	if (!STStackEmpty(stacks->pushSTStack))
	{
		//popջ�����ݴ�pushջ������
		while (!STStackEmpty(stacks->pushSTStack))
		{
			//��pushջ����������ѹ��popջ
			STStackPush(stacks->popSTStack, STStackTop(stacks->pushSTStack));
			STStackPop(stacks->pushSTStack);
		}
		ret = STStackTop(stacks->popSTStack);
		return ret;

	}

	//��ջ���������򱨴�
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