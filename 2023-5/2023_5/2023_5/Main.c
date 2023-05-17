#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

void TestSeqList01()
{
	SL sl;
	int i = 0;
	SeqListDataType data = 0;

	SeqListInit(&sl);
	for (i = 0; i < 6; i++)
	{
		data = i + 1;
		SeqListPushBack(&sl, &data);
	}

	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList02()
{
	SL sl;
	int i = 0;
	SeqListDataType data = 0;

	SeqListInit(&sl);
	for (i = 0; i < 6; i++)
	{
		data = i + 1;
		SeqListPushBack(&sl, &data);
	}

	SeqListPrint(&sl);

	while (sl.size)
	{
		SeqListPopFront(&sl);
	}
	SeqListDestroy(&sl);
}

void TestSeqList03()
{
	SL sl;
	SeqListDataType findDestination = 4;
	int i = 0;
	SeqListDataType data = 0;

	SeqListInit(&sl);
	for (i = 0; i < 6; i++)
	{
		data = i + 1;
		SeqListPushBack(&sl, &data);
	}

	SeqListPrint(&sl);

	printf("%d ÏÂ±êÎª %d", 4, SeqListFind(&sl, &findDestination, SeqListDataTypeContrastf));

	SeqListDestroy(&sl);
}

void TestSeqList04()
{
	SL sl;
	SeqListDataType findDestination = 4;
	int i = 0;
	SeqListDataType data = 0;

	SeqListInit(&sl);
	for (i = 0; i < 6; i++)
	{
		data = i + 1;
		SeqListPushBack(&sl, &data);
	}

	SeqListPrint(&sl);

	data = 9;
	SeqListInsert(&sl, 3, &data);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList05()
{
	SL sl;
	SeqListInit(&sl);
	SeqListMenu(&sl);
	SeqListDestroy(&sl);
}

int main()
{

	//TestSeqList01();
	//TestSeqList02();
	//TestSeqList03();
	//TestSeqList04();
	TestSeqList05();

	return 0;
}