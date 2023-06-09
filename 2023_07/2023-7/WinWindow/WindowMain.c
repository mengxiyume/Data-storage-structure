#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<tchar.h>

#define MM_REDISPLAY 0x3000

struct
{
	int     m_nIndex;
	PTSTR   m_pLabel;
	PTSTR   m_pDesc;
}METRICS[] = {
	SM_CXSCREEN,                    TEXT("SM_CXSCREEN"),                    TEXT("屏幕的宽度"),
	SM_CYSCREEN,                    TEXT("SM_CYSCREEN"),                    TEXT("屏幕的高度"),
	SM_CXFULLSCREEN,                TEXT("SM_CXFULLSCREEN"),                TEXT("全屏窗口的客户区宽度"),
	SM_CYFULLSCREEN,                TEXT("SM_CYFULLSCREEN"),                TEXT("全屏窗口的客户区高度"),
	SM_ARRANGE,                     TEXT("SM_ARRANGE"),                     TEXT("如何排列最小化窗口"),
	SM_CLEANBOOT,                   TEXT("SM_CLEANBOOT"),                   TEXT("系统启动方式"),
	SM_CMONITORS,                   TEXT("SM_CMONITORS"),                   TEXT("监视器的数量"),
	SM_CMOUSEBUTTONS,               TEXT("SM_CMOUSEBUTTONS"),               TEXT("鼠标上的按钮数"),
	SM_CONVERTIBLESLATEMODE,        TEXT("SM_CONVERTIBLESLATEMODE"),        TEXT("笔记本电脑或平板电脑模式"),
	SM_CXBORDER,                    TEXT("SM_CXBORDER"),                    TEXT("窗口边框的宽度"),
	SM_CYBORDER,                    TEXT("SM_CYBORDER"),                    TEXT("窗口边框的高度"),
	SM_CXCURSOR,                    TEXT("SM_CXCURSOR"),                    TEXT("光标的宽度"),
	SM_CYCURSOR,                    TEXT("SM_CYCURSOR"),                    TEXT("光标的高度"),
	SM_CXDLGFRAME,                  TEXT("SM_CXDLGFRAME"),                  TEXT("同SM_CXFIXEDFRAME，有标题但不可调整大小的窗口边框的宽度"),
	SM_CYDLGFRAME,                  TEXT("SM_CYDLGFRAME"),                  TEXT("同SM_CYFIXEDFRAME，有标题但不可调整大小的窗口边框的高度"),
	SM_CXDOUBLECLK,                 TEXT("SM_CXDOUBLECLK"),                 TEXT("鼠标双击事件两次点击的X坐标不可以超过这个值"),
	SM_CYDOUBLECLK,                 TEXT("SM_CYDOUBLECLK"),                 TEXT("鼠标双击事件两次点击的Y坐标不可以超过这个值"),
	SM_CXDRAG,                      TEXT("SM_CXDRAG"),                      TEXT("拖动操作开始之前，鼠标指针可以移动的鼠标下方点的任意一侧的像素数"),
	SM_CYDRAG,                      TEXT("SM_CYDRAG"),                      TEXT("拖动操作开始之前，鼠标指针可以移动的鼠标下移点上方和下方的像素数"),
	SM_CXEDGE,                      TEXT("SM_CXEDGE"),                      TEXT("三维边框的宽度"),
	SM_CYEDGE,                      TEXT("SM_CYEDGE"),                      TEXT("三维边框的高度"),
	SM_CXFIXEDFRAME,                TEXT("SM_CXFIXEDFRAME"),                TEXT("同SM_CXDLGFRAME，有标题但不可调整大小的窗口边框的宽度"),
	SM_CYFIXEDFRAME,                TEXT("SM_CYFIXEDFRAME"),                TEXT("同SM_CYDLGFRAME，有标题但不可调整大小的窗口边框的高度"),
	SM_CXFOCUSBORDER,               TEXT("SM_CXFOCUSBORDER"),               TEXT("DrawFocusRect绘制的焦点矩形的左边缘和右边缘的宽度"),
	SM_CYFOCUSBORDER,               TEXT("SM_CYFOCUSBORDER"),               TEXT("DrawFocusRect绘制的焦点矩形的上边缘和下边缘的高度"),
	SM_CXFRAME,                     TEXT("SM_CXFRAME"),                     TEXT("同SM_CXSIZEFRAME，可调大小窗口边框的宽度"),
	SM_CYFRAME,                     TEXT("SM_CYFRAME"),                     TEXT("同SM_CYSIZEFRAME，可调大小窗口边框的高度"),
	SM_CXHSCROLL,                   TEXT("SM_CXHSCROLL"),                   TEXT("水平滚动条中箭头位图的宽度"),
	SM_CYHSCROLL,                   TEXT("SM_CYHSCROLL"),                   TEXT("水平滚动条中箭头位图的高度"),
	SM_CXVSCROLL,                   TEXT("SM_CXVSCROLL"),                   TEXT("垂直滚动条中箭头位图的宽度"),
	SM_CYVSCROLL,                   TEXT("SM_CYVSCROLL"),                   TEXT("垂直滚动条中箭头位图的高度"),
	SM_CXHTHUMB,                    TEXT("SM_CXHTHUMB"),                    TEXT("水平滚动条中滚动框(滑块)的高度"),
	SM_CYVTHUMB,                    TEXT("SM_CYVTHUMB"),                    TEXT("垂直滚动条中滚动框(滑块)的宽度"),
	SM_CXICON,                      TEXT("SM_CXICON"),                      TEXT("图标的默认宽度"),
	SM_CYICON,                      TEXT("SM_CYICON"),                      TEXT("图标的默认高度"),
	SM_CXICONSPACING,               TEXT("SM_CXICONSPACING"),               TEXT("大图标视图中项目的网格单元格宽度"),
	SM_CYICONSPACING,               TEXT("SM_CYICONSPACING"),               TEXT("大图标视图中项目的网格单元格高度"),
	SM_CXMAXIMIZED,                 TEXT("SM_CXMAXIMIZED"),                 TEXT("最大化顶层窗口的默认宽度"),
	SM_CYMAXIMIZED,                 TEXT("SM_CYMAXIMIZED"),                 TEXT("最大化顶层窗口的默认高度"),
	SM_CXMAXTRACK,                  TEXT("SM_CXMAXTRACK"),                  TEXT("具有标题和大小调整边框的窗口可以拖动的最大宽度"),
	SM_CYMAXTRACK,                  TEXT("SM_CYMAXTRACK"),                  TEXT("具有标题和大小调整边框的窗口可以拖动的最大高度"),
	SM_CXMENUCHECK,                 TEXT("SM_CXMENUCHECK"),                 TEXT("菜单项前面复选框位图的宽度"),
	SM_CYMENUCHECK,                 TEXT("SM_CYMENUCHECK"),                 TEXT("菜单项前面复选框位图的高度"),
	SM_CXMENUSIZE,                  TEXT("SM_CXMENUSIZE"),                  TEXT("菜单栏按钮的宽度"),
	SM_CYMENUSIZE,                  TEXT("SM_CYMENUSIZE"),                  TEXT("菜单栏按钮的高度"),
	SM_CXMIN,                       TEXT("SM_CXMIN"),                       TEXT("窗口的最小宽度"),
	SM_CYMIN,                       TEXT("SM_CYMIN"),                       TEXT("窗口的最小高度"),
	SM_CXMINIMIZED,                 TEXT("SM_CXMINIMIZED"),                 TEXT("最小化窗口的宽度"),
	SM_CYMINIMIZED,                 TEXT("SM_CYMINIMIZED"),                 TEXT("最小化窗口的高度"),
	SM_CXMINSPACING,                TEXT("SM_CXMINSPACING"),                TEXT("最小化窗口的网格单元宽度"),
	SM_CYMINSPACING,                TEXT("SM_CYMINSPACING"),                TEXT("最小化窗口的网格单元高度"),
	SM_CXMINTRACK,                  TEXT("SM_CXMINTRACK"),                  TEXT("窗口的最小拖动宽度，用户无法将窗口拖动到小于这些尺寸"),
	SM_CYMINTRACK,                  TEXT("SM_CYMINTRACK"),                  TEXT("窗口的最小拖动高度，用户无法将窗口拖动到小于这些尺寸"),
	SM_CXPADDEDBORDER,              TEXT("SM_CXPADDEDBORDER"),              TEXT("标题窗口的边框填充量"),
	SM_CXSIZE,                      TEXT("SM_CXSIZE"),                      TEXT("窗口标题或标题栏中按钮的宽度"),
	SM_CYSIZE,                      TEXT("SM_CYSIZE"),                      TEXT("窗口标题或标题栏中按钮的高度"),
	SM_CXSIZEFRAME,                 TEXT("SM_CXSIZEFRAME"),                 TEXT("同SM_CXFRAME，可调大小窗口边框的宽度"),
	SM_CYSIZEFRAME,                 TEXT("SM_CYSIZEFRAME"),                 TEXT("同SM_CYFRAME，可调大小窗口边框的厚度"),
	SM_CXSMICON,                    TEXT("SM_CXSMICON"),                    TEXT("小图标的建议宽度"),
	SM_CYSMICON,                    TEXT("SM_CYSMICON"),                    TEXT("小图标的建议高度"),
	SM_CXSMSIZE,                    TEXT("SM_CXSMSIZE"),                    TEXT("小标题按钮的宽度"),
	SM_CYSMSIZE,                    TEXT("SM_CYSMSIZE"),                    TEXT("小标题按钮的高度"),
	SM_CXVIRTUALSCREEN,             TEXT("SM_CXVIRTUALSCREEN"),             TEXT("虚拟屏幕的宽度"),
	SM_CYVIRTUALSCREEN,             TEXT("SM_CYVIRTUALSCREEN"),             TEXT("虚拟屏幕的高度"),
	SM_CYCAPTION,                   TEXT("SM_CYCAPTION"),                   TEXT("标题区域的高度"),
	SM_CYKANJIWINDOW,               TEXT("SM_CYKANJIWINDOW"),               TEXT("屏幕底部的日文汉字窗口的高度"),
	SM_CYMENU,                      TEXT("SM_CYMENU"),                      TEXT("单行菜单栏的高度"),
	SM_CYSMCAPTION,                 TEXT("SM_CYSMCAPTION"),                 TEXT("小标题的高度"),
	SM_DBCSENABLED,                 TEXT("SM_DBCSENABLED"),                 TEXT("User32.dll是否支持DBCS"),
	SM_DEBUG,                       TEXT("SM_DEBUG"),                       TEXT("是否安装了User.exe的调试版本"),
	SM_DIGITIZER,                   TEXT("SM_DIGITIZER"),                   TEXT("设备支持的数字转换器输入类型"),
	SM_IMMENABLED,                  TEXT("SM_IMMENABLED"),                  TEXT("是否启用了输入法管理器／输入法编辑器功能"),
	SM_MAXIMUMTOUCHES,              TEXT("SM_MAXIMUMTOUCHES"),              TEXT("系统中是否有数字化仪"),
	SM_MEDIACENTER,                 TEXT("SM_MEDIACENTER"),                 TEXT("当前操作系统是不是Windows XP Media Center"),
	SM_MENUDROPALIGNMENT,           TEXT("SM_MENUDROPALIGNMENT"),           TEXT("下拉菜单是否与相应的菜单栏项右对齐"),
	SM_MIDEASTENABLED,              TEXT("SM_MIDEASTENABLED"),              TEXT("系统是否启用希伯来语和阿拉伯语"),
	SM_MOUSEHORIZONTALWHEELPRESENT, TEXT("SM_MOUSEHORIZONTALWHEELPRESENT"), TEXT("是否安装了带有水平滚轮的鼠标"),
	SM_MOUSEPRESENT,                TEXT("SM_MOUSEPRESENT"),                TEXT("是否安装了鼠标"),
	SM_MOUSEWHEELPRESENT,           TEXT("SM_MOUSEWHEELPRESENT"),           TEXT("是否安装了带有垂直滚轮的鼠标"),
	SM_NETWORK,                     TEXT("SM_NETWORK"),                     TEXT("是否存在网络"),
	SM_PENWINDOWS,                  TEXT("SM_PENWINDOWS"),                  TEXT("是否安装了Microsoft Windows for Pen Computing扩展"),
	SM_REMOTECONTROL,               TEXT("SM_REMOTECONTROL"),               TEXT("当前终端服务器会话是否被远程控制"),
	SM_REMOTESESSION,               TEXT("SM_REMOTESESSION"),               TEXT("调用进程是否与终端服务客户机会话关联"),
	SM_SAMEDISPLAYFORMAT,           TEXT("SM_SAMEDISPLAYFORMAT"),           TEXT("所有显示器的颜色格式是否相同"),
	SM_SECURE,                      TEXT("SM_SECURE"),                      TEXT("始终返回0"),
	SM_SERVERR2,                    TEXT("SM_SERVERR2"),                    TEXT("系统是否是Windows Server 2003 R2"),
	SM_SHOWSOUNDS,                  TEXT("SM_SHOWSOUNDS"),                  TEXT("用户是否要求应用程序在其他情况下以可视方式呈现信息"),
	SM_SHUTTINGDOWN,                TEXT("SM_SHUTTINGDOWN"),                TEXT("当前会话是否正在关闭"),
	SM_SLOWMACHINE,                 TEXT("SM_SLOWMACHINE"),                 TEXT("计算机是否具有低端(慢速)处理器"),
	SM_STARTER,                     TEXT("SM_STARTER"),                     TEXT("当前操作系统版本"),
	SM_SWAPBUTTON,                  TEXT("SM_SWAPBUTTON"),                  TEXT("鼠标左键和右键的功能是否互换了"),
	SM_SYSTEMDOCKED,                TEXT("SM_SYSTEMDOCKED"),                TEXT("停靠模式的状态"),
	SM_TABLETPC,                    TEXT("SM_TABLETPC"),                    TEXT("是否启动了Tablet PC输入服务"),
	SM_XVIRTUALSCREEN,              TEXT("SM_XVIRTUALSCREEN"),              TEXT("虚拟屏幕左侧的坐标"),
	SM_YVIRTUALSCREEN,              TEXT("SM_YVIRTUALSCREEN"),              TEXT("虚拟屏幕顶部的坐标")
};
 
