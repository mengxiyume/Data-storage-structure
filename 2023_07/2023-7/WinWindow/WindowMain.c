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
	SM_CXSCREEN,                    TEXT("SM_CXSCREEN"),                    TEXT("��Ļ�Ŀ��"),
	SM_CYSCREEN,                    TEXT("SM_CYSCREEN"),                    TEXT("��Ļ�ĸ߶�"),
	SM_CXFULLSCREEN,                TEXT("SM_CXFULLSCREEN"),                TEXT("ȫ�����ڵĿͻ������"),
	SM_CYFULLSCREEN,                TEXT("SM_CYFULLSCREEN"),                TEXT("ȫ�����ڵĿͻ����߶�"),
	SM_ARRANGE,                     TEXT("SM_ARRANGE"),                     TEXT("���������С������"),
	SM_CLEANBOOT,                   TEXT("SM_CLEANBOOT"),                   TEXT("ϵͳ������ʽ"),
	SM_CMONITORS,                   TEXT("SM_CMONITORS"),                   TEXT("������������"),
	SM_CMOUSEBUTTONS,               TEXT("SM_CMOUSEBUTTONS"),               TEXT("����ϵİ�ť��"),
	SM_CONVERTIBLESLATEMODE,        TEXT("SM_CONVERTIBLESLATEMODE"),        TEXT("�ʼǱ����Ի�ƽ�����ģʽ"),
	SM_CXBORDER,                    TEXT("SM_CXBORDER"),                    TEXT("���ڱ߿�Ŀ��"),
	SM_CYBORDER,                    TEXT("SM_CYBORDER"),                    TEXT("���ڱ߿�ĸ߶�"),
	SM_CXCURSOR,                    TEXT("SM_CXCURSOR"),                    TEXT("���Ŀ��"),
	SM_CYCURSOR,                    TEXT("SM_CYCURSOR"),                    TEXT("���ĸ߶�"),
	SM_CXDLGFRAME,                  TEXT("SM_CXDLGFRAME"),                  TEXT("ͬSM_CXFIXEDFRAME���б��⵫���ɵ�����С�Ĵ��ڱ߿�Ŀ��"),
	SM_CYDLGFRAME,                  TEXT("SM_CYDLGFRAME"),                  TEXT("ͬSM_CYFIXEDFRAME���б��⵫���ɵ�����С�Ĵ��ڱ߿�ĸ߶�"),
	SM_CXDOUBLECLK,                 TEXT("SM_CXDOUBLECLK"),                 TEXT("���˫���¼����ε����X���겻���Գ������ֵ"),
	SM_CYDOUBLECLK,                 TEXT("SM_CYDOUBLECLK"),                 TEXT("���˫���¼����ε����Y���겻���Գ������ֵ"),
	SM_CXDRAG,                      TEXT("SM_CXDRAG"),                      TEXT("�϶�������ʼ֮ǰ�����ָ������ƶ�������·��������һ���������"),
	SM_CYDRAG,                      TEXT("SM_CYDRAG"),                      TEXT("�϶�������ʼ֮ǰ�����ָ������ƶ���������Ƶ��Ϸ����·���������"),
	SM_CXEDGE,                      TEXT("SM_CXEDGE"),                      TEXT("��ά�߿�Ŀ��"),
	SM_CYEDGE,                      TEXT("SM_CYEDGE"),                      TEXT("��ά�߿�ĸ߶�"),
	SM_CXFIXEDFRAME,                TEXT("SM_CXFIXEDFRAME"),                TEXT("ͬSM_CXDLGFRAME���б��⵫���ɵ�����С�Ĵ��ڱ߿�Ŀ��"),
	SM_CYFIXEDFRAME,                TEXT("SM_CYFIXEDFRAME"),                TEXT("ͬSM_CYDLGFRAME���б��⵫���ɵ�����С�Ĵ��ڱ߿�ĸ߶�"),
	SM_CXFOCUSBORDER,               TEXT("SM_CXFOCUSBORDER"),               TEXT("DrawFocusRect���ƵĽ�����ε����Ե���ұ�Ե�Ŀ��"),
	SM_CYFOCUSBORDER,               TEXT("SM_CYFOCUSBORDER"),               TEXT("DrawFocusRect���ƵĽ�����ε��ϱ�Ե���±�Ե�ĸ߶�"),
	SM_CXFRAME,                     TEXT("SM_CXFRAME"),                     TEXT("ͬSM_CXSIZEFRAME���ɵ���С���ڱ߿�Ŀ��"),
	SM_CYFRAME,                     TEXT("SM_CYFRAME"),                     TEXT("ͬSM_CYSIZEFRAME���ɵ���С���ڱ߿�ĸ߶�"),
	SM_CXHSCROLL,                   TEXT("SM_CXHSCROLL"),                   TEXT("ˮƽ�������м�ͷλͼ�Ŀ��"),
	SM_CYHSCROLL,                   TEXT("SM_CYHSCROLL"),                   TEXT("ˮƽ�������м�ͷλͼ�ĸ߶�"),
	SM_CXVSCROLL,                   TEXT("SM_CXVSCROLL"),                   TEXT("��ֱ�������м�ͷλͼ�Ŀ��"),
	SM_CYVSCROLL,                   TEXT("SM_CYVSCROLL"),                   TEXT("��ֱ�������м�ͷλͼ�ĸ߶�"),
	SM_CXHTHUMB,                    TEXT("SM_CXHTHUMB"),                    TEXT("ˮƽ�������й�����(����)�ĸ߶�"),
	SM_CYVTHUMB,                    TEXT("SM_CYVTHUMB"),                    TEXT("��ֱ�������й�����(����)�Ŀ��"),
	SM_CXICON,                      TEXT("SM_CXICON"),                      TEXT("ͼ���Ĭ�Ͽ��"),
	SM_CYICON,                      TEXT("SM_CYICON"),                      TEXT("ͼ���Ĭ�ϸ߶�"),
	SM_CXICONSPACING,               TEXT("SM_CXICONSPACING"),               TEXT("��ͼ����ͼ����Ŀ������Ԫ����"),
	SM_CYICONSPACING,               TEXT("SM_CYICONSPACING"),               TEXT("��ͼ����ͼ����Ŀ������Ԫ��߶�"),
	SM_CXMAXIMIZED,                 TEXT("SM_CXMAXIMIZED"),                 TEXT("��󻯶��㴰�ڵ�Ĭ�Ͽ��"),
	SM_CYMAXIMIZED,                 TEXT("SM_CYMAXIMIZED"),                 TEXT("��󻯶��㴰�ڵ�Ĭ�ϸ߶�"),
	SM_CXMAXTRACK,                  TEXT("SM_CXMAXTRACK"),                  TEXT("���б���ʹ�С�����߿�Ĵ��ڿ����϶��������"),
	SM_CYMAXTRACK,                  TEXT("SM_CYMAXTRACK"),                  TEXT("���б���ʹ�С�����߿�Ĵ��ڿ����϶������߶�"),
	SM_CXMENUCHECK,                 TEXT("SM_CXMENUCHECK"),                 TEXT("�˵���ǰ�渴ѡ��λͼ�Ŀ��"),
	SM_CYMENUCHECK,                 TEXT("SM_CYMENUCHECK"),                 TEXT("�˵���ǰ�渴ѡ��λͼ�ĸ߶�"),
	SM_CXMENUSIZE,                  TEXT("SM_CXMENUSIZE"),                  TEXT("�˵�����ť�Ŀ��"),
	SM_CYMENUSIZE,                  TEXT("SM_CYMENUSIZE"),                  TEXT("�˵�����ť�ĸ߶�"),
	SM_CXMIN,                       TEXT("SM_CXMIN"),                       TEXT("���ڵ���С���"),
	SM_CYMIN,                       TEXT("SM_CYMIN"),                       TEXT("���ڵ���С�߶�"),
	SM_CXMINIMIZED,                 TEXT("SM_CXMINIMIZED"),                 TEXT("��С�����ڵĿ��"),
	SM_CYMINIMIZED,                 TEXT("SM_CYMINIMIZED"),                 TEXT("��С�����ڵĸ߶�"),
	SM_CXMINSPACING,                TEXT("SM_CXMINSPACING"),                TEXT("��С�����ڵ�����Ԫ���"),
	SM_CYMINSPACING,                TEXT("SM_CYMINSPACING"),                TEXT("��С�����ڵ�����Ԫ�߶�"),
	SM_CXMINTRACK,                  TEXT("SM_CXMINTRACK"),                  TEXT("���ڵ���С�϶���ȣ��û��޷��������϶���С����Щ�ߴ�"),
	SM_CYMINTRACK,                  TEXT("SM_CYMINTRACK"),                  TEXT("���ڵ���С�϶��߶ȣ��û��޷��������϶���С����Щ�ߴ�"),
	SM_CXPADDEDBORDER,              TEXT("SM_CXPADDEDBORDER"),              TEXT("���ⴰ�ڵı߿������"),
	SM_CXSIZE,                      TEXT("SM_CXSIZE"),                      TEXT("���ڱ����������а�ť�Ŀ��"),
	SM_CYSIZE,                      TEXT("SM_CYSIZE"),                      TEXT("���ڱ����������а�ť�ĸ߶�"),
	SM_CXSIZEFRAME,                 TEXT("SM_CXSIZEFRAME"),                 TEXT("ͬSM_CXFRAME���ɵ���С���ڱ߿�Ŀ��"),
	SM_CYSIZEFRAME,                 TEXT("SM_CYSIZEFRAME"),                 TEXT("ͬSM_CYFRAME���ɵ���С���ڱ߿�ĺ��"),
	SM_CXSMICON,                    TEXT("SM_CXSMICON"),                    TEXT("Сͼ��Ľ�����"),
	SM_CYSMICON,                    TEXT("SM_CYSMICON"),                    TEXT("Сͼ��Ľ���߶�"),
	SM_CXSMSIZE,                    TEXT("SM_CXSMSIZE"),                    TEXT("С���ⰴť�Ŀ��"),
	SM_CYSMSIZE,                    TEXT("SM_CYSMSIZE"),                    TEXT("С���ⰴť�ĸ߶�"),
	SM_CXVIRTUALSCREEN,             TEXT("SM_CXVIRTUALSCREEN"),             TEXT("������Ļ�Ŀ��"),
	SM_CYVIRTUALSCREEN,             TEXT("SM_CYVIRTUALSCREEN"),             TEXT("������Ļ�ĸ߶�"),
	SM_CYCAPTION,                   TEXT("SM_CYCAPTION"),                   TEXT("��������ĸ߶�"),
	SM_CYKANJIWINDOW,               TEXT("SM_CYKANJIWINDOW"),               TEXT("��Ļ�ײ������ĺ��ִ��ڵĸ߶�"),
	SM_CYMENU,                      TEXT("SM_CYMENU"),                      TEXT("���в˵����ĸ߶�"),
	SM_CYSMCAPTION,                 TEXT("SM_CYSMCAPTION"),                 TEXT("С����ĸ߶�"),
	SM_DBCSENABLED,                 TEXT("SM_DBCSENABLED"),                 TEXT("User32.dll�Ƿ�֧��DBCS"),
	SM_DEBUG,                       TEXT("SM_DEBUG"),                       TEXT("�Ƿ�װ��User.exe�ĵ��԰汾"),
	SM_DIGITIZER,                   TEXT("SM_DIGITIZER"),                   TEXT("�豸֧�ֵ�����ת������������"),
	SM_IMMENABLED,                  TEXT("SM_IMMENABLED"),                  TEXT("�Ƿ����������뷨�����������뷨�༭������"),
	SM_MAXIMUMTOUCHES,              TEXT("SM_MAXIMUMTOUCHES"),              TEXT("ϵͳ���Ƿ������ֻ���"),
	SM_MEDIACENTER,                 TEXT("SM_MEDIACENTER"),                 TEXT("��ǰ����ϵͳ�ǲ���Windows XP Media Center"),
	SM_MENUDROPALIGNMENT,           TEXT("SM_MENUDROPALIGNMENT"),           TEXT("�����˵��Ƿ�����Ӧ�Ĳ˵������Ҷ���"),
	SM_MIDEASTENABLED,              TEXT("SM_MIDEASTENABLED"),              TEXT("ϵͳ�Ƿ�����ϣ������Ͱ�������"),
	SM_MOUSEHORIZONTALWHEELPRESENT, TEXT("SM_MOUSEHORIZONTALWHEELPRESENT"), TEXT("�Ƿ�װ�˴���ˮƽ���ֵ����"),
	SM_MOUSEPRESENT,                TEXT("SM_MOUSEPRESENT"),                TEXT("�Ƿ�װ�����"),
	SM_MOUSEWHEELPRESENT,           TEXT("SM_MOUSEWHEELPRESENT"),           TEXT("�Ƿ�װ�˴��д�ֱ���ֵ����"),
	SM_NETWORK,                     TEXT("SM_NETWORK"),                     TEXT("�Ƿ��������"),
	SM_PENWINDOWS,                  TEXT("SM_PENWINDOWS"),                  TEXT("�Ƿ�װ��Microsoft Windows for Pen Computing��չ"),
	SM_REMOTECONTROL,               TEXT("SM_REMOTECONTROL"),               TEXT("��ǰ�ն˷������Ự�Ƿ�Զ�̿���"),
	SM_REMOTESESSION,               TEXT("SM_REMOTESESSION"),               TEXT("���ý����Ƿ����ն˷���ͻ����Ự����"),
	SM_SAMEDISPLAYFORMAT,           TEXT("SM_SAMEDISPLAYFORMAT"),           TEXT("������ʾ������ɫ��ʽ�Ƿ���ͬ"),
	SM_SECURE,                      TEXT("SM_SECURE"),                      TEXT("ʼ�շ���0"),
	SM_SERVERR2,                    TEXT("SM_SERVERR2"),                    TEXT("ϵͳ�Ƿ���Windows Server 2003 R2"),
	SM_SHOWSOUNDS,                  TEXT("SM_SHOWSOUNDS"),                  TEXT("�û��Ƿ�Ҫ��Ӧ�ó���������������Կ��ӷ�ʽ������Ϣ"),
	SM_SHUTTINGDOWN,                TEXT("SM_SHUTTINGDOWN"),                TEXT("��ǰ�Ự�Ƿ����ڹر�"),
	SM_SLOWMACHINE,                 TEXT("SM_SLOWMACHINE"),                 TEXT("������Ƿ���еͶ�(����)������"),
	SM_STARTER,                     TEXT("SM_STARTER"),                     TEXT("��ǰ����ϵͳ�汾"),
	SM_SWAPBUTTON,                  TEXT("SM_SWAPBUTTON"),                  TEXT("���������Ҽ��Ĺ����Ƿ񻥻���"),
	SM_SYSTEMDOCKED,                TEXT("SM_SYSTEMDOCKED"),                TEXT("ͣ��ģʽ��״̬"),
	SM_TABLETPC,                    TEXT("SM_TABLETPC"),                    TEXT("�Ƿ�������Tablet PC�������"),
	SM_XVIRTUALSCREEN,              TEXT("SM_XVIRTUALSCREEN"),              TEXT("������Ļ��������"),
	SM_YVIRTUALSCREEN,              TEXT("SM_YVIRTUALSCREEN"),              TEXT("������Ļ����������")
};
 
