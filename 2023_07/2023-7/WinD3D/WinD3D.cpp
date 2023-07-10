#define _CRT_SECURE_NO_WARNINGS

#include<d3d9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

LPDIRECT3D9 g_lpD3D = NULL;
LPDIRECT3DDEVICE9 g_lpD3DDevice = NULL;

bool InitializeD3D(HWND hWnd)
{
	D3DDISPLAYMODE displayMode{ 0 };
	g_lpD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!g_lpD3D)
	{
		return false;
	}
	if (FAILED(g_lpD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode)))
	{
		return false;
	}
	D3DPRESENT_PARAMETERS d3dpp{ 0 };
	d3dpp.Windowed = TRUE;
	d3dpp.BackBufferFormat = displayMode.Format;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	if (FAILED(g_lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_lpD3DDevice)))
	{
		return false;
	}

	return true;
}

void RenderScene()
{
	g_lpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	g_lpD3DDevice->BeginScene();

	//图形输出

	g_lpD3DDevice->EndScene();

	g_lpD3DDevice->Present(NULL,NULL,NULL,NULL);
}

void CloseD3D()
{
	if (g_lpD3DDevice)
	{
		g_lpD3DDevice->Release();
	}
	if (g_lpD3D)
	{
		g_lpD3D->Release();
	}
}

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
	TCHAR szClassName[] = TEXT("D3D Window Class");
	TCHAR szMainWindowName[] = TEXT("This is a DirectX 3D Window");

	WNDCLASSEX wcEx { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.hIcon = LoadIcon(NULL, IDI_SHIELD);
	wcEx.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
	wcEx.hInstance = hIns;
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = szClassName;
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wcEx);

	HWND hWndMain = CreateWindowEx(WS_EX_ACCEPTFILES, szClassName, szMainWindowName,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, hIns, NULL);

	if (!InitializeD3D(hWndMain))
	{
		return 0;
	}

	ShowWindow(hWndMain, SW_SHOW);
	UpdateWindow(hWndMain);

	MSG uMsg{ 0 };

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
			}
		}
		else
		{
			//无消息渲染
			RenderScene();
		}
	}

	CloseD3D();
	UnregisterClass(szClassName, hIns);
	return 0;
}