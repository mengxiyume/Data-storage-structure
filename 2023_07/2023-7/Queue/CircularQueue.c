#define _CRT_SECURE_NO_WARNINGS

#include"CircularQueue.h"

/*	���ѭ������ - ������Ԫ��Ϊ���������
* ѭ��������һ���������ݽṹ����������ֻ���FIFO���Ƚ��ȳ���ԭ��
* ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ����Ҳ���������ͻ�����
*
* ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ�
* ��һ����ͨ�Ķ����һ��һ�������������ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ�
* ��ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ
*
* ʵ�����ݽṹ��ӿ�
*	* CircularQueue(k)	�����������ö��г���Ϊk
*	* Front	�Ӷ��׻�ȡԪ�أ��������Ϊ�գ�����-1
*	* Rear	��ȡ��βԪ�أ������Ϊ�գ�����-1
*	* enQueue(value)	��ѭ�����в���һ��Ԫ�أ�����ɹ��򷵻���
*	* deQueue	��ѭ��������ɾ��һ��Ԫ�أ�����ɹ�ɾ���򷵻���
*	* isEmpty	���ѭ�������Ƿ�Ϊ��
*	* isFull	���ѭ�������Ƿ�����
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

	//��������
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