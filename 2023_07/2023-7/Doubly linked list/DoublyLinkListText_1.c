#define _CRT_SECURE_NO_WARNINGS

#include"DoublyList.h"

void DBListTest_01()
{
	int i = 0;
	DBLinkNode* pListHead = DBLinkListInit();

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

int main()
{
	DBListTest_01();

	return 0;
}