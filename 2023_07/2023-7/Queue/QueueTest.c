#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"
#include"QueueStack.h"

void QueueTest01()
{
	Queue queue = { 0 };
	int i = 0;
	QueueInit(&queue);

	for (i = 0; i < 5; i++)
	{
		QueuePush(&queue, i);
	}

	printf("%d\n", QueueBack(&queue));

	for (i = 0; i < 5; i++)
	{
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}

	QueueDestroy(&queue);
	printf("\n%d\n", QueueEmpty(&queue));
}                                            

/// <summary>
/// 用队列实现栈
/// </summary>
void QueueStackTest01()
{
	QStack* st = CreateQueueStack();
	int i = 0;
	
	for (i = 0; i < 10; i++)
	{
		QueueStackPush(st, i);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", QueueStackPop(st));
	}

	printf("\n%d %d\n", QueueStackTop(st), QueueStackEmpty(st));

	QueueStackDestroy(st);
	st = NULL;
}

int main()
{
	//QueueTest01();
	QueueStackTest01();
	return 0;
}