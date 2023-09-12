#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include<Windowsx.h>
#include"resource.h"

void MessageProc_WM_COMMAND(HWND hWnd,WPARAM wParam)
{
	TCHAR szTextBuffer[1024] = { 0 };
	TCHAR szMenuStringBuffer[512] = { 0 };
	UINT idBuffer = idBuffer = LOWORD(wParam);
	wsprintf(szMenuStringBuffer, TEXT("未知"));
	switch (LOWORD(wParam))
	{
	case ID_FILE_NEW:
		wsprintf(szMenuStringBuffer, TEXT("新建"));
		break;
	case ID_FILE_OPEN:
		wsprintf(szMenuStringBuffer, TEXT("打开"));
		break;
	case ID_FILE_SAVE:
		wsprintf(szMenuStringBuffer, TEXT("保存"));
		break;
	case ID_FILE_EXIT:
		wsprintf(szMenuStringBuffer, TEXT("退出"));
		idBuffer = ID_FILE_EXIT;

		wsprintf(szTextBuffer, TEXT("您使用了 [%s] 菜单项，命令ID: %d\n"), szMenuStringBuffer, idBuffer);
		MessageBox(hWnd, szTextBuffer, TEXT("提示"), MB_OK);

		PostMessage(hWnd, WM_QUIT, 0, 0);
		break;

	case ID_EDIT_COPY:
		wsprintf(szMenuStringBuffer, TEXT("复制"));
		break;
	case ID_EDIT_CUT:
		wsprintf(szMenuStringBuffer, TEXT("剪切"));
		break;
	case ID_EDIT_PASTE:
		wsprintf(szMenuStringBuffer, TEXT("粘贴"));
		break;
	case ID_EDIT_RED:
		wsprintf(szMenuStringBuffer, TEXT("红"));
		break;
	case ID_EDIT_GREEN:
		wsprintf(szMenuStringBuffer, TEXT("绿"));
		break;
	case ID_EDIT_BLUE:
		wsprintf(szMenuStringBuffer, TEXT("蓝"));
		break;
	case ID_EDIT_UPPER:
		wsprintf(szMenuStringBuffer, TEXT("大写字母"));
		break;
	case ID_EDIT_LOWER:
		wsprintf(szMenuStringBuffer, TEXT("小写字母"));
		break;

	case ID_HELP_ABOUT:
		wsprintf(szMenuStringBuffer, TEXT("关于"));
		break;

	case ID_VIEW_BIG:
		wsprintf(szMenuStringBuffer, TEXT("大图标"));
		break;
	case ID_VIEW_SMAL:
		wsprintf(szMenuStringBuffer, TEXT("小图标"));
		break;

	default:
		break;
	}
	wsprintf(szTextBuffer, TEXT("您使用了 [%s] 菜单项，命令ID: %d\n"), szMenuStringBuffer, idBuffer);
	MessageBox(hWnd, szTextBuffer, TEXT("提示"), MB_OK);
}

void MessageProc_WM_SYSCOMMAND(HWND hWnd, WPARAM wParam)
{
	TCHAR szTextBuffer[1024] = { 0 };
	TCHAR szMenuStringBuffer[512] = { 0 };
	UINT idBuffer = wParam;

	switch (wParam)
	{
	case SC_CLOSE:
		wsprintf(szMenuStringBuffer, TEXT("退出"));
		idBuffer = ID_FILE_EXIT;

		wsprintf(szTextBuffer, TEXT("您使用了 [%s] 菜单项，命令ID: %d\n"), szMenuStringBuffer, idBuffer);
		MessageBox(hWnd, szTextBuffer, TEXT("提示"), MB_OK);
		break;
	case ID_FILE_OPEN:
		wsprintf(szMenuStringBuffer, TEXT("打开"));

		wsprintf(szTextBuffer, TEXT("您使用了 [%s] 菜单项，命令ID: %d\n"), szMenuStringBuffer, idBuffer);
		MessageBox(hWnd, szTextBuffer, TEXT("提示"), MB_OK);
		break;
	default:
		break;
	}

}

