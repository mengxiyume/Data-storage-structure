#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include<math.h>
#include<tchar.h>
#include<assert.h>

int g_nWatchRadius = 200;			//����ֱ��
int g_nTimeAlignmentDifference = 50;	//������
int g_nTimeAlignmentTolerance = 80;	//�����ݲ�
int g_nAngleMax = 360;

DOUBLE PI = 3.1415926;
SYSTEMTIME st = { 0 };

#define ID_TIMER_TIMEALIGNMENT 1	//��ϵͳʱ�����
#define ID_TIMER_UPDATETIME 2		//ˢ�¼�ʱ��


void CALLBACK MainTimerProc(HWND hWnd,UINT uMsg,UINT_PTR idEvent,DWORD dwTime)
{

	switch (idEvent)
	{
	case ID_TIMER_TIMEALIGNMENT:
		GetSystemTime(&st);
		InvalidateRect(hWnd, NULL, TRUE);
		if (abs(st.wMilliseconds - g_nTimeAlignmentTolerance / 2) <= g_nTimeAlignmentDifference)	//��ʱ���и����Ҫ���ʱ��Ϊ�ݲ��ڵĶ���
		{
			KillTimer(hWnd, ID_TIMER_TIMEALIGNMENT);
			SetTimer(hWnd, ID_TIMER_UPDATETIME, 1000, MainTimerProc);		//������ɣ���ʼ��ȷ��ʱ
		}

		break;
	case ID_TIMER_UPDATETIME:
		GetSystemTime(&st);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	default:
		break;
	}
}

void MessageProc_WM_CREATE(HWND hWnd)
{
	//�и�һ��Բ�εĴ���
	HRGN hWindowRgn = { 0 };
	hWindowRgn = CreateEllipticRgn(0, 0, g_nWatchRadius * 2, g_nWatchRadius * 2);
	SetWindowRgn(hWnd, hWindowRgn, TRUE);
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	//��ʱ����ϵͳʱ�����
	SetTimer(hWnd, ID_TIMER_TIMEALIGNMENT, g_nTimeAlignmentDifference, MainTimerProc);
	GetSystemTime(&st);
}

void DrawDots(HDC hdc)
{
	int x = 0, y =0;
	int nAngle = 0;
	int nDotRadius = 0;

	RECT rect = { 0 };
	rect.left = 0;
	rect.right = g_nWatchRadius * 2;
	rect.top = 0;
	rect.bottom = g_nWatchRadius * 2;

	HBRUSH hBrush = SelectObject(hdc, CreateSolidBrush(0x000000));
	HPEN hPen = SelectObject(hdc, CreatePen(PS_NULL, 1, 0x000000));

	//����ƽ��Ϊ60��
	for (nAngle = 0; nAngle < g_nAngleMax; nAngle += g_nAngleMax / 60)
	{
		x = g_nWatchRadius + (int)((g_nWatchRadius - g_nWatchRadius / 15.0) * sin(PI * 2 * nAngle / g_nAngleMax));
		y = g_nWatchRadius - (int)((g_nWatchRadius - g_nWatchRadius / 15.0) * cos(PI * 2 * nAngle / g_nAngleMax));

		nDotRadius = nAngle % 5 ? g_nWatchRadius / 70 : g_nWatchRadius / 35;
		Ellipse(hdc, x - nDotRadius, y - nDotRadius, x + nDotRadius, y + nDotRadius);
	}
	
	DeleteObject(SelectObject(hdc, hBrush));
	DeleteObject(SelectObject(hdc, hPen));
}

void DrawHand(HDC hdc, int nLen, int nAngle)
{
	POINT p[2] = { 0 };

	//����β
	p[0].x = g_nWatchRadius - nLen / 10 * sin(PI * 2 * nAngle / g_nAngleMax);
	p[0].y = g_nWatchRadius + nLen / 10 * cos(PI * 2 * nAngle / g_nAngleMax);

	//����ͷ
	p[1].x = g_nWatchRadius + nLen * sin(PI * 2 * nAngle / g_nAngleMax);
	p[1].y = g_nWatchRadius - nLen * cos(PI * 2 * nAngle / g_nAngleMax);

	assert(Polyline(hdc, p, _countof(p)));
}

void MessageProc_WM_PAINT(HWND hWnd)
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);
	HPEN hPen = NULL;

	DrawDots(hdc);

	hPen = SelectObject(hdc, CreatePen(PS_SOLID, g_nWatchRadius / 100, 0x000000));
	DrawHand(hdc, g_nWatchRadius * 7 / 8, g_nAngleMax / 60 * st.wSecond);		//����
	DeleteObject(SelectObject(hdc, CreatePen(PS_SOLID, g_nWatchRadius / 50, 0x000000)));
	DrawHand(hdc, g_nWatchRadius * 5 / 8, g_nAngleMax / 60 * st.wMinute);		//����
	DeleteObject(SelectObject(hdc, CreatePen(PS_SOLID, g_nWatchRadius / 25, 0x000000)));
	DrawHand(hdc, g_nWatchRadius * 3 / 8, g_nAngleMax / 60 * st.wHour % 12);		//ʱ��
	DeleteObject(SelectObject(hdc, SelectObject(hdc, hPen)));
	EndPaint(hWnd, &ps);
}

void MessageProc_WM_DESTROY(HWND hWnd)
{
	PostMessage(hWnd, WM_QUIT, 0, 0);
	KillTimer(hWnd, ID_TIMER_UPDATETIME);
}

void MessageProc_WM_LBUTTONDOWN(HWND hWnd)
{
	SetCursor(LoadCursor(NULL, IDC_HAND));
	SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, NULL);
	SetCursor(LoadCursor(NULL, IDC_ARROW));
}

void MessageProc_WM_RBUTTONDBLCLK(HWND hWnd)
{
	PostMessage(hWnd, WM_QUIT, 0, 0);
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{

	switch (msgID)
	{
	case WM_DESTROY:
		MessageProc_WM_DESTROY(hWnd);
		return 0;
	case WM_CREATE:
		MessageProc_WM_CREATE(hWnd);
		return 0;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd);
		return 0;
	case WM_LBUTTONDOWN:
		MessageProc_WM_LBUTTONDOWN(hWnd);
		return 0;
	case WM_RBUTTONDBLCLK:
		MessageProc_WM_RBUTTONDBLCLK(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, msgID, wParam, lParam);
	}

	return 0;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow)
{
	TCHAR mainWndClassName[] = TEXT("The Main Window Class");
	TCHAR mainWndName[] = TEXT("The Window");
	MSG userMessage = { 0 };
	HWND hMainWindow = NULL;

	//ע�ᴰ����
	WNDCLASSEX wcEx = { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = mainWndClassName;
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
	wcEx.hInstance = hInstance;
	wcEx.hIconSm = LoadIcon(NULL, (LPCTSTR)GetStockObject((int)IDI_SHIELD));
	wcEx.hCursor = GetStockObject(IDC_ARROW);
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wcEx);

	//��ʾ����
	hMainWindow = CreateWindowEx(WS_EX_ACCEPTFILES, mainWndClassName, mainWndName, WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, g_nWatchRadius * 2, g_nWatchRadius * 2, NULL, NULL, hInstance, NULL);
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