#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>

void PaintLine(HWND hWnd)
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);

	POINT arrPtPolyPolyLine[] = {
		110,60, 10,60, 60,10, 160,10,
		10,60, 10,160, 110,160, 110,60, 160,10, 160,110, 110,160,
	};

	DWORD arrGroup[] = { 4,7 };
	POINT arrPtPolyLine[] = { 10,220, 110,200, 210,220 };
	POINT arrPtPolyLineTo[] = { 110,260, 210,240 };
	LOGPEN logPen = { 0 };
	HPEN hPen = NULL;


	SetBkMode(hdc, TRANSPARENT);

	logPen.lopnColor = 0x9CC99C;
	logPen.lopnStyle = PS_SOLID;
	logPen.lopnWidth.x = 5;

	hPen = CreatePenIndirect(&logPen);
	hPen = SelectObject(hdc, hPen);

	//绘制正方体
	PolyPolyline(hdc, arrPtPolyPolyLine, arrGroup, _countof(arrGroup));
	DeleteObject(SelectObject(hdc, hPen));

	logPen.lopnColor = 0x88CC88;
	logPen.lopnStyle = PS_DASH;
	logPen.lopnWidth.x = 1;
	hPen = CreatePenIndirect(&logPen);
	hPen = SelectObject(hdc, hPen);

	//绘制一条划线
	MoveToEx(hdc, 10, 180, NULL);
	LineTo(hdc, 210, 180);
	DeleteObject(SelectObject(hdc, hPen));

	logPen.lopnColor = 0xCC88CC;
	logPen.lopnStyle = PS_DOT;
	hPen = CreatePenIndirect(&logPen);
	hPen = SelectObject(hdc, hPen);

	//绘制一条点线
	Polyline(hdc, arrPtPolyLine, _countof(arrPtPolyLine));
	DeleteObject(SelectObject(hdc, hPen));

	logPen.lopnColor = 0xBB7BB7;
	logPen.lopnStyle = PS_DASHDOTDOT;
	hPen = CreatePenIndirect(&logPen);
	hPen = SelectObject(hdc, hPen);

	MoveToEx(hdc, 10, 240, NULL);
	PolylineTo(hdc, arrPtPolyLineTo, _countof(arrPtPolyLineTo));
	DeleteObject(SelectObject(hdc, hPen));



	EndPaint(hWnd, &ps);
}

void PaintArc(HWND hWnd)
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);
	HPEN hPen = CreatePen(PS_SOLID, 5, 0x000000);

	hPen = SelectObject(hdc, hPen);
	SetBkMode(hdc, TRANSPARENT);

	MoveToEx(hdc, 550, 50, NULL);
	AngleArc(hdc, 300, 300, 250, 0, 270);


	DeleteObject(SelectObject(hdc, hPen));
	hPen = CreatePen(PS_DOT, 1, 0x000000);
	SelectObject(hdc, hPen);

	MoveToEx(hdc, 300, 300, NULL);
	LineTo(hdc, 300, 600);
	MoveToEx(hdc, 300, 300, NULL);
	LineTo(hdc, 600, 300);


	//MoveToEx(hdc, 500, 500, NULL);
	//ArcTo(hdc, 0, 0, 500, 500, 505, 500, 120, 170);
	//Arc(hdc, 10, 10, 110, 110, 15, 15, 50, 150);

	DeleteObject(SelectObject(hdc, hPen));
	EndPaint(hWnd, &ps);
}

void PaintBezier(HWND hWnd)
{
	POINT position = { 100,100 };
	PAINTSTRUCT ps = { 0 };
	POINT arrPoint[] = { position.x,position.y, position.x,position.x + 200, position.x + 300,position.y, position.x + 300,position.y + 200 };
	HDC hdc = BeginPaint(hWnd, &ps);
	HPEN hPen_1 = CreatePen(PS_DASH, 1, 0x56BB56);
	HPEN hPen_2 = CreatePen(PS_SOLID, 2, 0x000000);

	SetBkMode(hWnd, TRANSPARENT);

	hPen_2 = SelectObject(hdc, hPen_2);
	PolyBezier(hdc, arrPoint, _countof(arrPoint));
	hPen_2 = SelectObject(hdc, hPen_2);

	hPen_1 = SelectObject(hdc, hPen_1);
	MoveToEx(hdc, arrPoint[1].x, arrPoint[1].y, NULL);
	LineTo(hdc, arrPoint[0].x, arrPoint[0].y);
	MoveToEx(hdc, arrPoint[2].x, arrPoint[2].y, NULL);
	LineTo(hdc, arrPoint[3].x, arrPoint[3].y);
	hPen_1 = SelectObject(hdc, hPen_1);

	DeleteObject(hPen_1);
	DeleteObject(hPen_2);

	EndPaint(hWnd, &ps);
}

void PaintPolyDraw(HWND hWnd)
{
	POINT arrPoint[] = { 10,100, 100,10, 150,150, 200,50, 10,100, 100,10 , 150,150, 200,50 };
	BYTE arrFlag[] = { PT_MOVETO, PT_BEZIERTO, PT_BEZIERTO, PT_BEZIERTO, PT_MOVETO, PT_LINETO, PT_MOVETO, PT_LINETO };
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);
	HPEN hPen = CreatePen(PS_SOLID, 2, 0x000000);
	SelectObject(hdc, hPen);

	PolyDraw(hdc, arrPoint, arrFlag, _countof(arrPoint));

	DeleteObject(SelectObject(hdc, hPen));
	EndPaint(hWnd, &ps);
}

void MessageProc_WM_PAINT(HWND hWnd)
{
	//PaintLine(hWnd);
	//PaintArc(hWnd);
	//PaintBezier(hWnd);
	PaintPolyDraw(hWnd);
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	switch (msgID)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, NULL, NULL);
		break;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd);
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msgID, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcEx = { 0 };
	HWND hWndMain = NULL;
	TCHAR szClassName[] = TEXT("The Window");
	TCHAR szMainWindowName[] = TEXT("This is a Window");
	MSG uMsg = { 0 };

	wcEx.cbClsExtra = 0;
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.cbWndExtra = 0;
	wcEx.hbrBackground = CreateSolidBrush(0xFFFFFF);
	wcEx.hCursor = NULL;
	wcEx.hIcon = LoadIcon(NULL, IDI_SHIELD);
	wcEx.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
	wcEx.hInstance = hIns;
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = szClassName;
	wcEx.lpszMenuName = NULL;
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wcEx);

	hWndMain = CreateWindowEx(WS_EX_ACCEPTFILES, szClassName, szMainWindowName,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, hIns, NULL);

	ShowWindow(hWndMain, SW_SHOW);
	UpdateWindow(hWndMain);

	while (TRUE)
	{
		if (PeekMessage(&uMsg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&uMsg, NULL, 0, 0))
			{
				TranslateMessage(&uMsg);
				DispatchMessage(&uMsg);
			}
			else
			{
				break;
				//exit(0);
				//return 0;
			}
		}
	}

	return 0;
}