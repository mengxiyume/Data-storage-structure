#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <Windows.h>

//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。

void init(int arr[], size_t sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[], size_t sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void reverse(int arr[], size_t sz)
{
	int i = 0;

	//折半，调换
	for (i = 0; i < (sz + 1) / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[sz - i - 1];
		arr[sz - i - 1] = temp;
	}
}

void Test_15()
{
	printf("TEST_15_OUT\n");

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(arr, _countof(arr));

	reverse(arr, _countof(arr));
	print(arr, _countof(arr));

	init(arr, _countof(arr));
	print(arr, _countof(arr));
}

unsigned char is_prime(int x)
{

	//i的开方就是a*b的最中间值
	int n = (int)sqrt(x);

	int i = 0;
	//3到中间值为止都不能被整除则为素数
	for (i = 3; i <= n; i += 2)
	{
		if (x % i == 0)
		{
			//能被3到中间值中的任意一个属整除则不为素数
			return 0;
		}
	}
	return 1;
}

unsigned char IsLeapYear(int year)
{
	//闰年返回1，不是闰年返回0
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void PutMulTable(int x, int y)
{
	//打印乘法口诀表，x与y确定范围
	int i = 0;
	for (i = 1; i <= x; i++)
	{
		int j = 0;
		for (j = i; j <= y || j <= x; j++)
		{
			printf("%d x %d = %d ", j, i, i * j);
		}
		putchar('\n');
		//打印完一行换行
	}
}

void Test_14()
{
	printf("TEST_14_OUT\n");

	//int year = 0;
	////PutMulTable(12, 10);
	//while (EOF != scanf("%d", &year))
	//{
	//	if (IsLeapYear(year))
	//	{
	//		printf("%d 是闰年\n", year);
	//	}
	//	else
	//	{
	//		printf("%d 不是闰年\n", year);
	//	}
	//}

	int i = 0;
	for (i = 101; i < 200; i += 2)
	{
		if (is_prime(i))
		{
			printf("%d ", i);
		}
	}

}

//数组名时首元素的地址，参数arr的类型为 int [] 它可以直接访问原数组的内容并更改
void swap(int arr[])
{
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void Test_13()
{
	printf("TEST_13_OUT\n");

	int arr[] = { 1, 2 };

	swap(arr);

	printf("%d %d", arr[0], arr[1]);

}

void PutArr(int arr[], size_t sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//交换两个数组内容，两个数组大小相同
void Test_12()
{
	printf("TEST_12_OUT\n");

	int i = 0;

	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("arr1:");
	PutArr(arr1, _countof(arr1));
	printf("arr2:");
	PutArr(arr2, _countof(arr2));
	printf("\n\n");

	for (i = 0; i < _countof(arr1); i++)
	{
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}

	printf("arr1:");
	PutArr(arr1, _countof(arr1));
	printf("arr2:");
	PutArr(arr2, _countof(arr2));
}

void Test_11()
{
	printf("TEST_11_OUT\n");

	//输入十个数值，输出平均值

	int arr[10] = { 0 };

	int sum = 0;

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 10; i++)
	{
		sum += arr[i];
	}

	printf("%f\n", sum / 10.0);
}

void Test_10()
{
	printf("TEST_10_OUT\n");
	int a = 0, b = 0;
	int temp = 0;

	scanf("%d%d", &a, &b);

	//确保开始时a中的数值比b大
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	//辗转相除法，b除尽时a的值就为最大公因数
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	printf("%d\n", a);
}

void Test_09()
{
	printf("TEST_09_OUT\n");

	//打印1~100之间的所有素数
	int i = 0;

	//能与2整除的都不是素数，所以每次增加的数值为2

	for (i = 3; i < 100; i += 2)
	{
		//i的开方就是a*b的最中间值
		int n = (int)sqrt(i);
		int j = 0;

		//从第一个素数开始尝试整除到中间值
		for (j = 3; j < n; j += 2)
		{
			if (i % j == 0)
			{
				continue;
			}
		}
		printf("%d ", i);
	}

}

#define SETUP_COUNT 5

void GuessNumber()
{
	srand((unsigned int)time(NULL) + (unsigned int)GetTickCount64());

	const int nGuessNumber = rand() % 100;
	int nSetup = 0;

	printf("请您猜一个 0~100 之间的数值\n我们将给您提示,但您只有 %d 次机会:>", SETUP_COUNT);

	while (nSetup < SETUP_COUNT)
	{
		int nUserNumber = 0;
		scanf("%d", &nUserNumber);

		if (nUserNumber < 0 || nUserNumber > 100)
		{
			printf("输入不合法\n");
			continue;
		}
		else if (nGuessNumber < nUserNumber)
		{
			printf("你猜的数字大了\n");
		}
		else if (nGuessNumber > nUserNumber)
		{
			printf("你猜的数字小了\n");
		}
		else
		{
			printf("You are Win !!!\nSteup is %d\n", nSetup);
			break;
		}

		printf(":>");
		nSetup++;
	}
	
	if (nSetup == SETUP_COUNT)
	{
		printf("\n菜\n答案是%d\n", nGuessNumber);
	}
}

void PutTest_08_Menu()
{
	printf("—————————————————\n");
	printf("—1.Play———0.Quit—\n");
	printf("—————————————————\n");
}

void Test_08()
{
	printf("TEST_08_OUT\n");

	int input = 0;
	do {
		PutTest_08_Menu();
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			GuessNumber();
			break;
		default:
			break;
		}
	} while (input);

}

//编写程序数一下 1到 100 的所有整数中出现多少个数字9

signed long long FindValueUnsignedNumbersStaringFromZero	//求从0开始到end这个区间内nFindValue在每一位出现的次数，进制数为nBaseValue
(	const unsigned int end,										//范围结束限定值
	const unsigned int nFindValue,								//需要寻找的数值
	const unsigned int nBaseValue								//进制，不能小于2
){
	assert(nBaseValue >= 2);			//进制不萌小于2，这是无意义的

	signed int nTempDigit = 1;
	signed int nCurNumberEnd = abs(end);

	signed int nDigitNextNumber = 0;
	signed int nDigitPrevNumber = 0;
	signed int nCurrentDigitNumber = 0; 

	signed long long sum = 0;

	//用循环遍历每一位 - 拿到之前位与剩下位进行计算
	while (nCurNumberEnd)
	{
		signed long long nPrevSum = sum;	//溢出判定控制用

		nCurrentDigitNumber = nCurNumberEnd % nBaseValue;			//拿到当前位的数值

		//整体数值 % 当前位位阶 = 之后位数值
		//9 999 % 1000 = 999
		//99 99 % 100 = 99
		//999 9 % 10 = 9
		//9999  % 0 = 0
		nDigitNextNumber = (nTempDigit >= nBaseValue) ? (end % nTempDigit) : 0;							//拿到之后位的数值

		//整体数值 / (当前位的前一位的位阶) = 之前位数值
		//999 9  / 10 = 999
		//99 9 9 / 100 = 99
		//9 9 99 / 1000 = 9
		// 9 999 / 1000 = 0
		nDigitPrevNumber = end / (nBaseValue * nTempDigit);		//拿到之前位的数值

		//计算
		{

			//每一位需要统计出现次数的数值出现的次数都为三部分组成
			//之前位和：以当前位的位阶为之前位最低位的位阶；2999，当前位为十位，之前位和为290
			//当前位和：如果当前位数值大于需查询的数值，则为一个进制基本值，如十进制为10；2999，当前位为十位9，需查询数值为3，进制为10，当前位和位为10
			//之后位和：如果当前位数值等于需查询的数值，则为之后位和的数值；2999，当前位为百位9，需查询数值为9，之后位为99

			sum += ((signed long long)nDigitPrevNumber * nTempDigit);						//之前位和
			sum == (nCurrentDigitNumber > nFindValue) ? nBaseValue : 0;					//当前位和
			sum += (nCurrentDigitNumber == nFindValue) ? nDigitNextNumber + 1 : 0;		//剩下位和
		}

		nTempDigit *= nBaseValue;		//进制位阶增加
		nCurNumberEnd /= nBaseValue;		//数值位指向数值段向左移动
		// 1   9  >5<  6 指向数值段为5
		// 1  >9<  5   6 指向数值段为9

		//数据溢出/异常处理
		if (nPrevSum > sum)
		{
			//printf("单项总和溢出上限\n");
			return (signed long long)EOF;
		}
	}

	return sum;
}

signed long long FindValueNumbers(signed int begin, signed int end, const unsigned int nFindValue, const unsigned int nBaseValue)
{
	//正常返回结果值
	//超过longlong的最大值返回EOF

	//进制数有效性确认
	assert(nBaseValue >= 2);

	signed long long nBigSum = 0;
	signed long long nSmallSum = 0;
	signed long long nRetSum = 0;

	//统计begin - 0之间nFindValue出现的次数
	//统计end - 0之间nFindValue出现的次数
	//如果异号，则相加两值，如查找值为0，则将统计值减去1，但开始、结束、查找值都为0时，直接返回1

	//开始与结束都为同一数值的情况，单独计算这一个数值节省算力
	if (begin == end)
	{
		if (nFindValue == begin)
		{
			//查找值等于起始值等于结束值，就只能查找到1个需查找值
			return 1;
		}
		//开始与结束都为同一个值时，统计这个值中nFindValue出现的次数
		signed int temp = begin;
		while (temp > 0)
		{
			if (temp % nBaseValue == nFindValue)
			{
				//统计每一位上出现9的次数
				nRetSum++;
			}
			temp /= nBaseValue;
		}
		return nRetSum;
	}

	if (begin < 0 && end >= 0 || begin >= 0 && end < 0)	//nSum1与nSum2异号，则sum和为绝对值的和
	{
		begin = abs(begin);
		end = abs(end);

		//拿到0到两端的sum
		nBigSum = FindValueUnsignedNumbersStaringFromZero(begin, nFindValue, nBaseValue);
		nSmallSum = FindValueUnsignedNumbersStaringFromZero(end, nFindValue, nBaseValue);

		if ((signed long long)EOF == nBigSum || (signed long long)EOF == nSmallSum)
		{		//算术溢出返回EOF
			return (signed long long)EOF;
		}

		nRetSum = nBigSum + nSmallSum;

		if (nRetSum < nBigSum || nRetSum < nSmallSum)
		{
			//算术溢出返回EOF
			return (signed long long)EOF;
		}

		if (0 == nFindValue)
		{
			//如果查找的数值就是0，那么查找的范围两端异号时会重复查找1次0，需去除
			nRetSum -= 1;
		}
	}
	else		//同号为绝对值大的值减去绝对值少的值
	{
		//排序一下
		begin = abs(begin);
		end = abs(end);

		//进行一个大小的排序
		if (begin > end)
		{
			int temp = begin;
			begin = end;
			end = temp;
		}

		//统计begin~end之间9的数量 0~end - 0~(begin - 1)
		if (begin > 0)
		{
			begin -= 1;
		}

		//获取到两头的数值的数量
		nBigSum = FindValueUnsignedNumbersStaringFromZero(begin, nFindValue, nBaseValue);
		nSmallSum = FindValueUnsignedNumbersStaringFromZero(end, nFindValue, nBaseValue);

		if ((signed long long)EOF == nBigSum|| (signed long long)EOF == nSmallSum)
		{		//算术溢出返回EOF
			return (signed long long)EOF;
		}

		nRetSum = nSmallSum - nBigSum;		//拿到绝对值大的与绝对值小的sum，用大的减去小的得到区间内的和
	}

	return nRetSum;	//返回值为大值减去小值
}

signed long long FindValueNumbers_Test(signed int begin, signed int end, const unsigned int nFindValue, const unsigned int nBaseValue)
{
	signed int i = 0;
	signed long long sum = 0;

	//先对数据排序，再进行计算
	signed int temp = begin;
	if (begin > end)
	{
		begin = end;
		end = temp;
	}

	//穷举法
	for (i = begin; i <= end; i++)
	{
		signed int tempI = abs(i);
		while (tempI > 0)
		{
			if (tempI % nBaseValue == nFindValue)
			{
				sum++;
			}
			tempI /= nBaseValue;
		}
	}

	return sum;
}

void Test_07()
{

	printf("TEST_07_OUT\n");

	const unsigned int nFindValue = 9;
	const unsigned int nBaseValue = 10;

	signed int begin = 0;
	signed int end = 0;

	char szBegin[] = "你好";
	char szEnd[] = "世界";

	begin = -(*((signed int*)szBegin));
	end = *((signed int*)szEnd);


	printf("计数法： %d ~ %d 之间 %d 出现的次数是 %lld\n", begin, end, nFindValue, FindValueNumbers(begin, end, nFindValue, nBaseValue));
	printf("穷举法： %d ~ %d 之间 %d 出现的次数是 %lld\n", begin, end, nFindValue, FindValueNumbers_Test(begin, end, nFindValue, nBaseValue));

}

void Test_06()
{

	printf("TEST_06_OUT\n");

	const unsigned int nFindValue = 9;
	const unsigned int nBaseValue = 10;

	signed int begin = 0;
	signed int end = 0;

	while (1)
	{
		printf("请依次输入 begin 与 end\n");
		if (EOF == scanf("%d%*c%d", &begin, &end))
		{
			return;
		}

		printf("计数法： %d ~ %d 之间 %d 出现的次数是 %lld\n", begin, end, nFindValue, FindValueNumbers(begin, end, nFindValue, nBaseValue));
		printf("穷举法： %d ~ %d 之间 %d 出现的次数是 %lld\n", begin, end, nFindValue, FindValueNumbers_Test(begin, end, nFindValue, nBaseValue));
	}

}

void Test_05()
{
	printf("TEST_05_OUT\n");

	int i = 0;

	const int begin = 1;
	const int end = 100;
	int nFindNumber = 9;
	const int nBaseNumber = 10;

	long long sum = 0;

	int b = begin;
	int e = end;

	//1 - 100 9的个数
	//百位0个
	//十位 - 90 91 ... 98 99 10个9
	//个位 - 9 19 ... 89 99 10个9
	
	//1 - 1000 9的个数为
	//千位0个
	//百位 - 900 901 ... 998 999 100个9
	//十位 - 90 91 ... 98 99 191 192 ... 998 999 (10 * 10) = 100个9
	//个位 - 9 19 ... 89 99 ... 189 199 ... 989 999 (10 * 10) = 100个9

	//1 - 10000 9的个数
	//万位 0个
	//千位 9000 9001 ... 9998  9999 (10 * 10 * 10) = 1000个9
	//百位 900 901 ... 998 999  1900 1901 ... 9998 (10 * 10 * 10) = 1000个9
	//十位 90 91 ... 99 190 ... 999 1090 ... 9989 9999 (10 * 10 * 10) = 1000个9
	//个位 9 19 ... 99 109 ... 999  1009 ... 9989 9999 (10 * 10 * 10) = 1000个9
	
	//1 - 1999 9的个数
	//千位 0个
	//百位 - 900 901 ... 999 1900 ... 1998 1999 (10 * 10 * 2) = 200个9
	//十位 - 90 91 ... 99 190 ... 999 1090 ... 1998 1999 (10 * 10 * 2) = 200个9
	//个位 - 9 19 ... 99 109 ... 999 1009 ... 1989 1999 (10 * 10 * 2) = 200个9

	//6789 = 6000 + 700 + 80 + 9

	//sum = /*高位 -> 低位*/ /*6000*/ 6 * 300 + /*700*/ 7 * 20 + /*80*/ 8 * 1 + /*9*/ 1 * 1;

	//100 = 百位9的个数 0个 + 十位9的个数 10个 + 个位9的个数 10个
	//200 = 百位9的个数 0个 + 十位9的个数 10 * 2个 + 个位9的个数 10 * 2个
	//...
	//900 = 百位9的个数 1个 + 十位9的个数 10 * 9个 + 个位9的个数 10 * 9个

	//99 = 十位10个9 + 个位10个9
	//95 = 十位6个9 + 个位9个9
	//90 = 十位1个9 + 个位9个9

	//999 = 百位100个9 + 十位100个9 + 个位100个9
	//899 = 百位0个9 + 十位80 + 10 = 90个9 + 个位80 + 10 = 90个9
	//793 = 百位0个9 + 十位70 + 4 = 74个9 + 个位70 + 9 = 79个9
	//7395 = 千位0个9 + 百位700个9 + 十位730 + 6 = 736个9 + 个位739 = 739个9
	//7935 = 千位0个9 + 百位700 + 36 = 736个9 + 十位790个9 + 个位793 = 793个9

	//如果该位不为9，该位上9的个数为之前的位数
	//如果该位为9，该位上9的个数为之前位*当前位权重加上剩下位再加1,如果该位不为9，则不加剩下位与1//
	//9999 = 千位0 * 1000 + (999 + 1) 百位9 * 100 + (99 + 1) 十位99 * 10 + (9 + 1) 个位999 * 1 + (0 + 1)	//4000
	//9998 = 千位0 * 1000 + (998 + 1) 百位9 * 100 + (98 + 1) 十位99 * 10 + (8 + 1) 个位999 * 1 + (0)			//3996
	//9997 = 千位0 * 1000 + (997 + 1) 百位9 * 100 + (97 + 1) 十位99 * 10 + (7 + 1) 个位999 * 1 + (0)			//3993
	//100 = 百位0 * 100 + (0) 十位1 * 10 + (0) 个位10 * 1 + (0)
	//200 = 百位0 * 100 + (0) 十位2 * 10 + (0) 个位20 * 1 + (0)
	//280 = 百位0 * 100 + (0) 十位2 * 10 + (0) 个位28 * 1 + (0)
	//283 = 百位0 * 100 + (0) 十位2 * 10 + (0) 个位28 * 1 + (0)
	//290 = 百位0 * 100 + (0) 十位2 * 10 + (0 + 1) 个位29 * 1 + (0)
	//395 = 百位0 * 100 + (0) 十位3 * 10 + (5 + 1) 个位29 * 1 + (0)

	e = 100;

	//char arr[4] = "卧槽";
	//e = (unsigned int)(*((int*)arr)) & INT_MAX;

	b = e = 99;
	nFindNumber = 9;

	sum = FindValueNumbers(b, e, nFindNumber, nBaseNumber);
	if ((signed long long)EOF == sum)
	{
		printf("算术溢出\n");
		exit(0);
	}

	printf("计数法\n");
	printf("%d - %d 之间的数字 %d 出现的次数为 %llu\n", b, e, nFindNumber, sum);

	sum = 0;

	//穷举法
	for (i = 1; i <= e ;i++)
	{
		int tempI = i;
		while (tempI > 0)
		{
			if (tempI % 10 == 9)
			{
				sum++;
			}
			tempI /= 10;
		}
	}

	printf("穷举法\n");
	printf("%d - %d 之间的数字 %d 出现的次数为 %llu\n", b, e, nFindNumber, sum);
}

//打印1000~2000年之间的闰年
void Test_04()
{
	
	printf("TEST_04_OUT\n");

	int year = 0;

	for (year = 1000; year <= 2000; year++)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			//如果year是闰年，就将它打印到屏幕上
			printf("%d ", year);
		}
	}
}

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
void Test_03()
{
	printf("TEST_03_OUT\n");

	//第一次的结果是加上分数，接下来是减去，如此交替进行
	int flag = 1;
	int i = 0;
	//这个变量存储结果，为了结果尽量准确，所以我使用了double
	double sum = 0;

	for (i = 1; i <= 100; i++)
	{
		//结果加上或减去分数
		sum += (1 / (double)i * flag);
		//让加减交替进行
		flag *= -1;
	}
	printf("1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 = %.16lf", sum);
}

//求十个数中的最大值
void Test_02()
{
	printf("TEST_02_OUT\n");

	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int max = arr[0];

	for (i = 1; i < 10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("The numbers's Max-Number is %d\n", max);
}


//打印乘法口诀表
void Test_01()
{
	printf("TEST_01_OUT\n");

	int i = 0;
	for (i = 9; i >= 1; i--)
	{
		int j = 0;
		for (j = i; j <= 9; j++)
		{
			printf("%d * %d = %-2d  ", i, j, i * j);
		}
		printf("\n");
	}

}

int main()
{
	//Test_01();
	//Test_02();
	//Test_03();
	//Test_04();
	//Test_05();
	//Test_06();
	//Test_07();
	//Test_08();
	//Test_09();
	//Test_10();
	//Test_11();
	//Test_12();
	//Test_13();
	//Test_14();
	Test_15();


	return 0;
}