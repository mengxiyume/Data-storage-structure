#define _CRT_SECURE_NO_WARNINGS 1

#define ID_TIME_S_TIMER 1

#include<Windows.h>
#include<tchar.h>

SYSTEMTIME g_systemTime = { 0 };
SYSTEMTIME g_localTime = { 0 };

void CALLBACK MainTimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	switch (idEvent)
	{
	case ID_TIME_S_TIMER:
		GetSystemTime(&g_systemTime);
		GetLocalTime(&g_localTime);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
}

void MessageProc_WM_CREATE(HWND hWnd)
{
	GetSystemTime(&g_systemTime);
	GetLocalTime(&g_localTime);
	SetTimer(hWnd, ID_TIME_S_TIMER, 1000, MainTimerProc);
}

void MessageProc_WM_PAINT(HWND hWnd)
{
	PAINTSTRUCT ps = { 0 };
	RECT clientRect = { 0 };
	TCHAR szTextBuffer[1024] = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);
	
	GetClientRect(hWnd, &clientRect);
	
	clientRect.bottom = clientRect.bottom / 2;
	wsprintf(szTextBuffer, TEXT("UTD:年%d月%d日%d时%d分%d秒%d"), g_systemTime.wYear, g_systemTime.wMonth, g_systemTime.wDay, g_systemTime.wHour, g_systemTime.wMinute, g_systemTime.wSecond);
	DrawTextEx(hdc, szTextBuffer, _tcslen(szTextBuffer), &clientRect, DT_VCENTER | DT_CENTER | DT_SINGLELINE, NULL);

	clientRect.top = clientRect.bottom;
	clientRect.bottom = clientRect.bottom * 2;
	wsprintf(szTextBuffer, TEXT("UDT+8:年%d月%d日%d时%d分%d秒%d"), g_localTime.wYear, g_localTime.wMonth, g_localTime.wDay, g_localTime.wHour, g_localTime.wMinute, g_localTime.wSecond);
	DrawTextEx(hdc, szTextBuffer, _tcslen(szTextBuffer), &clientRect, DT_VCENTER | DT_CENTER | DT_SINGLELINE, NULL);

	EndPaint(hWnd, &ps);
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{

	switch (msgID)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, 0, 0);
		return 0;
	case WM_CREATE:
		MessageProc_WM_CREATE(hWnd);
		return 0;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd);
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