const int NUMLINES = sizeof(METRICS) / sizeof(METRICS[0]);
//const int NUMLINES = 10;

static int s_nTextHeight = 20;
static const int s_c_nNullWhiteHeight = 10;
static int s_nTextPosition = 0;

void MessageProc_WM_PAINT(HWND hWnd)
{
	HDC hdc = NULL;
	PAINTSTRUCT ps = { 0 };
	TCHAR szText[] = TEXT("Hello Windows API!");
	TCHAR szBuffer[1024] = TEXT("");
	HFONT hFont = CreateFont(s_nTextHeight, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, DRAFT_QUALITY, DEFAULT_PITCH, TEXT("./阿里汉仪智能黑体.ttf"));
	RECT mClientRect = { 0 };
	int i = 0;
	int* arrCharWidth = NULL;
	int arrTapStopPositions[] = { 100, 240, 1000 };
	SIZE mSzTextSize = { 0 };
	int iOffsetTextIndex = (s_nTextPosition - s_c_nNullWhiteHeight) / s_nTextHeight;
	int nDisplayLineCount = 0;
	int nOffsetTextPosition = ((s_nTextPosition - s_c_nNullWhiteHeight) > 0 ? (s_nTextPosition - s_c_nNullWhiteHeight) : 0) % s_nTextHeight;
	nOffsetTextPosition = (s_nTextPosition - s_c_nNullWhiteHeight) < 0 ? -1 : nOffsetTextPosition;

	GetClientRect(hWnd, &mClientRect);
	nDisplayLineCount = (mClientRect.bottom - mClientRect.top) / s_nTextHeight - 1;	//刷新限制范围 

	hdc = BeginPaint(hWnd, &ps);
	hFont = SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);
	//SetBkMode(hdc, OPAQUE);
	SetTextColor(hdc, 0xCBBCCB);
	SetBkColor(hdc, 0x000000);

	//绘制
	for (i = iOffsetTextIndex; i < NUMLINES; i++)
	{
		int tmpMode = SetTextAlign(hdc, TA_CENTER | TA_TOP | TA_NOUPDATECP);
		int y = (i - iOffsetTextIndex) * s_nTextHeight + (nOffsetTextPosition >= 0 ? 0 : s_c_nNullWhiteHeight - s_nTextPosition) - (nOffsetTextPosition >= 0 ? nOffsetTextPosition : 0);
		SetTextCharacterExtra(hdc, 0);

		_stprintf_s(szBuffer, _countof(szBuffer), TEXT("%d\t%d\t%s\t%s"), i, GetSystemMetrics(i), METRICS[i].m_pDesc, METRICS[i].m_pLabel);
		TabbedTextOut(hdc, 30, y
			, szBuffer, _tcslen(szBuffer), _countof(arrTapStopPositions), arrTapStopPositions, 0);

		SetTextAlign(hdc, tmpMode);
		SetTextCharacterExtra(hdc, 0);

		if (i - iOffsetTextIndex > nDisplayLineCount)
		{
			break;
		}
	}
	//GetTextExtentPoint(hdc, szText, _tcslen(szText), &mSzTextSize);
	////GetTabbedTextExtent(hdc, szText, _tcslen(szText), 0, &mSzTextSize);

	////TextOut(hdc, (GetSystemMetrics(SM_CXSCREEN) - mSzTextSize.cx) / 2, (GetSystemMetrics(SM_CYSCREEN) - mSzTextSize.cy) / 2, szText, _tcslen(szText));
	////ExtTextOut(hdc, (GetSystemMetrics(SM_CXSCREEN) - mSzTextSize.cx) / 2, (GetSystemMetrics(SM_CYSCREEN) - mSzTextSize.cy) / 2, 0, NULL, szText, _tcslen(szText), NULL);
	////DrawTextEx(hdc, szText, _tcslen(szText), &mScreenRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_WORDBREAK, NULL);

	SetBkMode(hdc, OPAQUE);
	SetTextColor(hdc, 0x000000);
	hFont = SelectObject(hdc, hFont);
	DeleteObject(hFont);
	hFont = NULL;
	EndPaint(hWnd, &ps);
	hdc = NULL;
}

