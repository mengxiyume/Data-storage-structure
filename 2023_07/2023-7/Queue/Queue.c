#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

/// <summary>
/// ��ȡһ���ڵ�Ŀռ���������ݲ�������һ���ڵ�
/// </summary>
/// <param name="prev">��һ���ڵ�ĵ�ַ</param>
/// <param name="data">����������</param>
/// <returns>����ֵΪ�¿��ٵĿռ�</returns>
QNode* QueueBuyOneNode(QNode* prev, QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	if (prev)
	{
		prev->next = newNode;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/// <summary>
/// ��ʼ������
/// </summary>
/// <param name="pQueue">���еĵ�ַ</param>
void QueueInit(Queue* pQueue)
{
	assert(pQueue);

	pQueue->head = NULL;
	pQueue->tail = NULL;
}

/// <summary>
/// ����������������
/// </summary>
/// <param name="pQueue">���е�ַ</param>
/// <param name="data">����</param>
void QueuePush(Queue* pQueue, QDataType data)
{
	assert(pQueue);
	QNode* newNode = QueueBuyOneNode(pQueue->tail, data);
	if (!pQueue->head)
	{
		pQueue->head = newNode;
	}
	pQueue->tail = newNode;
}

/// <summary>
/// �Ӷ����Ƴ����ݳ���
/// </summary>
/// <param name="pQueue">���е�ַ</param>
void QueuePop(Queue* pQueue)
{
	//�����Լ�����������Ϣʱ����
	assert(pQueue && pQueue->head && pQueue->tail);

	//�õ�ԭ����head��head�ƶ�
	QNode* prev = pQueue->head;
	pQueue->head = pQueue->head->next;

	//����ƶ����headΪNULL������������ݣ���β�ÿ�
	if (!pQueue->head)
	{
		pQueue->tail = NULL;
	}

	//�ͷſռ�
	free(prev);
	prev = NULL;
}

/// <summary>
/// ��ȡ��β������
/// </summary>
/// <param name="pQueue">���еĵ�ַ</param>
/// <returns>��ȡ������</returns>
QDataType QueueBack(Queue* pQueue)
{
	assert(pQueue && pQueue->tail);
	return pQueue->tail->data;
}

/// <summary>
/// ��ȡ��ͷ������
/// </summary>
/// <param name="pQueue">���е�ַ</param>
/// <returns>��ͷ������</returns>
QDataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	assert(pQueue->head);
	return pQueue->head->data;
}

/// <summary>
/// ��ȡ��������������
/// </summary>
/// <param name="pQueue">���еĵ�ַ</param>
/// <returns>���������ݵ�����</returns>
size_t QueueSize(Queue* pQueue)
{
	assert(pQueue);
	int size = 0;
	QueueNode* curNode = pQueue->head;
	while (curNode)
	{
		size++;
		curNode = curNode->next;
	}
	
	return size;
}

/// <summary>
/// �ж϶����Ƿ�Ϊ��
/// </summary>
/// <param name="pQueue">���е�ַ</param>
/// <returns>Ϊ�շ���true</returns>
bool QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	if (!pQueue->head)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/// <summary>
/// ע������
/// </summary>
/// <param name="pQueue">���еĵ�ַ</param>
void QueueDestroy(Queue* pQueue)
{
	//�Ӷ�ͷ��ʼ�ͷŽڵ�ռ�
	assert(pQueue);


//#ifndef heightPerformance
//#define heightPerformance
//#endif
//
//#ifdef heightPerformance
	#pragma region ����Ч�ʸߵķ�ʽ

	if (!pQueue->head || !pQueue->tail)
	{
		pQueue->head = pQueue->tail = NULL;
		return;
	}
		QNode* cur = pQueue->head;

		while (cur)
		{
			QNode* prev = cur;
			cur = cur->next;

			free(prev);
			prev = NULL;
		}

		pQueue->head = NULL;
		pQueue->tail = NULL;

	#pragma endregion
//#else
	#pragma region ����Ч�ʵ͵ķ�ʽ

		////������������ݣ������
		//while (queueempty(pqueue))
		//{
		//	queuepop(pqueue);
		//}

	#pragma endregion
//#endif
//#undef heightPerformance
}