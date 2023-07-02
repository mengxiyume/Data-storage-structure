#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<tchar.h>

void MessageProc_WM_PAINT(HWND hWnd)
{
	HDC hdc = NULL;
	PAINTSTRUCT ps = { 0 };
	TCHAR szText[] = TEXT("Hello Windows API!");

	hdc = BeginPaint(hWnd, &ps);

	//绘制
	TextOut(hdc, 10, 10, szText, _tcslen(szText));

	EndPaint(hWnd, &ps);
	hdc = NULL;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, NULL, NULL);		//结束程序
		//PostQuitMessage(0);
		break;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd);
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, TEXT("DBLCLK_Left"), TEXT("Information"), MB_OK);
		break;
	case WM_RBUTTONDBLCLK:
		MessageBox(hWnd, TEXT("DBLCLK_Right"), TEXT("Information"), MB_OK);
		break;
	case WM_MBUTTONDBLCLK:
		MessageBox(hWnd, TEXT("DBLCLK_Middle"), TEXT("Information"), MB_OK);
		break;
	default:
		DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpCmdLine, int nCmdShow)
{
	TCHAR windowClassName[] = TEXT("The Window");
	TCHAR windowName[] = TEXT("This is a Window");
	HWND hWndMain = NULL;
	MSG useMessage = { 0 };

	//注册窗口类
	WNDCLASSEX wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = CreateSolidBrush(0xFFFFFF);		//CreateSolidBrush(0xFFFFFF);
	wc.hCursor = NULL;
	wc.hIcon = LoadIcon(NULL, (LPCTSTR)IDI_SHIELD);
	wc.hIconSm = LoadIcon(NULL, (LPCTSTR)IDI_SHIELD);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = windowClassName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wc);

	//显示窗口
	hWndMain = CreateWindowEx(0, windowClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, hInstance, NULL);
	ShowWindow(hWndMain, nCmdShow);
	UpdateWindow(hWndMain);

	//消息循环
	while (TRUE)
	{
		if (PeekMessage(&useMessage, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&useMessage, NULL, 0, 0))
			{
				exit(0);
			}
			else
			{
				//消息分发
				TranslateMessage(&useMessage);
				DispatchMessage(&useMessage);
			}
		}
		else
		{
			//屏幕刷新 - 自动化运行程序使用
		}
	}

	return 0;
}