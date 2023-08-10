#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<assert.h>

#define InputBufferSize 0xFFFF

void MessageProc_WM_KEYDOWN(WPARAM wParam)
{
	if (wParam == 'A') {
		if ((((unsigned short)GetKeyState(VK_SHIFT) >> 8) >= 1) && ((unsigned short)GetKeyState(VK_CAPITAL) == 0) ||
			(((unsigned short)GetKeyState(VK_SHIFT) >> 8) == 0) && ((unsigned short)GetKeyState(VK_CAPITAL) >= 1)) {
			MessageBox(NULL, TEXT("A"), NULL, MB_OK);
		}
		else{
			MessageBox(NULL, TEXT("a"), NULL, MB_OK);
		}
	}
}

void MessageProc_WM_CREATE(LPTCH* lpTextArr)
{
	TCHAR* szTextBuffer = (TCHAR*)malloc(sizeof(TCHAR) * InputBufferSize);
	assert(szTextBuffer);
	ZeroMemory(szTextBuffer, InputBufferSize);
	*lpTextArr = szTextBuffer;
}

void MessageProc_WM_CHAR(LPTCH buffer, HWND hWnd, WPARAM wParam, int* nCaretPosX, int* nCaretPosY)
{
	int i = 0;

	static int nChIndex = 0;	//最后一个字符的索引
	TEXTMETRIC tm = { 0 };
	int curCharHeight = 0;
	int curCharWidth = 0;
	TCHAR ch = (TCHAR)wParam;

	HDC hDC = GetDC(hWnd);
	GetTextMetrics(hDC, &tm);
	GetCharWidth32(hDC, (UINT)ch, (UINT)ch, &curCharWidth);
	curCharHeight = tm.tmHeight;

	switch (wParam)
	{
	case '\b':
		break;	//退格
	case '\n':
		break;	//换行
	case 0x1B:
		return 0;	//Esc
	case '\t':
		for (i = 0; i < 4; i++)
			SendMessage(hWnd, WM_CHAR, ' ', 0);
	case '\r':
		buffer[nChIndex++] = '\r';
		*nCaretPosX = 0;
		*nCaretPosY += curCharHeight;
		break;
	default:
		buffer[nChIndex++] = (TCHAR)wParam;
		*nCaretPosX += curCharWidth;
		SetCaretPos(*nCaretPosX, *nCaretPosY);
		break;
	}
	InvalidateRect(hWnd, NULL, TRUE);
	ReleaseDC(hWnd, hDC);
}

void MessageProc_WM_SETFOCUS(HWND hWnd, int nCaretPosX, int nCaretPosY)
{
	HDC hDC = GetDC(hWnd);
	TEXTMETRIC tm = { 0 };
	GetTextMetrics(hDC, &tm);

	CreateCaret(hWnd, (HBITMAP)1, 2, tm.tmHeight);
	ShowCaret(hWnd);
	SetCaretPos(nCaretPosX, nCaretPosY);
}

void MessageProc_WM_KILLFOCUS(hWnd)
{
	HideCaret(hWnd);
	DestroyCaret();
}

void MwssageProc_WM_PAINT(HWND hWnd,LPTCH lpTextArr)
{
	PAINTSTRUCT ps = { 0 };
	HDC hDC = BeginPaint(hWnd, &ps);
	RECT rectUse = { 0 };
	GetClientRect(hWnd, &rectUse);

	DrawText(hDC, lpTextArr, -1, &rectUse, DT_LEFT);

	EndPaint(hWnd, &ps);

}

LRESULT	CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	static TCHAR* szTextBuffer = NULL;
	static int nCaretPosX = 0;
	static int nCaretPosY = 0;

	switch (msgID)
	{
	case WM_DESTROY:
		//结束程序
		PostMessage(hWnd, WM_QUIT, 0, 0);
		break;
	case WM_KEYDOWN:
		MessageProc_WM_KEYDOWN(wParam);
		break;
	case WM_CREATE:
		MessageProc_WM_CREATE(&szTextBuffer);
		break;
	case WM_CHAR:
		MessageProc_WM_CHAR(szTextBuffer, hWnd, wParam, &nCaretPosX, &nCaretPosY);
		break;
	case WM_SETFOCUS:
		MessageProc_WM_SETFOCUS(hWnd, nCaretPosX, nCaretPosY);
		break;
	case WM_KILLFOCUS:
		MessageProc_WM_KILLFOCUS(hWnd);
		break;
	case WM_PAINT:
		MwssageProc_WM_PAINT(hWnd,szTextBuffer);
		break;
	default:
		//默认处理
		return DefWindowProc(hWnd, msgID, wParam, lParam);
		break;
	}

	return 0;
}

int	CALLBACK WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPTSTR lpCmdLine, int cmdShow)
{
	TCHAR className[] = TEXT("TheClass");
	TCHAR windowName[] = TEXT("This is a Window");
	HWND hMainWnd = NULL;
	MSG userMsg = { 0 };

	WNDCLASSEX wcExMain = { 0 };
	//注册主窗口类
	wcExMain.cbSize = sizeof(WNDCLASSEX);
	wcExMain.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcExMain.lpfnWndProc = MainWndProc;
	wcExMain.hInstance = hIns;
	wcExMain.lpszClassName = className;
	wcExMain.hbrBackground = CreateSolidBrush(0xCCCCCC);
	wcExMain.hIconSm = LoadIcon(NULL, IDI_SHIELD);
	RegisterClassEx(&wcExMain);

	//创建显示窗口
	hMainWnd = CreateWindowEx(WS_EX_ACCEPTFILES, className, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, hIns, NULL);
	ShowWindow(hMainWnd, SW_SHOW);
	UpdateWindow(hMainWnd);

	//消息循环
	while (TRUE)
	{
		if (PeekMessage)
		{
			//获取消息
			if (GetMessage(&userMsg, NULL, 0, 0))
			{
				TranslateMessage(&userMsg);
				DispatchMessage(&userMsg); 
			}
			else
			{
				break;
			}
		}
		else
		{
			//渲染
		}
	}

	UnregisterClass(className, hIns);
	return 0;
}