const int NUMLINES = sizeof(METRICS) / sizeof(METRICS[0]);

void MessageProc_WM_PAINT(HWND hWnd)
{
	HDC hdc = NULL;
	PAINTSTRUCT ps = { 0 };
	TCHAR szText[] = TEXT("Hello Windows API!");
	TCHAR szBuffer[1024] = TEXT("");
	HFONT hFont = CreateFont(20, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, DRAFT_QUALITY, DEFAULT_PITCH, TEXT("./���ﺺ�����ܺ���.ttf"));
	RECT mScreenRect = { 0 };
	int i = 0;
	int* arrCharWidth = NULL;
	int arrTapStopPositions[] = { 100, 240, 1000 };
	SIZE mSzTextSize = { 0 };
	GetClientRect(hWnd, &mScreenRect);

	hdc = BeginPaint(hWnd, &ps);
	hFont = SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);
	//SetBkMode(hdc, OPAQUE);
	SetTextColor(hdc, 0xCBBCCB);
	SetBkColor(hdc, 0x000000);

	//����
	for (i = 0; i < NUMLINES; i++)
	{
		int tmpMode = SetTextAlign(hdc, TA_CENTER | TA_TOP | TA_NOUPDATECP);
		SetTextCharacterExtra(hdc, 0);
		//TextOut(hdc, 30, i * 20, szBuffer, _stprintf_s(szBuffer, _countof(szBuffer), TEXT("%d"), i));
		//TextOut(hdc, 180, i * 20, szBuffer, _stprintf_s(szBuffer, _countof(szBuffer), TEXT("%d"), GetSystemMetrics(i)));
		//SetTextCharacterExtra(hdc, 2);
		//TextOut(hdc, 500, i * 20, METRICS[i].m_pDesc, _tcslen(METRICS[i].m_pDesc));
		//SetTextCharacterExtra(hdc, 4);
		//TextOut(hdc, 1000, i * 20, METRICS[i].m_pLabel, _tcslen(METRICS[i].m_pLabel));

		_stprintf_s(szBuffer, _countof(szBuffer), TEXT("%d\t%d\t%s\t%s"), i, GetSystemMetrics(i), METRICS[i].m_pDesc, METRICS[i].m_pLabel);
		TabbedTextOut(hdc, 30, i * 20, szBuffer, _tcslen(szBuffer), _countof(arrTapStopPositions), arrTapStopPositions, 0);

		SetTextAlign(hdc, tmpMode);	
		SetTextCharacterExtra(hdc, 0);
	}

	GetTextExtentPoint(hdc, szText, _tcslen(szText), &mSzTextSize);
	//GetTabbedTextExtent(hdc, szText, _tcslen(szText), 0, &mSzTextSize);

	//TextOut(hdc, (GetSystemMetrics(SM_CXSCREEN) - mSzTextSize.cx) / 2, (GetSystemMetrics(SM_CYSCREEN) - mSzTextSize.cy) / 2, szText, _tcslen(szText));
	//ExtTextOut(hdc, (GetSystemMetrics(SM_CXSCREEN) - mSzTextSize.cx) / 2, (GetSystemMetrics(SM_CYSCREEN) - mSzTextSize.cy) / 2, 0, NULL, szText, _tcslen(szText), NULL);
	//DrawTextEx(hdc, szText, _tcslen(szText), &mScreenRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_WORDBREAK, NULL);

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

}

void KeyUp_F9(HWND hWnd)
{
	static BOOL s_bWindowOnTopLayerState = FALSE;
 
	LONG newLong = 0;
	TCHAR szBuffer[1024] = TEXT("");

	//����Ϊ���ʱ���ܵ��Z����
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
		HDC hdc = GetDC(NULL);
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

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, NULL, NULL);		//��������
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

	//ע�ᴰ����
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

	//��ʾ����
	hWndMain = CreateWindowEx(WS_EX_ACCEPTFILES, windowClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, hInstance, NULL);
	ShowWindow(hWndMain, SW_SHOW);
	UpdateWindow(hWndMain);

	//��Ϣѭ��
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
				//��Ϣ�ַ�
				TranslateMessage(&useMessage);
				DispatchMessage(&useMessage);
			}
		}
	}

	return 0;
}