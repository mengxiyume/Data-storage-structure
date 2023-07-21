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

	//ѭ�����������ַ���
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			//������������ջ, ָ����һ��
			STStackPush(&stack, *s);
			s++;
		}
		else
		{
			if (STStackEmpty(&stack))
			{
				//�޿�ƥ��������ʱ���տռ䲢����FALSE
				STStackDestroy(&stack);
				return FALSE;
			}
			//��ջ���ж��������Ƿ�Ϸ�
			char topCh = STStackTop(&stack);
			if ((topCh == '(' && *s != ')') ||
				(topCh == '[' && *s != ']') ||
				(topCh == '{' && *s != '}')) {
				//���Ϸ�ʱ���տռ䣬����FALSE
				STStackDestroy(&stack);
				return FALSE;
			}
			else
			{
				//�Ϸ� - ��ջ��ָ����һ��
				STStackPop(&stack);
				s++;
			}
		}
	}

	//��ջ�ҿ��ٹ��ռ��򷵻�TRUE�����򷵻�FALSE
	if (stack.arrData && STStackEmpty(&stack))
	{
		//�ռ����
		STStackDestroy(&stack);
		return TRUE;
	}
	else
	{
		//�ռ����
		STStackDestroy(&stack);
		return FALSE;
	}
}

/// <summary>
/// ��Ч������
/// </summary>
void STS_Test02()
{
	//����һ��ֻ����'(', ')', '{', '}', '[', ']'���ַ���s���ж��ַ����Ƿ���Ч
	//��Ч �ַ���������:
	//	�����ű�������ͬ���͵������űպ�
	//	�����ű�������ȷ��˳��պ�
	char* arr[] = { "{(})" ,"()()" , "(())" , "((])" ,"]" ,"{" ,"" };
	int c = _countof(arr);
	int i = 0;

	//ѭ���������еĲ�������
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