#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

#define TO_STRING(SOURSE) #SOURSE

void SeqListMenu(SL* pSeqList)
{
	assert(pSeqList);
	int select = 0;
	SeqListDataType data = 0;
	do {
	int subscript = 0;
		printf("%d."TO_STRING(PushFront)"\t%d."TO_STRING(PushBack)
			"\n%d."TO_STRING(PopFront)"\t%d."TO_STRING(PopBack)
			"\n%d."TO_STRING(PrintList)"\t%d."TO_STRING(FindData)
			"\n%d."TO_STRING(PushInsert)"\t%d."TO_STRING(Erase)
			"\n%d."TO_STRING(Exit)"\n",
			PushFront, PushBack, PopFront, PopBack, PrintList, FindData, PushInsert, Erase, Exit);
		printf("Select:>");
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case PushFront: 
			printf("%d."TO_STRING(PushFront)"--DataType:"TO_STRING(int)":>", PushFront);
			scanf("%d", &data);
			SeqListPushFront(pSeqList, &data);
			break;
		case PushBack:
			printf("%d."TO_STRING(PushBack)"--DataType:"TO_STRING(int)":>", PushBack);
			scanf("%d", &data);
			SeqListPushBack(pSeqList, &data);
			break;
		case PopFront:
			SeqListPopFront(pSeqList);
			break;
		case PopBack:
			SeqListPopBack(pSeqList);
			break;
		case PrintList:
			SeqListPrint(pSeqList);
			break;
		case FindData:
			printf("%d.SearchData--DataType:"TO_STRING(int)":>", FindData);
			scanf("%d", &data);
			subscript = SeqListFind(pSeqList, &data, SeqListDataTypeContrastf);
			if (subscript < 0)
			{
				printf("The data is not such the SeqList\n");
			}
			else
			{
				printf("The data (%d) subscript is [%d]\n", data, subscript);
			}
			break;
		case PushInsert:
			printf("%d.InsertData--DataType:"TO_STRING(int)":>", PushInsert);
			scanf("%d", &data);
			printf("\nInsert To Subscript:>");
			scanf("%d", &subscript);
			SeqListInsert(pSeqList, subscript, &data);
			break;
		case Erase:
			printf("%d.Erase Subscript:>_", Erase);
			scanf("%d", &subscript);
			SeqListErase(pSeqList, subscript);
			break;
		case Exit:
			exit(0);
		default:
			printf("The Instruct is not\n");
			system("pause");
			break;
		}
		printf("\n----\n");
	} while (select);
}

void SeqListInit(SL* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestroy(SL* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL* pSeqList)
{
	assert(pSeqList);
	int i = 0;
	for (i = 0; i < pSeqList->size; i++)
	{
		printf("%5d | ", pSeqList->data[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* pSeqList)
{
	assert(pSeqList);
	//1.空间充足，离开
	//2.空间不足，开辟空间
	//3.没有空间，开辟空间
	if (pSeqList->capacity == pSeqList->size)
	{
		int tmpNewCapacity = pSeqList->capacity ? pSeqList->capacity * SEQ_LIST_INCREASE : 4;
		SeqListDataType* tmpNewPData = NULL;
		//申请失败时缩减申请空间并再次申请
		while (tmpNewCapacity)
		{
			tmpNewPData = (SeqListDataType*)realloc(pSeqList->data, sizeof(SeqListDataType) * tmpNewCapacity);
			if (!tmpNewPData)
			{
				tmpNewCapacity /= SEQ_LIST_INCREASE;
			}
			else
			{
				break;
			}
		}
		if (!tmpNewPData)
		{
			//若无法继续申请则异常退出程序
			perror("");
			exit(-1);
		}

		pSeqList->data = tmpNewPData;
		pSeqList->capacity = tmpNewCapacity;
	}
}

int SeqListFind(SL* sourse, SeqListDataType* data, unsigned char Contrastf(SeqListDataType* d1,SeqListDataType* d2))
{
	//使用回调函数进行顺序对比
	//找到返回下标，找不到返回-1
	assert(sourse && data && Contrastf);
	int i = 0;
	for (i = 0; i < sourse->size; i++)
	{
		if (Contrastf(data, sourse->data + i))
		{
			return i;
		}
	}
	return -1;
}

unsigned char SeqListDataTypeContrastf(SeqListDataType* d1, SeqListDataType* d2)
{
	assert(d1 && d2);
	if ((*d1) == (*d2))
	{
		return 1;
	}
	return 0;
}

#pragma region Push
void SeqListPushBack(SL* pSeqList, SeqListDataType* data)
{
	assert(pSeqList && data);
	//容量检测
	SeqListCheckCapacity(pSeqList);
	//无论怎样都会进行的PushBack
	pSeqList->data[pSeqList->size++] = *data;

}

void SeqListPushFront(SL* pSeqList, SeqListDataType* data)
{
	//1.检测容量
	//2.挪动数据
	//3.插入数据,增加size

	assert(pSeqList && data);

	int end = 0;

	SeqListCheckCapacity(pSeqList);

	for (end = pSeqList->size - 1; end >= 0; end--)
	{
		pSeqList->data[end + 1] = pSeqList->data[end];
	}

	pSeqList->data[0] = *data;
	//*(pSeqList->data) = data;
	pSeqList->size++;
}

void SeqListInsert(SL* pSeqList, int position, SeqListDataType* data)
{
	//1.如果position > size, position = size
	//2.容量检测
	//3.将下标为position及之后的元素后移1位
	//4.在下标为position的位置写入数据,size增加
	assert(pSeqList && data);
	int i = 0;

	if (position >= 0)
	{
		if (position > pSeqList->size)
		{
			position = pSeqList->size;
		}
		SeqListCheckCapacity(pSeqList);
		for (i = pSeqList->size - 1; i >= position; i--)
		{
			pSeqList->data[i + 1] = pSeqList->data[i];
		}
		pSeqList->data[position] = *data;
		pSeqList->size++;
	}
}
#pragma endregion

#pragma region Pop
void SeqListPopBack(SL* pSeqList)
{
	assert(pSeqList);
	if (pSeqList->size > 0)
	{
		pSeqList->size--;
	}
}

void SeqListPopFront(SL* pSeqList)
{
	//1.数据向前位移覆盖上一位数据
	//2.数据减少
	assert(pSeqList);

	int begin = 0;

	for (begin = 0; begin < pSeqList->size - 1; begin++)
	{
		pSeqList->data[begin] = pSeqList->data[begin + 1];
	}

	if (pSeqList->size > 0)
	{
		pSeqList->size--;
	}
}

void SeqListErase(SL* pSeqList, int position)
{
	assert(pSeqList);
	int i = 0;

	if (position >= 0 && position <= pSeqList->size)
	{
		for (i = position; i < pSeqList->size; i++)
		{
			pSeqList->data[i] = pSeqList->data[i + 1];
		}
		pSeqList->size--;
	}
	else
	{
		printf("This subscript is not legal\n");
	}
}
#pragma endregion