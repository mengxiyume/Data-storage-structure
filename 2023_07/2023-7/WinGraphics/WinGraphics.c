#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	switch (msgID)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, NULL, NULL);
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
	wcEx.hbrBackground = CreateSolidBrush(0xCBBCCB);
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