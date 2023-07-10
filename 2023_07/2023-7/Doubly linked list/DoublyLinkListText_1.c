#define _CRT_SECURE_NO_WARNINGS

#include"DoublyList.h"

void DBListTest_01()
{
	int i = 0;
	DBLinkNode* pListHead = DBLinkCycleListInit();

	for (i = 0; i < 5; i++)
	{
		DBLinkCycleListPushFront(pListHead, i + 1);
	}
	DBLinkCycleListPrint(pListHead);
	for (i = 0; i < 5; i++)
	{
		DBLinkCycleListPopFront(pListHead);
	}
	DBLinkCycleListPrint(pListHead);
}

void DBListTest_02()
{
	int i = 0;
	DBLinkNode* pListHead = DBLinkCycleListInit();

	for (i = 0; i < 5; i++)
	{
		DBLinkCycleListPushBack(pListHead, i + 1);
	}
	DBLinkCycleListPrint(pListHead);
	for (i = 0; i < 5; i++)
	{
		DBLinkCycleListPopBack(pListHead);
	}
	DBLinkCycleListPrint(pListHead);
}

void DBListTest_03()
{
	int i = 0;
	DBLinkNode* pListHead = DBLinkCycleListInit();

	for (i = 0; i < 5; i++)
	{
		DBLinkCycleListPushBack(pListHead, i + 1);
	}
	DBLinkCycleListPrint(pListHead);

	DBLinkCycleListErase(DBLinkCycleListFind(pListHead, 2));

	DBLinkCycleListPrint(pListHead);
	for (i = 0; i < 5; i++)
	{
		DBLinkCycleListPopBack(pListHead);
	}
}

int main()
{
	//DBListTest_01();
	//DBListTest_02();
	DBListTest_03();

	return 0;
}