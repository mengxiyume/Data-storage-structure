#pragma once

#include"Queue.h"

typedef struct {
	Queue* q1;
	Queue* q2;
}QueueStack;

typedef QueueStack QStack;

QStack* CreateQueueStack();
void QueueStackDestroy(QStack* queues);
void QueueStackPush(QStack* queues, QDataType data);
QDataType QueueStackPop(QStack* queues);
QDataType QueueStackTop(QStack* queues);
bool QueueStackEmpty(QStack* queues);