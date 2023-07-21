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

	while (!STStackEmpty(&stack))
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

BOOL isValid(char* s)
{
	assert(s);
	STStack stack = { 0 };
	STStackInit(&stack);

	//循环遍历整个字符串
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			//遇到左括号入栈, 指针走一步
			STStackPush(&stack, *s);
			s++;
		}
		else
		{
			if (STStackEmpty(&stack))
			{
				//无可匹配左括号时回收空间并返回FALSE
				STStackDestroy(&stack);
				return FALSE;
			}
			//弹栈并判定右括号是否合法
			char topCh = STStackTop(&stack);
			if ((topCh == '(' && *s != ')') ||
				(topCh == '[' && *s != ']') ||
				(topCh == '{' && *s != '}')) {
				//不合法时回收空间，返回FALSE
				STStackDestroy(&stack);
				return FALSE;
			}
			else
			{
				//合法 - 弹栈，指针走一步
				STStackPop(&stack);
				s++;
			}
		}
	}

	//空栈且开辟过空间则返回TRUE，否则返回FALSE
	if (stack.arrData && STStackEmpty(&stack))
	{
		//空间回收
		STStackDestroy(&stack);
		return TRUE;
	}
	else
	{
		//空间回收
		STStackDestroy(&stack);
		return FALSE;
	}
}

/// <summary>
/// 有效的括号
/// </summary>
void STS_Test02()
{
	//给定一个只包括'(', ')', '{', '}', '[', ']'的字符串s，判断字符串是否有效
	//有效 字符串需满足:
	//	左括号必须与相同类型的右括号闭合
	//	左括号必须以正确的顺序闭合
	char* arr[] = { "{(})" ,"()()" , "(())" , "((])" ,"]" ,"{" ,"" };
	int c = _countof(arr);
	int i = 0;

	//循环测试所有的测试用例
	for (i = 0; i < c; i++)
	{
		printf("%d ", isValid(arr[i]));
	}
	
}

int main()
{
	//STS_Test01();
	STS_Test02();

	return 0;
}