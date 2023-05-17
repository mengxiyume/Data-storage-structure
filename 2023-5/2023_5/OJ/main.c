#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>

#define ARR_SIZE 10

////给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度
//
////将一片内存空间以 int 的写入形式写入 value内容
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
//#pragma region	自己思考的思路
//int removeElement01(int* nums, int numsSize, int val)
//{
//	assert(nums);
//	//从头遍历整个数组
//	//计算相隔的val的个数，间隔之后移动内存块至第一个val处
//	int i = 0;
//	int destination = 0;
//	int destSize = 0;
//	int sourse = 0;
//	int sourseSize = 0;
//
//	int retSize = 0;
//
//	//unsigned char 均为伪bool，其真值以0或1代替
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
//				//数据前移destSize距离，数据长度为sourseSize
//				memmove(nums + destination, nums + sourse, sizeof(int) * sourseSize);
//				destination = retSize;;
//				//格式化多余空间
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
//				//数据前移距离确定
//				sourseSize = 0;
//
//				moveDistanceOK = 1;
//			}
//			//每次遇到非val时retSize++
//			sourseSize++;
//			retSize++;
//		}
//	}
//	//末尾处理
//	if (!ifMove || sourse_Bool)
//	{
//		if (ifMove && nums[i - 1] == val)
//		{
//			//只有最后一位是需要去除的数据时
//			retSize =  numsSize - 1;
//		}
//		else if(sourse_Bool)
//		{
//			//剩下有未移动数据时
//			memmove(nums + destination, nums + sourse, sizeof(int) * sourseSize);
//		}
//		else
//		{
//			//没有需要移动数据时
//			// !ifMove
//			retSize = numsSize - destSize;
//		}
//	}
//	return retSize;
//}
//#pragma endregion
//
//#pragma region 双指针思路
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
//	//可以忽略的无效空间初始化
//	MemsetIntBlock(arr + newSize, 0, (10 - newSize));
//
//	for (i = 0; i < newSize; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//给你一个有序数组 nums ,请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度

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