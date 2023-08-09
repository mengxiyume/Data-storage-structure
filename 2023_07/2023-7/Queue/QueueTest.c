#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"
#include"QueueStack.h"
#include"CircularQueue.h"

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

/*	设计循环队列 - 不考虑元素为负数的情况
* 循环队列是一种线形数据结构，其操作表现基于FIFO（先进先出）原则
* 并且队尾被连接在队首之后以形成一个循环，也被称作环型缓冲器
*
* 循环队列的一个好处是我们可以利用这个队列之前用过的空间
* 在一个普通的队列里，一旦一个队列满了我们就不能插入下一个元素，即使在队列前面仍有空间
* 但使用循环队列，我们能使用这些空间去存储新的值
*
* 实现数据结构与接口
*	* CircularQueue(k)	构造器，设置队列长度为k
*	* Front	从队首获取元素，如果队首为空，返回-1
*	* Rear	获取队尾元素，如队列为空，返回-1
*	* enQueue(value)	向循环队列插入一个元素，如果成功则返回真
*	* deQueue	从循环队列中删除一个元素，如果成功删除则返回真
*	* isEmpty	检测循环队列是否为空
*	* isFull	检查循环队列是否已满
*/

void CircularQueueTest01()
{
	CircularQueue* cq = CircularQueueCreate(10);
	int i = 0;

	for (i = 0; i < 20; i++)
	{
		if (!CircularQueueEnQueue(cq, i))
		{
			break;
		}
		printf("%d ", CircularQueueRear(cq));
	}

	printf("\n");

	for (i = 0; i < 20; i++)
	{
		if (!CircularQueueDeQueue(cq))
		{
			break;
		}
		printf("%d ", CircularQueueFront(cq));
	}

	CircularQueueDestroy(cq);
	cq = NULL;
}

int main()
{
	//QueueTest01();
	//QueueStackTest01();
	CircularQueueTest01();

	return 0;
}