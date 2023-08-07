#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

/// <summary>
/// 获取一个节点的空间且填充数据并链接上一个节点
/// </summary>
/// <param name="prev">上一个节点的地址</param>
/// <param name="data">需填充的数据</param>
/// <returns>返回值为新开辟的空间</returns>
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
/// 初始化队列
/// </summary>
/// <param name="pQueue">队列的地址</param>
void QueueInit(Queue* pQueue)
{
	assert(pQueue);

	pQueue->head = NULL;
	pQueue->tail = NULL;
}

/// <summary>
/// 向队列输入数据入队
/// </summary>
/// <param name="pQueue">队列地址</param>
/// <param name="data">数据</param>
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
/// 从队列移除数据出队
/// </summary>
/// <param name="pQueue">队列地址</param>
void QueuePop(Queue* pQueue)
{
	//秋猎以及队列内无消息时报错
	assert(pQueue && pQueue->head && pQueue->tail);

	//拿到原本的head，head移动
	QNode* prev = pQueue->head;
	pQueue->head = pQueue->head->next;

	//如果移动后的head为NULL，则队列无数据，队尾置空
	if (!pQueue->head)
	{
		pQueue->tail = NULL;
	}

	//释放空间
	free(prev);
	prev = NULL;
}

/// <summary>
/// 获取队尾的数据
/// </summary>
/// <param name="pQueue">队列的地址</param>
/// <returns>获取到数据</returns>
QDataType QueueBack(Queue* pQueue)
{
	assert(pQueue && pQueue->tail);
	return pQueue->tail->data;
}

/// <summary>
/// 获取队头的数据
/// </summary>
/// <param name="pQueue">队列地址</param>
/// <returns>队头的数据</returns>
QDataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	assert(pQueue->head);
	return pQueue->head->data;
}

/// <summary>
/// 获取队列内数据数量
/// </summary>
/// <param name="pQueue">队列的地址</param>
/// <returns>队列内数据的数量</returns>
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
/// 判断队列是否为空
/// </summary>
/// <param name="pQueue">队列地址</param>
/// <returns>为空返回true</returns>
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
/// 注销队列
/// </summary>
/// <param name="pQueue">队列的地址</param>
void QueueDestroy(Queue* pQueue)
{
	//从队头开始释放节点空间
	assert(pQueue);


//#ifndef heightPerformance
//#define heightPerformance
//#endif
//
//#ifdef heightPerformance
	#pragma region 采用效率高的方式

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
	#pragma region 采用效率低的方式

		////如果队列有数据，则出队
		//while (queueempty(pqueue))
		//{
		//	queuepop(pqueue);
		//}

	#pragma endregion
//#endif
//#undef heightPerformance
}