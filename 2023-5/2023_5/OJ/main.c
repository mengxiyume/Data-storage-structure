#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>

#define ARR_SIZE 10

////����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³���
//
////��һƬ�ڴ�ռ��� int ��д����ʽд�� value����
//void MemsetIntBlock(void* destination, int value, size_t size)
//{
//	int i = 0;
//	int* pValue = &value;
//
//	for (i = 0; i < size; i++)
//	{
//		*((int*)destination + i) = *pValue;
//	}
//}
//
//#pragma region	�Լ�˼����˼·
//int removeElement01(int* nums, int numsSize, int val)
//{
//	assert(nums);
//	//��ͷ������������
//	//���������val�ĸ��������֮���ƶ��ڴ������һ��val��
//	int i = 0;
//	int destination = 0;
//	int destSize = 0;
//	int sourse = 0;
//	int sourseSize = 0;
//
//	int retSize = 0;
//
//	//unsigned char ��Ϊαbool������ֵ��0��1����
//	unsigned char dest_Bool = 0;
//	unsigned char sourse_Bool = 0;
//	unsigned char ifMove = 0;
//	unsigned char moveDistanceOK = 0;
//
//
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == val)
//		{
//			destSize++;
//			if (moveDistanceOK)
//			{
//				//����ǰ��destSize���룬���ݳ���ΪsourseSize
//				memmove(nums + destination, nums + sourse, sizeof(int) * sourseSize);
//				destination = retSize;;
//				//��ʽ������ռ�
//				MemsetIntBlock(nums + destination, val, destSize);
//				destSize = sourseSize = 0;
//
//				moveDistanceOK = 0;
//				ifMove = 1;
//				sourse_Bool = 0;
//			}
//			else
//			{
//				if (!dest_Bool)
//				{
//					destination = i;
//
//					dest_Bool = 1;
//				}
//				if (sourse_Bool)
//				{
//					sourse = i;
//
//					sourse_Bool = 0;
//				}
//			}
//		}
//		if (nums[i] != val)
//		{
//			if (!sourse_Bool)
//			{
//				sourse = i;
//
//				sourse_Bool = 1;
//			}
//			if (sourse_Bool && !moveDistanceOK && dest_Bool)
//			{
//				//����ǰ�ƾ���ȷ��
//				sourseSize = 0;
//
//				moveDistanceOK = 1;
//			}
//			//ÿ��������valʱretSize++
//			sourseSize++;
//			retSize++;
//		}
//	}
//	//ĩβ����
//	if (!ifMove || sourse_Bool)
//	{
//		if (ifMove && nums[i - 1] == val)
//		{
//			//ֻ�����һλ����Ҫȥ��������ʱ
//			retSize =  numsSize - 1;
//		}
//		else if(sourse_Bool)
//		{
//			//ʣ����δ�ƶ�����ʱ
//			memmove(nums + destination, nums + sourse, sizeof(int) * sourseSize);
//		}
//		else
//		{
//			//û����Ҫ�ƶ�����ʱ
//			// !ifMove
//			retSize = numsSize - destSize;
//		}
//	}
//	return retSize;
//}
//#pragma endregion
//
//#pragma region ˫ָ��˼·
//int removeElement02(int* nums, int numsSize, int val)
//{
//	assert(nums);
//	int* pDest, * pSour;
//	int i = 0;
//	int retSize = 0;
//	pDest = pSour = nums;
//
//	for (i = 0; i < numsSize; i++)
//	{
//		if (*pSour != val)
//		{
//			*(pDest++) = *pSour;
//			retSize++;
//		}
//		pSour++;
//	}
//	return retSize;
//}
//#pragma endregion
////
//
//int main()
//{
//
//	int arr[ARR_SIZE] = { 0, 1, 1, 1, 0, 1, 0, 1, 1, 0 };
//
//	int i = 0;
//	//int newSize = removeElement01(arr, ARR_SIZE, 0);
//	int newSize = removeElement02(arr, ARR_SIZE, 0);
//
//	printf("New arr size = %d\n", newSize);
//
//	//���Ժ��Ե���Ч�ռ��ʼ��
//	MemsetIntBlock(arr + newSize, 0, (10 - newSize));
//
//	for (i = 0; i < newSize; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//����һ���������� nums ,����ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ�����ɾ����������³���

int removeDuplicates(int* nums, size_t numsSize)
{
	int dest = 0, src = 0;

	int dup = *nums;

	while (src < numsSize)
	{
		if (src == 0)
		{
			dup = nums[src];
			dest++;
		}
		else if (dup != nums[src])
		{
			dup = nums[src];
			nums[dest++] = dup;
		}
		src++;
	}
	return dest;
}

int main()
{
	int arr[] = { 0,0,1,1,2,2,3,3,4,4,5,5,6,7,7,7 };

	int newSize = removeDuplicates(arr, sizeof(arr) / sizeof(int));

	int i = 0;

	printf("%d\n", newSize);

	for (i = 0; i < newSize; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}