void MessageProc_MM_REDISPLAY(HWND hWnd)
{
	InvalidateRect(NULL, NULL, TRUE);
	UpdateWindow(hWnd);
}

void KeyUp_F9(HWND hWnd)
{
	static BOOL s_bWindowOnTopLayerState = FALSE;
 
	LONG newLong = 0;
	TCHAR szBuffer[1024] = TEXT("");

	//设置为最顶层时不能点击Z不变
	if (s_bWindowOnTopLayerState == FALSE)
	{
		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE |  SWP_FRAMECHANGED | SWP_SHOWWINDOW);
		s_bWindowOnTopLayerState = TRUE;
	}
	else
	{
		SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED | SWP_SHOWWINDOW);
		s_bWindowOnTopLayerState = FALSE;
	}
}

void MessageProc_WM_KEYUP(HWND hWnd, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_DELETE:
		PostMessage(hWnd, MM_REDISPLAY, NULL, NULL);
		break;
	case VK_F9:
		KeyUp_F9(hWnd);
		break;
	default:
		break;
	}
}

void MessageProc_WM_MOUSEMOVE(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	if (wParam == MK_LBUTTON)
	{
		HDC hdc = GetDC(hWnd);
		int nPointX = LOWORD(lParam);
		int nPointY = HIWORD(lParam);
		HPEN hPen = CreatePen(PS_NULL, 0, 0xFFFFFF);
		HBRUSH hBrush = CreateSolidBrush(0xFFFFFF);

		hPen = SelectObject(hdc, hPen);
		hBrush = SelectObject(hdc, hBrush);

		Ellipse(hdc, nPointX - 10, nPointY - 10, nPointX + 10, nPointY + 10);

		hPen = SelectObject(hdc, hPen);
		hBrush = SelectObject(hdc, hBrush);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hWnd, hdc);
	}
}

