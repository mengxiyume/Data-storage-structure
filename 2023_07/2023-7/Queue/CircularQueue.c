#define _CRT_SECURE_NO_WARNINGS

#include"CircularQueue.h"

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

CircularQueue* CircularQueueCreate(int k)
{
	CircularQueue* newCQ = (CircularQueue*)malloc(sizeof(CircularQueue));
	CQDataType* newArrData = (CQDataType*)malloc(sizeof(CQDataType) * k + 1);
	assert(newCQ && newArrData);
	newCQ->arrData = newArrData;
	newCQ->nCapacity = k;
	newCQ->iFront = 0;
	newCQ->iTail = 0;
	
	return newCQ;
}

void CircularQueueDestroy(CircularQueue* obj)
{
	assert(obj);
	assert(obj->arrData);
	free(obj->arrData);
	obj->arrData = NULL;
	free(obj);
}

bool CircularQueueEnQueue(CircularQueue* obj, CQDataType value)
{
	assert(obj);
	assert(obj->arrData);

	if (CircularQueueIsFull(obj))
	{
		return false;
	}

	obj->arrData[obj->iTail] = value;

	//环型链接
	obj->iTail++;
	obj->iTail = obj->iTail % obj->nCapacity;

	return true;
}

bool CircularQueueDeQueue(CircularQueue* obj)
{
	assert(obj);
	assert(obj->arrData);

	if (CircularQueueIsEmpty(obj))
	{
		return false;
	}

	obj->iFront++;
	obj->iFront = obj->iFront % obj->nCapacity;

	return true;
}

CQDataType CircularQueueFront(CircularQueue* obj)
{
	assert(obj);
	assert(obj->arrData);

	if (CircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->arrData[obj->iFront];
}

CQDataType CircularQueueRear(CircularQueue* obj)
{
	assert(obj);
	assert(obj->arrData);

	if (CircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->arrData[obj->iTail - 1];
}

bool CircularQueueIsEmpty(CircularQueue* obj)
{
	assert(obj);
	assert(obj->arrData);

	return obj->iFront == obj->iTail;
}

bool CircularQueueIsFull(CircularQueue* obj)
{
	assert(obj);
	assert(obj->arrData);

	return (obj->iTail + 1) % obj->nCapacity == obj->iFront;
}