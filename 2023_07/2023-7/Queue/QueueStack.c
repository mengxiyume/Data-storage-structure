#define _CRT_SECURE_NO_WARNINGS

#include"QueueStack.h"

QStack* CreateQueueStack()
{
	//��ʼ��
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

	//�ֱ�ע����������
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

	//�սṹָ�뽻��
	if (!QueueEmpty(emptyQ))
	{
		Queue* tmpEmptyQ = emptyQ;
		emptyQ = nonEmptyQ;
		nonEmptyQ = tmpEmptyQ;
	}

	assert(!QueueEmpty(nonEmptyQ));

	while (QueueSize(nonEmptyQ) > 1)
	{
		//����ת��
		QueuePush(emptyQ, QueueFront(nonEmptyQ));
		QueuePop(nonEmptyQ);
	}
	
	//���һ��Ԫ��
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
		//q1�������򷵻�q1�Ķ�β
		return queues->q1->tail->data;
	}
	else
	{
		//���򷵻�q2�Ķ�β
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