#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<assert.h>

void PaintLine(HDC hdc)
{
	POINT arrPtPolyPolyLine[] = {
		110,60, 10,60, 60,10, 160,10,
		10,60, 10,160, 110,160, 110,60, 160,10, 160,110, 110,160,
	};

	DWORD arrGroup[] = { 4,7 };
	POINT arrPtPolyLine[] = { 10,220, 110,200, 210,220 };
	POINT arrPtPolyLineTo[] = { 110,260, 210,240 };
	LOGPEN logPen = { 0 };
	HPEN hPen = NULL;

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
}

void PaintArc(HDC hdc)
{
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
}

void PaintBezier(HDC hdc)
{
	POINT position = { 100,100 };
	POINT arrPoint[] = { position.x,position.y, position.x,position.x + 200, position.x + 300,position.y, position.x + 300,position.y + 200 };
	HPEN hPen_1 = CreatePen(PS_DASH, 1, 0x56BB56);
	HPEN hPen_2 = CreatePen(PS_SOLID, 2, 0x000000);

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
}

void PaintPolyDraw(HDC hdc)
{
	POINT arrPoint[] = { 10,100, 100,10, 150,150, 200,50, 10,100, 100,10 , 150,150, 200,50 };
	BYTE arrFlag[] = { PT_MOVETO, PT_BEZIERTO, PT_BEZIERTO, PT_BEZIERTO, PT_MOVETO, PT_LINETO, PT_MOVETO, PT_LINETO };
	HPEN hPen = CreatePen(PS_SOLID, 2, 0x000000);
	SelectObject(hdc, hPen);

	PolyDraw(hdc, arrPoint, arrFlag, _countof(arrPoint));

	DeleteObject(SelectObject(hdc, hPen));
}

void PaintBox(HDC hdc)
{
	POINT position = { 50,50 };
	POINT arrGonPoint[] = { 500,500, 100,500, 100,100, 400,100, 400,400 , 400,200, 200,200, 200,400  };
	
	Rectangle(hdc, position.x, position.y, position.x + 200, position.y + 100);
	position.x += 250;

	RoundRect(hdc, position.x, position.y, position.x + 200, position.y + 100, 50, 50);
	position.x += 250;

	Ellipse(hdc, position.x, position.y, position.x + 200, position.y + 100);
	position.x += 250;

	SetArcDirection(hdc, AD_CLOCKWISE);
	Chord(hdc, position.x, position.y, position.x + 200, position.y + 100, position.x + 200 * 3 / 4, position.y, position.x, position.y + 100 * 3 / 4);
	position.x += 250;

	Pie(hdc, position.x, position.y, position.x + 200, position.y + 100, position.x + 200 * 3 / 4, position.y, position.x, position.y + 100 * 3 / 4);
	position.x += 250;

	SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
	Chord(hdc, position.x, position.y, position.x + 200, position.y + 100, position.x + 200 * 3 / 4, position.y, position.x, position.y + 100 * 3 / 4);
	position.x += 150;

	Pie(hdc, position.x, position.y, position.x + 200, position.y + 100, position.x + 200 * 3 / 4, position.y, position.x, position.y + 100 * 3 / 4);
	position.x = 50, position.y += 150;

	Polygon(hdc, arrGonPoint, _countof(arrGonPoint));
}

void PaintStar(HDC hdc)
{
	POINT arrStarPoint_1[] = { 0,40, 100,40, 20,100, 50,0, 80,100 };
	POINT arrStarPoint_2[] = { 120,40, 220,40, 140,100, 170,0, 200,100 };

	SetPolyFillMode(hdc, ALTERNATE);
	Polygon(hdc, arrStarPoint_1, _countof(arrStarPoint_1));
	SetPolyFillMode(hdc, WINDING);
	Polygon(hdc, arrStarPoint_2, _countof(arrStarPoint_2));

}

void PaintSandwitch(HDC hdc)
{
	POINT arrSandwitchPoint[] = 
	{	50,66, 66,33, 50,0, 33,33,
		50,66, 17,66, 0,100, 33,100,
		50,66, 83,66, 100,100, 66,100 };

	INT arrPolyCounts[] = { 4, 4, 4 };

	PolyPolygon(hdc, arrSandwitchPoint, arrPolyCounts, _countof(arrPolyCounts));
}

void Graphics_PosTrans(HDC hdc)
{
	XFORM xForm = { 0 };
	HPEN hPen = CreatePen(PS_SOLID, 2, 0x000000);
	HBRUSH hBrush = CreateSolidBrush(0xFFFFFF);

	SetMapMode(hdc, MM_LOENGLISH);
	hPen = SelectObject(hdc, hPen);
	hBrush = SelectObject(hdc, hBrush);
	
	Rectangle(hdc, 50,-50,650,-650);

	DeleteObject(SelectObject(hdc, hPen));
	DeleteObject(SelectObject(hdc, hBrush));
	SetMapMode(hdc, MM_TEXT);
}

