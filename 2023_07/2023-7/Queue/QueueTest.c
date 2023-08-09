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
/// �ö���ʵ��ջ
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