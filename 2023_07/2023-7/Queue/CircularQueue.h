#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

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

typedef int CircularQueueDataType;
typedef CircularQueueDataType CQDataType;

typedef struct {
	CircularQueueDataType* arrData;
	int iFront;
	int iTail;
	int nCapacity;	//���ÿռ���ܴ�С�����±��1
}CircularQueue;

CircularQueue* CircularQueueCreate(int k);
void CircularQueueDestroy(CircularQueue* obj);
bool CircularQueueEnQueue(CircularQueue* obj, CQDataType value);
bool CircularQueueDeQueue(CircularQueue* obj);
CQDataType CircularQueueFront(CircularQueue* obj);
CQDataType CircularQueueRear(CircularQueue* obj);
bool CircularQueueIsEmpty(CircularQueue* obj);
bool CircularQueueIsFull(CircularQueue* obj);