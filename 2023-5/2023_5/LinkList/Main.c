#define _CRT_SECURE_NO_WARNINGS

#include"SingleList.h"

void TestSingleList01()
{
	SLNode* pList = NULL;

	SingleListPushBack(&pList, 1);
	SingleListPushBack(&pList, 2);
	SingleListPushBack(&pList, 3);
	SingleListPushBack(&pList, 4);
	SingleListPushBack(&pList, 5);

	SingleListPrint(pList);
	SingleListDestroy(&pList);
}

void TestSingleList02()
{
	SLNode* pList = NULL;

	SingleListPushFront(&pList, 1);
	SingleListPushFront(&pList, 2);
	SingleListPushFront(&pList, 3);
	SingleListPushFront(&pList, 4);
	SingleListPushFront(&pList, 5);

	SingleListPrint(pList);

	SingleListPopFront(&pList);
	SingleListPopBack(&pList);
	SingleListPrint(pList);

	SingleListPopFront(&pList);
	SingleListPopBack(&pList);
	SingleListPopFront(&pList);
	SingleListPopBack(&pList);
	SingleListPopFront(&pList);
	SingleListPopBack(&pList);
	SingleListPopFront(&pList);
	SingleListPopBack(&pList);

	SingleListPrint(pList);
	SingleListDestroy(&pList);
}

void TestSingleList03()
{
	SLNode* pList = NULL;

	SingleListPushFront(&pList, 1);
	SingleListPushFront(&pList, 2);
	SingleListPushFront(&pList, 3);
	SingleListPushFront(&pList, 4);
	SingleListPushFront(&pList, 5);

	SingleListPrint(pList);

	printf("%d\n", SingleListFind(pList, 3));

	SingleListInsert(&pList, -1, 100);
	SingleListInsert(&pList, 0, 100);
	SingleListInsert(&pList, 4, 100);
	SingleListInsert(&pList, 10, 100);

	SingleListPrint(pList);

	SingleListDestroy(&pList);
}

void TestSingleList04()
{
	SLNode* pList = NULL;

	SingleListPushFront(&pList, 1);
	SingleListPushFront(&pList, 2);
	SingleListPushFront(&pList, 3);
	SingleListPushFront(&pList, 4);
	SingleListPushFront(&pList, 5);

	SingleListPrint(pList);

	printf("%d\n", SingleListFind(pList, 3));

	SingleListInsert(&pList, -1, 100);
	SingleListInsert(&pList, 0, 100);
	SingleListInsert(&pList, 4, 400);
	SingleListInsert(&pList, 10, 100);

	SingleListPrint(pList);

	SingleListErase(&pList, SingleListFind(pList, 100));
	SingleListErase(&pList, SingleListFind(pList, 400));

	SingleListPrint(pList);

	SingleListDestroy(&pList);
}

void TestSingleList05()
{
	//给你一个链表的头节点heaed和一个整数val，请你删除链表中所有满足Node.val == val 的节点，并返回新的头节点
	//输入:head = [1,2,6,3,4,5,6],val = 6
	
	SingleListDataType arr[6] = { 6,6,6,6,6,6 };
	int i = 0;
	SLNode* pList = NULL;
	
	for (i = 0; i < 6; i++)
	{
		SingleListPushBack(&pList, arr[i]);
	}
	SingleListPrint(pList);

	pList = SingleListRemoveElments(pList, 6);

	SingleListPrint(pList);
}

void TestSingleList06()
{
	SLNode* pList = NULL;
	SLNode* pInsDataList = NULL;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		SingleListPushBack(&pList, i + 1);
	}
	SingleListPrint(pList);
	SingleListInsertAfter(pList, 100);
	pInsDataList = pList;
	while (pInsDataList && pInsDataList->next)
	{
		pInsDataList = pInsDataList->next;
	}
	SingleListInsertAfter(pInsDataList, 200);
	SingleListPrint(pList);
	SingleListEraseAfter(pList);
	SingleListEraseAfter(pInsDataList);
	SingleListPrint(pList);

}

int main()
{
	//TestSingleList01();
	//TestSingleList02();
	//TestSingleList03();
	//TestSingleList04();
	//TestSingleList05();
	TestSingleList06();
	return 0;
}