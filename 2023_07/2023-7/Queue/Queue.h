#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//队列 - 先进先出 - 链表结构

typedef int QueueDataType;
typedef QueueDataType QDataType;

typedef struct QueueNode {
	QDataType data;
	struct QueueNode* next;
}QueueNode;
typedef QueueNode QNode;

typedef struct Queue {
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pQueue);
void QueuePush(Queue* pQueue, QDataType data);
void QueuePop(Queue* pQueue);
QDataType QueueBack(Queue* pQueue);
QDataType QueueFront(Queue* pQueue);
size_t QueueSize(Queue* pQueue);
bool QueueEmpty(Queue* pQueue);
void QueueDestroy(Queue* pQueue);