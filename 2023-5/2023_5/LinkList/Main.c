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
	SingleListDestroy(&pList);
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
	SingleListDestroy(&pList);
}

void TestSingleList07()
{
	SLNode* pList = NULL;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		SingleListPushBack(&pList, i + 1);
	}
	SingleListPrint(pList);
	pList = SingleListReverseList(pList);
	SingleListPrint(pList);
	SingleListDestroy(&pList);
}

void TestSingleList08()
{
	SLNode* pList = NULL;
	SLNode* pMiddle = NULL;
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		SingleListPushBack(&pList, i + 1);
	}
	SingleListPrint(pList);
	pMiddle = SingleListMiddleNode(pList);
	SingleListPrintOneNode(pMiddle);
	SingleListDestroy(&pList);
}

void TestSingleList09()
{
	int k = 0;
	SLNode* pList = NULL;
	SLNode* pKthToTail = NULL;
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		SingleListPushBack(&pList, i + 1);
	}
	SingleListPrint(pList);
	pKthToTail = SingleListFindKthToTail(pList, k);

	printf("The %dth to tail Node's data is ", k);

	SingleListPrintOneNode(pKthToTail);
	SingleListDestroy(&pList);
}

void TestSingleList10()
{
	int k = 0;
	SingleListDataType arr1[3] = { 1,1,4 };
	SingleListDataType arr2[3] = { 2,6,6 };
	SLNode* pL1 = NULL, * pL2 = NULL;
	SLNode* newList = NULL;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		SingleListPushBack(&pL1, arr1[i]);
		SingleListPushBack(&pL2, arr2[i]);
	}
	SingleListPushBack(&pL1, 8);
	SingleListPrint(pL1);
	SingleListPrint(pL2); 

	newList = SingleListMergeTowList(pL1, pL2);
	pL1 = pL2 = NULL;
	SingleListPrint(newList);

	SingleListDestroy(&newList);
}

void TestSingleList11()
{
	int i = 0;

	SingleListDataType fillData[10] = { -1,-7,0,-9,10,-5,12 };
	SLNode* pList = NULL;

	for (i = 0; i < 10; i++)
	{
		SingleListPushBack(&pList, fillData[i]);
	}
	SingleListPrint(pList);

	pList = SingleListPartition(pList, 0);
	SingleListPrint(pList);

	SingleListDestroy(&pList);
}

void TestSingleList12()
{
	int i = 0;

	SingleListDataType palindromArr[3] = { 1,2,1 };
	SLNode* pList = NULL;

	for (i = 0; i < 3; i++)
	{
		SingleListPushBack(&pList, palindromArr[i]);
	}
	SingleListPrint(pList);

	printf("%d\n", SingleListCheckPalindrom(pList));

	SingleListPrint(pList);

	SingleListDestroy(&pList);
}

void TestSingleList13()
{
	int i = 0;

	SingleListDataType ArrA[3] = { 0,1,2 };
	SingleListDataType ArrB[3] = { 0,-1,-2 };
	SingleListDataType ArrC[3] = { 3,4,5 };
	SLNode* pListATail = NULL, * pListBTail = NULL;
	SLNode* pListA = NULL, * pListB = NULL, * pListC = NULL;

	for (i = 0; i < 3; i++)
	{
		SingleListPushBack(&pListA, ArrA[i]);
		SingleListPushBack(&pListB, ArrB[i]);
		SingleListPushBack(&pListC, ArrC[i]);
	}
	SingleListPrint(pListA);
	SingleListPrint(pListB);
	SingleListPrint(pListC);
	
	pListATail = SingleListFindTail(pListA);
	pListBTail = SingleListFindTail(pListB);

	pListATail->next = pListC;
	pListBTail->next = pListC;

	SingleListPushFront(&pListA, 9);
	SingleListPushFront(&pListA, 99);
	SingleListPushFront(&pListA, 999);

	SingleListPrintOneNode(SingleListGetIntersectionNode(pListA, pListB));

	SingleListPrint(pListA);
	SingleListPrint(pListB);

	pListATail->next = NULL;
	pListBTail->next = NULL;

	SingleListDestroy(&pListA);
	SingleListDestroy(&pListB);
	SingleListDestroy(&pListC);
}

void TestSingleList14()
{
	int i = 0;

	SLNode* pList = NULL;
	SLNode* pListTail = NULL;

	for (i = 0; i < 9; i++)
	{
		SingleListPushBack(&pList, 10-i);
	}

	pListTail = SingleListFindTail(pList);
	SingleListPrint(pList);
	//进环节点在链表的第二个节点
	pListTail->next = pList->next;

	printf("%d\n", SingleListHasCycle(pList));
	SingleListPrintOneNode(SingleListDetectCycle(pList));

	//进环节点在链表的第一个节点，也就是链表是一个完整的环
	pListTail->next = pList;
	SingleListPrintOneNode(SingleListDetectCycle(pList));
	pListTail->next = NULL;

	SingleListPrint(pList);
	SingleListDestroy(&pList);

}

void TestSingleList15()
{
	int i = 0;

	SLNode_Random* pList = NULL;
	SLNode_Random* pNewList = NULL;

	for (i = 0; i < 10; i++)
	{
		SingleListRandomPushBack(&pList, i + 1);
	}
	assert(pList);

	pList->random = NULL;
	pList->next->random = pList->next->next->next->next;
	pList->next->next->random = pList;

	SingleListRandomPrint(pList);
	printf("\n");

	pNewList = SingleListCopyRandomList(pList);
	SingleListRandomPrint(pNewList);
}

int main()
{
	//TestSingleList01();
	//TestSingleList02();
	//TestSingleList03();
	//TestSingleList04();
	//TestSingleList05();
	//TestSingleList06();
	//TestSingleList07();
	//TestSingleList08();
	//TestSingleList09();
	//TestSingleList10();
	//TestSingleList11();
	//TestSingleList12();
	//TestSingleList13();
	//TestSingleList14();
	TestSingleList15();
	return 0;
}