void PaintExtPen(HDC hdc)
{
	HPEN hPen = NULL;
	LOGBRUSH logBrush = { 0 };
	POINT arrPoint[] = { 50,50, 100,200, 150,50 };
	int i = 0;

	int arrPenStyleEndcap[] = { PS_ENDCAP_ROUND,PS_ENDCAP_SQUARE,PS_ENDCAP_FLAT,PS_ENDCAP_MASK };
	int arrPenStyleJoin[] = { PS_JOIN_BEVEL,PS_JOIN_MITER,PS_JOIN_ROUND,PS_JOIN_MASK };

	for (i = 0; i < 4; i++)
	{
		int j = 0;
		hPen = ExtCreatePen(PS_GEOMETRIC | PS_SOLID | arrPenStyleEndcap[i] | arrPenStyleJoin[i], 40, &logBrush, 0, NULL);
		hPen = SelectObject(hdc, hPen);

		Polyline(hdc, arrPoint, _countof(arrPoint));
		DeleteObject(SelectObject(hdc, hPen));
		SelectObject(hdc, GetStockObject(WHITE_PEN));

		Polyline(hdc, arrPoint, _countof(arrPoint));

		SelectObject(hdc, GetStockObject(BLACK_PEN));
		for (j = 0; j < _countof(arrPoint); j++)
		{
			arrPoint[j].x += 150;
		}

	}
}

void Paint_Rgn(HDC hdc)
{
	HRGN hClipRgn = CreateEllipticRgn(50, 50, 350, 250);
	HBRUSH hBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));

	SelectClipRgn(hdc, hClipRgn);

	Rectangle(hdc, 0, 0, 1920, 1080);

	SelectObject(hdc, hBrush);
}

void PaintPath(HDC hdc)
{
	BeginPath(hdc);
	MoveToEx(hdc, 50, 50, NULL);
	LineTo(hdc, 150, 80);
	LineTo(hdc, 50, 110);

	//闭合路径
	CloseFigure(hdc);
	Rectangle(hdc, 160, 50, 250, 110);

	EndPath(hdc);
	SelectClipPath(hdc, RGN_COPY);

	SelectObject(hdc, GetStockObject(BLACK_BRUSH));

	StrokePath(hdc);
	Rectangle(hdc, 0, 0, 1920, 1080);
}

void MessageProc_WM_PAINT(HWND hWnd)
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT clientRect = { 0 };
	SetBkMode(hWnd, TRANSPARENT);

	//PaintLine(hdc);
	//PaintArc(hdc);
	//PaintBezier(hdc);
	//PaintPolyDraw(hdc);
	//PaintBox(hdc);
	//PaintStar(hdc);
	//PaintSandwitch(hdc);12

	//Graphics_PosTrans(hdc);
	//SetGraphicsMode(hWnd, GM_ADVANCED);

	//SetMapMode(hdc, MM_LOENGLISH);
	//DPtoLP(hdc, (LPPOINT)&clientRect, 2);
	//Ellipse(hdc, clientRect.right / 4, clientRect.bottom / 4, clientRect.right * 3 / 4, clientRect.bottom * 3 / 4);

	//SetMapMode(hdc, MM_ISOTROPIC);
	//SetWindowExtEx(hdc, 500, 500, NULL);
	//GetClientRect(hWnd, &clientRect);
	//SetViewportExtEx(hdc, clientRect.right, -clientRect.bottom, NULL);
	//
	//SetViewportOrgEx(hdc, clientRect.right / 2, clientRect.bottom / 2, NULL);
	//
	//Ellipse(hdc, -100, 100, 100, -100);
	//
	//SetMapMode(hdc, MM_TEXT);

	//PaintExtPen(hdc);
	//Paint_Rgn(hdc);
	PaintPath(hdc);

	EndPaint(hdc, &ps);
}

void MessageProc_WM_MOUSEMOVE(WPARAM wParam, LPARAM lParam)
{
	HDC hdc = GetDC(NULL);
	HPEN hPen = SelectObject(hdc, CreatePen(PS_SOLID, 20, 0xFFFFFF));

	int x = LOWORD(lParam), y = HIWORD(lParam);
	int oldROP2 = SetROP2(hdc, R2_NOT);

	if (wParam == MK_LBUTTON)
	{
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, y, x);
	}

	SetROP2(hdc, oldROP2);
	DeleteObject(SelectObject(hdc, hPen));
	ReleaseDC(NULL, hdc);
}

void MessageProc_WM_CREATE(HWND hWnd)
{
	//设置窗口为椭圆形裁切窗口
	//HRGN hClipWindowRgn = CreateEllipticRgn(50, 50, 350, 250);
	//SetWindowRgn(hWnd, hClipWindowRgn, TRUE);
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	switch (msgID)
	{
	case WM_MOUSEMOVE:
		MessageProc_WM_MOUSEMOVE(wParam, lParam);
		break;
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, NULL, NULL);
		break;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd);
		break;
	case WM_CREATE:
		MessageProc_WM_CREATE(hWnd);
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
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
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