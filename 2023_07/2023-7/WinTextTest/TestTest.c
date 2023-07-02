#define _CRT_SECURE_NO_WARNINGS

// _s 安全版本，内存空间安全+

#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<locale.h>
#include<strsafe.h>
#include<assert.h>

void TextTest_01()
{
	TCHAR szStr[] = TEXT("WindowsAPI是最为强大的编程语言！");
	LPTSTR 	lp = _tcsstr(szStr, TEXT("API"));
	setlocale(LC_ALL, "chs");

	_tprintf(TEXT("szStr = %s\nlpStr = %s\n"), szStr, lp);
}

void TextTest_02()
{

	TCHAR szStr[] = TEXT("WindowsAPI是最为强大的编程语言！");
	LPTSTR subStr = _tcschr(szStr, TEXT('编'));
	setlocale(LC_ALL, "chs");

	_tprintf(TEXT("szStr = %s\nlpStr = %s\n"), szStr, subStr);
}

void TextTest_03()
{
	TCHAR szStr[] = TEXT("The 3 men and 2 boys ate 5 pigs");
	TCHAR szStrCharSet[] = TEXT("1234567890");
	LPTSTR lpSearch = _tcspbrk(szStr, szStrCharSet);

	int i = 0;

	while (lpSearch)
	{
		i++;
		_tprintf(TEXT("%d:\t%s\n"),i, lpSearch);
		lpSearch++;
		lpSearch = _tcspbrk(lpSearch, szStrCharSet);
	}

}

void TextTest_04()
{
	TCHAR szStr[] = TEXT("WindowsAPI");

	_tcprintf(szStr);
	printf("\n");

	_tcprintf(TEXT("%s\n"), _tcslwr(szStr));
	_tcprintf(TEXT("%s\n"), _tcsupr(szStr));
}

void TextTest_05()
{
	TCHAR textChar = TEXT('T');

	textChar = _totlower(textChar);
	_puttchar(textChar);

	textChar = _totupper(textChar);
	_puttchar(textChar);
}

void TextTest_06()
{
	TCHAR szStr1[1024] = TEXT("WindowsAPI ");
	TCHAR szStr2[] = TEXT("is vevry good!");

	if (_tcscat_s(szStr1, _countof(szStr1), szStr2))
	{
		printf("Not have more RAM\n");
		exit(0);
	}
	_tcprintf(szStr1);
}

void TextTest_07()
{
	TCHAR szStr1[] = TEXT("1234");
	TCHAR szStr2[] = TEXT("567");

	_tcscpy_s(szStr1, _countof(szStr1), szStr2);
	_tcprintf(szStr1);

}

void TextTest_08()
{
	//TCHAR szStr1[] = TEXT("ABCDe");
	//TCHAR szStr2[] = TEXT("ABCDE");
	// 
	//int cmpRet = _tcscmp(szStr1, szStr2);

	TCHAR szStr1[] = TEXT("你好啊");
	TCHAR szStr2[] = TEXT("你好阿");

	int cmpRet = _tcscoll(szStr1, szStr2);
	if (cmpRet > 0)
	{
		_tcprintf(TEXT("szStr1 > szStr2\n"));
	}
	else if (cmpRet < 0)
	{
		_tcprintf(TEXT("szStr1 < szStr2\n"));
	}
	else
	{
		_tcprintf(TEXT("szStr1 = szStr2\n"));
	}
}

void TextTest_09()
{
	TCHAR strToken[] = TEXT("A string\tof ,,tokens\nand some  more tokens");
	TCHAR strDelimit[] = TEXT(" ,\t\n");
	LPTSTR lpToken = NULL;
	LPTSTR lpTokenNext = NULL;

	_tcprintf(TEXT("%s\n\n"), strToken);
	lpToken = _tcstok_s(strToken, strDelimit, &lpTokenNext);

	while (lpToken)
	{
		_tcprintf(TEXT("%s\n"), lpToken);

		lpToken = _tcstok_s(NULL, strDelimit, &lpTokenNext);
	}
}

int compare(const void* arr1, const void* arr2)
{
	return _tcscoll(*((LPCSTR*)arr1), *((LPCSTR*)arr2));
}

void TextTest_10()
{
	int i = 0;

	LPTSTR arrStr[] = {
		TEXT("架构风格之资源管理.AVI"),
		TEXT("模块化之合理内聚.AVI"),
		TEXT("总结.AVI"),
		TEXT("模块化之管理依赖.AVI"),
		TEXT("系统架构设计概述.AVI"),
		TEXT("架构风格之分布式.AVI")
	};
	setlocale(LC_ALL, "chs");
	qsort(arrStr, _countof(arrStr), sizeof(LPTSTR), compare);


	for (i = 0; i < _countof(arrStr); i++)
	{
		_tcprintf(TEXT("%s\n"), arrStr[i]);
	}
}

void TextTest_11()
{
	int n = 0xFFFFFFFF;
	TCHAR szBuffer[1024] = { 0 };

	//进制显示最高36进制
	_itot_s(n, szBuffer, _countof(szBuffer), 36);
	_tcprintf(szBuffer);
}

void TextTest_12()
{
	//#include<strsafe.h>
	//StringCchPrintf()

	HRESULT hResult = E_FAIL;
	TCHAR szName[] = TEXT("老王");
	TCHAR szAddress[] = TEXT("山东济南");
	int nAge = 18;
	TCHAR szBuffer[1024] = { 0 };

	hResult = StringCchPrintf(szBuffer, _countof(szBuffer), TEXT("姓名:%s\n年龄:%d\n住址:%s\n"), szName, nAge, szAddress);

	if (SUCCEEDED(hResult))
	{
		MessageBox(NULL, szBuffer, TEXT("使用成功"), MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	}
	else
	{
		MessageBox(NULL, TEXT("使用失败"), TEXT("使用失败"), MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
	}
}

void TextTest_13()
{
	LPCSTR lpMultiByteStr = "Windows API 程序设计";

	LPCSTR lpMultiByteStr_1[1024] = { 0 };

	//第一次调用，获得所需缓冲区大小
	int nCchWideChar = MultiByteToWideChar(CP_ACP, 0, lpMultiByteStr, -1, NULL, 0);

	LPWSTR lpWideCharStr = (LPWSTR)malloc(sizeof(WCHAR) * nCchWideChar);
	assert(lpWideCharStr);

	MultiByteToWideChar(CP_ACP, 0, lpMultiByteStr, -1, lpWideCharStr, nCchWideChar);

	MessageBox(NULL, lpWideCharStr, TEXT("caption"), MB_OK | MB_DEFBUTTON1);

	WideCharToMultiByte(CP_ACP, 0, lpWideCharStr, -1, lpMultiByteStr_1, _countof(lpMultiByteStr_1), NULL, NULL);

	MessageBoxA(NULL, lpMultiByteStr_1, "caption", MB_OK | MB_DEFBUTTON1);

	free(lpWideCharStr);
	lpWideCharStr = NULL;
}

void TextTest_14()
{
	//结构体数据对齐
}

int main()
{
	//TextTest_01();
	//TextTest_02();
	//TextTest_03();
	//TextTest_04();
	//TextTest_05();
	//TextTest_06();
	//TextTest_07();
	//TextTest_08();
	//TextTest_09();
	//TextTest_10();
	//TextTest_11();
	//TextTest_12();
	//TextTest_13();
	TextTest_14();

	return 0;
}