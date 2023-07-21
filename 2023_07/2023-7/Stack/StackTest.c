#define _CRT_SECURE_NO_WARNINGS

#include"LinkListStack.h"
#include"SequenceTableStack.h"

void STS_Test01()
{
	int i = 0;
	STStack stack = { 0 };
	STStackInit(&stack);
	
	for (i = 0; i < 10; i++)
	{
		STStackPush(&stack, i);
	}
	STStackPrint(&stack);

	for (i = 0; i < 2; i++)
	{
		STStackPop(&stack);
	}
	STStackPrint(&stack);

	printf("Top %d\n", STStackTop(&stack));
	printf("Size %d\n", STStackSize(&stack));
	printf("Life %d\n", STStackEmpty(&stack));

	while (STStackEmpty(&stack))
	{
		printf("%d ", STStackTop(&stack));
		STStackPop(&stack);
	}
	STStackPrint(&stack);

	//printf("Top %d\n", STStackTop(&stack));
	printf("Size %d\n", STStackSize(&stack));
	printf("Life %d\n", STStackEmpty(&stack));

	STStackDestroy(&stack);
}

int main()
{
	STS_Test01();

	return 0;
}