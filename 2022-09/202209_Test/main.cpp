#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include"Sales_item.h"

int main()
{
	/*
	* C++标准规定类型最小数据宽度
	* bool				* 布尔类型				* 未定义
	* char				* 字符					* 8位
	* wchar_t			* 宽字符				* 16位
	* char16_t			* Unicode字符			* 16位
	* char32_t			* Unicode字符			* 32位
	* short				* 短整型				* 16位
	* int				* 整型					* 16位
	* long				* 长整型				* 32位
	* long long			* 长整型				* 64位
	* float				* 单精度浮点数			* 6位有效数字
	* double			* 双精度浮点数			* 10位有效数字
	* long double		* 扩展双精度浮点数		* 10位有效数字
	*/
	
	return 0;
}

//int main()
//{
//	Sales_item total;
//	if (std::cin >> total)
//	{
//		Sales_item trans;
//		while (std::cin >> trans)
//		{
//			if (total.isbn() == trans.isbn())
//			{
//				total += trans;
//			}
//			else
//			{
//				std::cout << total << std::endl;
//				total = trans;
//			}
//		}
//		std::cout << total << std::endl;
//	}
//	else
//	{
//		std::cout << "NO data ?!" << std::endl;
//		return -1;
//	}
//	return 0;
//}

//struct S
//{
//	int a;
//	int b;
//	char ch[256];
//};
//
//int main()
//{
//	//int* a = new int;
//	//delete a;
//	//a = NULL;
//	//struct S* s = new struct S;
//
//	//s->a = 100;
//	//s->b = 200;
//	//memcpy(s->ch, "Hello world\n", strlen("Hello world\n") + 1);
//
//	//printf(s->ch);
//	//delete s;
//	//s = NULL;
//
//	//char* memry = new char[4 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024];
//	//if (!memry)
//	//{
//	//	std::cout << "NO MEMRY" << std::endl;
//	//	return NULL;
//	//}
//	//else
//	//{
//	//	std::cout << (int*)memry << std::endl;
//	//}
//
//	return 0;
//}