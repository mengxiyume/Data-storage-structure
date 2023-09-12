#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include<tchar.h>
#include<windowsx.h>

typedef struct DisplayData {
	POINT mousePosition;
}DisplayData;

void MessageProc_WM_PAINT(HWND hWnd, DisplayData dp)
{
	RECT clientRect = { 0 };
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);
	TCHAR szTextBuffer[1024] = { 0 };

	GetClientRect(hWnd, &clientRect);

	wsprintf(szTextBuffer, TEXT("鼠标X:%d 鼠标Y:%d"), dp.mousePosition.x, dp.mousePosition.y);
	DrawTextEx(hdc, szTextBuffer, _tcslen(szTextBuffer), &clientRect, DT_CENTER | DT_VCENTER, NULL);

	EndPaint(hWnd, &ps);
}

DisplayData MessageProc_WM_MOUSEMOVE(HWND hWnd, LPARAM lParam)
{
	DisplayData dp = { 0 };
	dp.mousePosition.x = GET_X_LPARAM(lParam);
	dp.mousePosition.y = GET_Y_LPARAM(lParam);
	InvalidateRect(hWnd, NULL, TRUE);
	return dp;
}

void MessageProc_WM_KEYDOWN(HWND hWnd, WPARAM wParam)
{
	int cScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int cScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	int cMouseMoveDistance = (cScreenWidth < cScreenHeight ? cScreenWidth : cScreenHeight) / 300;
	
	//模拟鼠标消息
	switch (wParam)
	{
	case 'A':
		mouse_event(MOUSEEVENTF_MOVE, -cMouseMoveDistance, 0, 0, NULL);
		break;
	case 'W':
		mouse_event(MOUSEEVENTF_MOVE, 0, -cMouseMoveDistance, 0, NULL);
		break;
	case 'S':
		mouse_event(MOUSEEVENTF_MOVE, 0, cMouseMoveDistance, 0, NULL);
		break;
	case 'D':
		mouse_event(MOUSEEVENTF_MOVE, cMouseMoveDistance, 0, 0, NULL);
		break;
	case VK_SPACE:
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
	}
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	static DisplayData dp = { 0 };

	switch (msgID)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, 0, 0);
		return 0;
	case WM_KEYDOWN:
		MessageProc_WM_KEYDOWN(hWnd, wParam);
		return 0;
	case WM_MOUSEMOVE:
		dp = MessageProc_WM_MOUSEMOVE(hWnd, lParam);
		return 0;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd, dp);
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

	//注册窗口类
	WNDCLASSEX wcEx = { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = mainWndClassName;
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
	wcEx.hInstance = hInstance;
	wcEx.hIconSm = LoadIcon(NULL, (LPCTSTR)GetStockObject((int)IDI_SHIELD));
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