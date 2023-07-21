#define _CRT_SECURE_NO_WARNINGS

#include"SequenceTableStack.h"

void BuyBlock(STStack* ps)
{
	assert(ps);

	if (ps->top >= ps->capacity - 1)
	{
		const int baseSize = 4;
		int newSize = ps->capacity <= 0 ? baseSize : ps->capacity * 2;
		STSDataType* arrData = (STSDataType*)realloc(ps->arrData, sizeof(STSDataType) * newSize);
		assert(arrData);

		ps->capacity = newSize;
		ps->arrData = arrData;
	}
}

void STStackInit(STStack* ps)
{
	assert(ps);
	//初始化栈

	//Top指向当前顶层节点
	ps->top = -1;

	ps->capacity = 0;
	ps->arrData = NULL;
}

void STStackDestroy(STStack* ps)
{
	//数据置空，空间回收
	assert(ps);
	if (!ps->arrData)
	{
		return;
	}
	free(ps->arrData);
	ps->capacity = 0;
	ps->top = -1;
	ps->arrData = NULL;
}

void STStackPush(STStack* ps, STSDataType data)
{
	assert(ps);
	//内存增容
	BuyBlock(ps);
	//栈顶指针移动
	//数据填充
	ps->arrData[++(ps->top)] = data;
}

void STStackPop(STStack* ps)
{
	assert(ps && ps->arrData);

	if (ps->top >= 0)
	{
		ps->top--;
	}
}

STSDataType STStackTop(STStack* ps)
{
	assert(ps && ps->arrData);
	if (ps->top >= 0)
	{
		return ps->arrData[ps->top];
	}
	else
	{
		printf("\nStack Not Have Data\n");
		assert(0);
	}
}

int STStackSize(STStack* ps)
{
	assert(ps && ps->arrData);

	if (ps->top >= 0)
	{
		return ps->top + 1;
	}
	else
	{
		return 0;
	}
}

BOOL STStackEmpty(STStack* ps)
{
	assert(ps);

	if (ps->top >= 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

void STStackPrint(STStack* ps)
{
	int i = 0;
	assert(ps);
	if (ps->arrData == NULL || ps->top < 0)
	{
		printf("\nStack Not Have Data\n");
		return;
	}

	printf("/|\\\n");
	for (i = ps->top; i >= 0; i--)
	{
		printf(" | %d", ps->arrData[i]);
		if (i == ps->top)
		{
			printf(" <-- Top");
		}
		printf("\n");
	}
	printf("\n");
}