void MessageProc_WM_CREATE(HWND hWnd)
{
	HMENU hMainMenu = GetMenu(hWnd);
	HMENU hPopupMenu = CreateMenu();
	HMENU hSubMenu = GetSubMenu(hMainMenu, 1);

	//新增弹出菜单项
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_VIEW_BIG, TEXT("大图标"));		//弹出菜单内容
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_VIEW_SMAL, TEXT("小图标"));		//弹出菜单内容
	InsertMenu(hMainMenu, -1, MF_POPUP | MF_STRING, (UINT_PTR)hPopupMenu, TEXT("视图"));	//弹出菜单链接上主菜单

	InsertMenu(hSubMenu, -1, MF_SEPARATOR, NULL, NULL);
	InsertMenu(hSubMenu, -1, MF_STRING, ID_EDIT_RED, TEXT("红(&R)"));
	InsertMenu(hSubMenu, -1, MF_STRING, ID_EDIT_GREEN, TEXT("绿(&G)"));
	InsertMenu(hSubMenu, -1, MF_STRING, ID_EDIT_BLUE, TEXT("蓝(&B)"));

	InsertMenu(hSubMenu, -1, MF_SEPARATOR, NULL, NULL);

	//于弹出菜单项中添加子弹出菜单
	hPopupMenu = CreateMenu();
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_EDIT_UPPER, TEXT("大写字母(&U)"));
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_EDIT_LOWER, TEXT("小写字母(&L)"));
	InsertMenu(hSubMenu, -1, MF_STRING | MF_POPUP, (UINT_PTR)hPopupMenu, TEXT("更改大小写(&N)"));

	//将红绿蓝项中只复选一项
	CheckMenuRadioItem(GetSubMenu(hMainMenu, 1), ID_EDIT_RED, ID_EDIT_BLUE, ID_EDIT_RED, MF_BYCOMMAND);

	SetMenu(hWnd, hMainMenu);

	ModifyMenu(GetSystemMenu(hWnd, FALSE), SC_CLOSE, MF_GRAYED, SC_CLOSE, TEXT("关闭(&C)\tAlt+F4"));
	InsertMenu(GetSystemMenu(hWnd, FALSE), -1, MF_STRING, ID_FILE_OPEN, TEXT("打开(&O)\tCtrl+O"));

}

void MessageProc_WM_RBUTTONUP(HWND hWnd, LPARAM lParam)
{
	HMENU hMainMenu = GetMenu(hWnd);
	HMENU hPopupMenu = GetSubMenu(hMainMenu, 1);
	POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };

	ClientToScreen(hWnd, &pt);

	GetMenuItemCount(hPopupMenu);	//求一个菜单内有多少菜单项

	TrackPopupMenuEx(hPopupMenu, TPM_CENTERALIGN | TPM_VCENTERALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, hWnd, NULL);
	//MessageBox(hWnd, NULL, NULL, MB_OK);
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	switch (msgID)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, 0, 0);
		return 0;
	case WM_COMMAND:
		MessageProc_WM_COMMAND(hWnd, wParam);
		return 0;
	case WM_SYSCOMMAND:
		MessageProc_WM_SYSCOMMAND(hWnd, wParam);
		return DefWindowProc(hWnd, msgID, wParam, lParam);
	case WM_CREATE:
		MessageProc_WM_CREATE(hWnd);
		return 0;
	case WM_RBUTTONUP:
		MessageProc_WM_RBUTTONUP(hWnd, lParam);
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
	HWND hWindowMain = NULL;
	HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR_MENU_MAIN));

	//注册窗口类
	WNDCLASSEX wcEx = { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = mainWndClassName;
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
	wcEx.hInstance = hInstance;
	wcEx.hIconSm = LoadIcon(NULL, (LPCTSTR)GetStockObject((int)IDI_SHIELD));
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcEx.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	RegisterClassEx(&wcEx);

	//显示窗口
	hWindowMain = CreateWindowEx(WS_EX_ACCEPTFILES, mainWndClassName, mainWndName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500, NULL, NULL, hInstance, NULL);
	ShowWindow(hWindowMain, SW_SHOW);
	UpdateWindow(hWindowMain);

	//消息循环
	while (TRUE)
	{
		if (PeekMessage(&userMessage, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&userMessage, NULL, 0, 0))
			{
				if (!TranslateAccelerator(hWindowMain, hAccel, &userMessage))
				{
					//消息分发与翻译
					TranslateMessage(&userMessage);
					DispatchMessage(&userMessage);
				}
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