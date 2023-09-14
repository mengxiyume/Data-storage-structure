#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include"resource.h"

HINSTANCE g_hMainInstance;

void MessageProc_WM_CHAR(HWND hWnd, WPARAM wParam)
{
	switch (wParam)
	{
		//更换小图标
	case '1':
		//SetClassLongPtr(hWnd, GCLP_HICONSM, (LONG)LoadIcon(g_hMainInstance, (LPCTSTR)MAKEINTRESOURCE(IDI_FEATHER)));
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(g_hMainInstance, (LPTSTR)MAKEINTRESOURCE(IDI_FEATHER)));		//建议使用 WM_SETICON 消息,SetClassLongPtr函数不太稳定
		break;
	case '2':
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(g_hMainInstance, (LPTSTR)MAKEINTRESOURCE(IDI_EAGLE)));
		break;
	default:
		break;
	}
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	//分发消息处理
	switch (msgID)
	{
	case WM_CHAR:
		MessageProc_WM_CHAR(hWnd, wParam);
		return 0;
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, 0, 0);
		return 0;
	default:
		return DefWindowProc(hWnd, msgID, wParam, lParam);
	}

	return DefWindowProc(hWnd, msgID, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow)
{
	TCHAR mainWndClassName[] = TEXT("The Main Window Class");
	TCHAR mainWndName[] = TEXT("The Window");
	MSG userMessage = { 0 };
	HWND hMainWindow = NULL;

	g_hMainInstance = hInstance;

	//注册窗口类
	WNDCLASSEX wcEx = { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = mainWndClassName;
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
	wcEx.hInstance = hInstance;
	//wcEx.hIconSm = LoadIcon(NULL, (LPCTSTR)GetStockObject((int)IDI_SHIELD));
	wcEx.hIcon = LoadImage(hInstance, (LPCTSTR)MAKEINTRESOURCE(IDI_FEATHER), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_DEFAULTCOLOR);
	wcEx.hIconSm = LoadImage(NULL, TEXT("./Smile.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_DEFAULTCOLOR | LR_LOADFROMFILE);		//非程序内部资源，请添加掩码信息 LR_LOADFROMFILE
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wcEx);

	//显示窗口
	hMainWindow = CreateWindowEx(WS_EX_ACCEPTFILES, mainWndClassName, mainWndName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500, NULL, NULL, hInstance, NULL);
	ShowWindow(hMainWindow, SW_SHOW);
	UpdateWindow(hMainWindow);

	//消息循环
	while (TRUE)
	{
		if (PeekMessage(&userMessage, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&userMessage, NULL, 0, 0))
			{
				//消息分发与翻译
				TranslateMessage(&userMessage);
				DispatchMessage(&userMessage);
			}
			else
			{
				//监测到推出消息，退出程序
				break;
			}
		}
		else
		{
			//渲染
		}
	}

	UnregisterClass(mainWndClassName, hInstance);
	return 0;
}