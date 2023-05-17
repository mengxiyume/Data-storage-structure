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

int main()
{
	//TestSingleList01();
	//TestSingleList02();
	//TestSingleList03();
	TestSingleList04();
	return 0;
}