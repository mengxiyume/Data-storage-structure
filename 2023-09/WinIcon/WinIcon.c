#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include"resource.h"

HINSTANCE g_hMainInstance;

void MessageProc_WM_CHAR(HWND hWnd, WPARAM wParam)
{
	switch (wParam)
	{
		//����Сͼ��
	case '1':
		//SetClassLongPtr(hWnd, GCLP_HICONSM, (LONG)LoadIcon(g_hMainInstance, (LPCTSTR)MAKEINTRESOURCE(IDI_FEATHER)));
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(g_hMainInstance, (LPTSTR)MAKEINTRESOURCE(IDI_FEATHER)));		//����ʹ�� WM_SETICON ��Ϣ,SetClassLongPtr������̫�ȶ�
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
	//�ַ���Ϣ����
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

	//ע�ᴰ����
	WNDCLASSEX wcEx = { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = mainWndClassName;
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
	wcEx.hInstance = hInstance;
	//wcEx.hIconSm = LoadIcon(NULL, (LPCTSTR)GetStockObject((int)IDI_SHIELD));
	wcEx.hIcon = LoadImage(hInstance, (LPCTSTR)MAKEINTRESOURCE(IDI_FEATHER), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_DEFAULTCOLOR);
	wcEx.hIconSm = LoadImage(NULL, TEXT("./Smile.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_DEFAULTCOLOR | LR_LOADFROMFILE);		//�ǳ����ڲ���Դ�������������Ϣ LR_LOADFROMFILE
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wcEx);

	//��ʾ����
	hMainWindow = CreateWindowEx(WS_EX_ACCEPTFILES, mainWndClassName, mainWndName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500, NULL, NULL, hInstance, NULL);
	ShowWindow(hMainWindow, SW_SHOW);
	UpdateWindow(hMainWindow);

	//��Ϣѭ��
	while (TRUE)
	{
		if (PeekMessage(&userMessage, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&userMessage, NULL, 0, 0))
			{
				//��Ϣ�ַ��뷭��
				TranslateMessage(&userMessage);
				DispatchMessage(&userMessage);
			}
			else
			{
				//��⵽�Ƴ���Ϣ���˳�����
				break;
			}
		}
		else
		{
			//��Ⱦ
		}
	}

	UnregisterClass(mainWndClassName, hInstance);
	return 0;
}