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

//用栈实现队列
// 请你使用两个栈实现先入先出队列，队列应该支持一般队列支持的所有操作（push，pop，peek，empty）
// void StackQueuePush(int x)	//将元素x推到队列尾
// int StackQueuePop()			//从队列开头移除元素并返回该元素
// int StackQueuePeek()			//返回队列开头的元素
// bool StackQueueEmpty()		//判空                                                 

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