void MessageProc_WM_VSCROLL(HWND hWnd, WPARAM wParam)
{
	RECT mClinetRect = { 0 };
	GetClientRect(hWnd, &mClinetRect);
	switch (LOWORD(wParam))
	{
	case SB_THUMBTRACK:
		SetScrollPos(hWnd, SB_VERT, HIWORD(wParam), TRUE);
		s_nTextPosition = HIWORD(wParam);
		ScrollWindow(hWnd, 0, mClinetRect.bottom - mClinetRect.top, NULL, NULL);
		UpdateWindow(hWnd);
		break;
	default:
		break;
	}

}

void MessageProc_WM_CREATE(HWND hWnd)
{
	SetScrollRange(hWnd, SB_VERT, 0, (NUMLINES - 1) * s_nTextHeight + s_c_nNullWhiteHeight, TRUE);
	SetScrollPos(hWnd, SB_VERT, 0, TRUE);
}

void MessageProc_WM_SIZE(HWND hWnd, LPARAM lParam)
{
	int width = LOWORD(lParam);
	int height = HIWORD(lParam);
	SCROLLINFO si = {0};

	//滚动条重绘
	si.fMask = SIF_RANGE | SIF_PAGE;
	si.nMax = (NUMLINES) * s_nTextHeight + s_c_nNullWhiteHeight;
	si.nMin = 0;
	si.nPage = height;
	si.cbSize = sizeof(SCROLLINFO);
	SetScrollInfo(hWnd, SB_VERT, &si, TRUE);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		MessageProc_WM_CREATE(hWnd);
		break;
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, NULL, NULL);		//结束程序
		//PostQuitMessage(0);
		break;
	case WM_PAINT:
		MessageProc_WM_PAINT(hWnd);
		break;
	case MM_REDISPLAY:
		MessageProc_MM_REDISPLAY(hWnd);
		break;
	case WM_MOUSEMOVE:
		MessageProc_WM_MOUSEMOVE(hWnd, wParam, lParam);
		break;
	case WM_KEYUP:
		MessageProc_WM_KEYUP(hWnd, wParam);
		break;
	case WM_VSCROLL:
		MessageProc_WM_VSCROLL(hWnd, wParam);
		break;
	case WM_SIZE:
		MessageProc_WM_SIZE(hWnd, lParam);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
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
	wc.hbrBackground = CreateSolidBrush(0xDFDFDF);		//CreateSolidBrush(0xFFFFFF);
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
	hWndMain = CreateWindowEx(WS_EX_ACCEPTFILES, windowClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, hInstance, NULL);
	ShowWindow(hWndMain, SW_SHOW);
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
	}

	return 0;
}