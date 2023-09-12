#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include<Windowsx.h>
#include"resource.h"

void MessageProc_WM_COMMAND(HWND hWnd,WPARAM wParam)
{
	TCHAR szTextBuffer[1024] = { 0 };
	TCHAR szMenuStringBuffer[512] = { 0 };
	UINT idBuffer = idBuffer = LOWORD(wParam);
	wsprintf(szMenuStringBuffer, TEXT("δ֪"));
	switch (LOWORD(wParam))
	{
	case ID_FILE_NEW:
		wsprintf(szMenuStringBuffer, TEXT("�½�"));
		break;
	case ID_FILE_OPEN:
		wsprintf(szMenuStringBuffer, TEXT("��"));
		break;
	case ID_FILE_SAVE:
		wsprintf(szMenuStringBuffer, TEXT("����"));
		break;
	case ID_FILE_EXIT:
		wsprintf(szMenuStringBuffer, TEXT("�˳�"));
		idBuffer = ID_FILE_EXIT;

		wsprintf(szTextBuffer, TEXT("��ʹ���� [%s] �˵������ID: %d\n"), szMenuStringBuffer, idBuffer);
		MessageBox(hWnd, szTextBuffer, TEXT("��ʾ"), MB_OK);

		PostMessage(hWnd, WM_QUIT, 0, 0);
		break;

	case ID_EDIT_COPY:
		wsprintf(szMenuStringBuffer, TEXT("����"));
		break;
	case ID_EDIT_CUT:
		wsprintf(szMenuStringBuffer, TEXT("����"));
		break;
	case ID_EDIT_PASTE:
		wsprintf(szMenuStringBuffer, TEXT("ճ��"));
		break;
	case ID_EDIT_RED:
		wsprintf(szMenuStringBuffer, TEXT("��"));
		break;
	case ID_EDIT_GREEN:
		wsprintf(szMenuStringBuffer, TEXT("��"));
		break;
	case ID_EDIT_BLUE:
		wsprintf(szMenuStringBuffer, TEXT("��"));
		break;
	case ID_EDIT_UPPER:
		wsprintf(szMenuStringBuffer, TEXT("��д��ĸ"));
		break;
	case ID_EDIT_LOWER:
		wsprintf(szMenuStringBuffer, TEXT("Сд��ĸ"));
		break;

	case ID_HELP_ABOUT:
		wsprintf(szMenuStringBuffer, TEXT("����"));
		break;

	case ID_VIEW_BIG:
		wsprintf(szMenuStringBuffer, TEXT("��ͼ��"));
		break;
	case ID_VIEW_SMAL:
		wsprintf(szMenuStringBuffer, TEXT("Сͼ��"));
		break;

	default:
		break;
	}
	wsprintf(szTextBuffer, TEXT("��ʹ���� [%s] �˵������ID: %d\n"), szMenuStringBuffer, idBuffer);
	MessageBox(hWnd, szTextBuffer, TEXT("��ʾ"), MB_OK);
}

void MessageProc_WM_SYSCOMMAND(HWND hWnd, WPARAM wParam)
{
	TCHAR szTextBuffer[1024] = { 0 };
	TCHAR szMenuStringBuffer[512] = { 0 };
	UINT idBuffer = wParam;

	switch (wParam)
	{
	case SC_CLOSE:
		wsprintf(szMenuStringBuffer, TEXT("�˳�"));
		idBuffer = ID_FILE_EXIT;

		wsprintf(szTextBuffer, TEXT("��ʹ���� [%s] �˵������ID: %d\n"), szMenuStringBuffer, idBuffer);
		MessageBox(hWnd, szTextBuffer, TEXT("��ʾ"), MB_OK);
		break;
	case ID_FILE_OPEN:
		wsprintf(szMenuStringBuffer, TEXT("��"));

		wsprintf(szTextBuffer, TEXT("��ʹ���� [%s] �˵������ID: %d\n"), szMenuStringBuffer, idBuffer);
		MessageBox(hWnd, szTextBuffer, TEXT("��ʾ"), MB_OK);
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

	//���������˵���
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_VIEW_BIG, TEXT("��ͼ��"));		//�����˵�����
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_VIEW_SMAL, TEXT("Сͼ��"));		//�����˵�����
	InsertMenu(hMainMenu, -1, MF_POPUP | MF_STRING, (UINT_PTR)hPopupMenu, TEXT("��ͼ"));	//�����˵����������˵�

	InsertMenu(hSubMenu, -1, MF_SEPARATOR, NULL, NULL);
	InsertMenu(hSubMenu, -1, MF_STRING, ID_EDIT_RED, TEXT("��(&R)"));
	InsertMenu(hSubMenu, -1, MF_STRING, ID_EDIT_GREEN, TEXT("��(&G)"));
	InsertMenu(hSubMenu, -1, MF_STRING, ID_EDIT_BLUE, TEXT("��(&B)"));

	InsertMenu(hSubMenu, -1, MF_SEPARATOR, NULL, NULL);

	//�ڵ����˵���������ӵ����˵�
	hPopupMenu = CreateMenu();
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_EDIT_UPPER, TEXT("��д��ĸ(&U)"));
	InsertMenu(hPopupMenu, -1, MF_STRING, ID_EDIT_LOWER, TEXT("Сд��ĸ(&L)"));
	InsertMenu(hSubMenu, -1, MF_STRING | MF_POPUP, (UINT_PTR)hPopupMenu, TEXT("���Ĵ�Сд(&N)"));

	//������������ֻ��ѡһ��
	CheckMenuRadioItem(GetSubMenu(hMainMenu, 1), ID_EDIT_RED, ID_EDIT_BLUE, ID_EDIT_RED, MF_BYCOMMAND);

	SetMenu(hWnd, hMainMenu);

	ModifyMenu(GetSystemMenu(hWnd, FALSE), SC_CLOSE, MF_GRAYED, SC_CLOSE, TEXT("�ر�(&C)\tAlt+F4"));
	InsertMenu(GetSystemMenu(hWnd, FALSE), -1, MF_STRING, ID_FILE_OPEN, TEXT("��(&O)\tCtrl+O"));

}

void MessageProc_WM_RBUTTONUP(HWND hWnd, LPARAM lParam)
{
	HMENU hMainMenu = GetMenu(hWnd);
	HMENU hPopupMenu = GetSubMenu(hMainMenu, 1);
	POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };

	ClientToScreen(hWnd, &pt);

	GetMenuItemCount(hPopupMenu);	//��һ���˵����ж��ٲ˵���

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

	//ע�ᴰ����
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

	//��ʾ����
	hWindowMain = CreateWindowEx(WS_EX_ACCEPTFILES, mainWndClassName, mainWndName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500, NULL, NULL, hInstance, NULL);
	ShowWindow(hWindowMain, SW_SHOW);
	UpdateWindow(hWindowMain);

	//��Ϣѭ��
	while (TRUE)
	{
		if (PeekMessage(&userMessage, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&userMessage, NULL, 0, 0))
			{
				if (!TranslateAccelerator(hWindowMain, hAccel, &userMessage))
				{
					//��Ϣ�ַ��뷭��
					TranslateMessage(&userMessage);
					DispatchMessage(&userMessage);
				}
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