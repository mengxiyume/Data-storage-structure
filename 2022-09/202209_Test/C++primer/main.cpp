#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include"Sales_item.h"

int main()
{
	Sales_item total;
	if (std::cin >> total)
	{
		Sales_item trans;
		while (std::cin >> trans)
		{
			if (total.isbn() == trans.isbn())
			{
				total += trans;
			}
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else
	{
		std::cout << "NO data ?!" << std::endl;
		return -1;
	}
	return 0;
}

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