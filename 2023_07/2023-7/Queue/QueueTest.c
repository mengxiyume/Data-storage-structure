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

//��ջʵ�ֶ���
// ����ʹ������ջʵ�������ȳ����У�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty��
// void StackQueuePush(int x)	//��Ԫ��x�Ƶ�����β
// int StackQueuePop()			//�Ӷ��п�ͷ�Ƴ�Ԫ�ز����ظ�Ԫ��
// int StackQueuePeek()			//���ض��п�ͷ��Ԫ��
// bool StackQueueEmpty()		//�п�                                                 

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

int main()
{
	//QueueTest01();
	QueueStackTest01();
	return 0;
}