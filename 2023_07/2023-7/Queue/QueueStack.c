#define _CRT_SECURE_NO_WARNINGS

#include"QueueStack.h"

QStack* CreateQueueStack()
{
	//初始化
	QStack* ret = (QStack*)malloc(sizeof(QStack));
	assert(ret);
	ret->q1 = (Queue*)malloc(sizeof(Queue));
	ret->q2 = (Queue*)malloc(sizeof(Queue));
	QueueInit(ret->q1);
	QueueInit(ret->q2);
	
	return ret;
}

void QueueStackDestroy(QStack* queues)
{
	assert(queues);
	assert(queues->q1);
	assert(queues->q2);

	//分别注销连个队列
	QueueDestroy(queues->q1);
	QueueDestroy(queues->q2);

	free(queues);
}

void QueueStackPush(QStack* queues, QDataType data)
{
	assert(queues);
	assert(queues->q1);
	assert(queues->q2);

	if (!QueueEmpty(queues->q1))
	{
		QueuePush(queues->q1, data);
	}
	else
	{
		QueuePush(queues->q2, data);
	}
}

QDataType QueueStackPop(QStack* queues)
{
	assert(queues);
	assert(queues->q1);
	assert(queues->q2);

	QDataType ret = 0;

	Queue* emptyQ = queues->q1;
	Queue* nonEmptyQ = queues->q2;

	//空结构指针交换
	if (!QueueEmpty(emptyQ))
	{
		Queue* tmpEmptyQ = emptyQ;
		emptyQ = nonEmptyQ;
		nonEmptyQ = tmpEmptyQ;
	}

	assert(!QueueEmpty(nonEmptyQ));

	while (QueueSize(nonEmptyQ) > 1)
	{
		//数据转移
		QueuePush(emptyQ, QueueFront(nonEmptyQ));
		QueuePop(nonEmptyQ);
	}
	
	//最后一个元素
	ret = QueueFront(nonEmptyQ);
	QueuePop(nonEmptyQ);

	return ret;
}

QDataType QueueStackTop(QStack* queues)
{
	assert(queues);
	assert(queues->q1);
	assert(queues->q2);

	if (!QueueEmpty(queues->q1))
	{
		//q1有数据则返回q1的队尾
		return queues->q1->tail->data;
	}
	else
	{
		//否则返回q2的队尾
		return queues->q2->tail->data;
	}
}

bool QueueStackEmpty(QStack* queues)
{
	assert(queues);
	assert(queues->q1);
	assert(queues->q2);

	if (QueueEmpty(queues->q1) && QueueEmpty(queues->q2))
	{
		return true;
	}
	else
	{
		return false;
	}

}