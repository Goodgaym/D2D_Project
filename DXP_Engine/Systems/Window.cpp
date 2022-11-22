#include "Framework.h"
#include "window.h"

UINT g_Width = 1920;
UINT g_Height = 1080;
HWND g_Hwnd;
LPCTSTR g_Title = TEXT("Window");

void Window::WindowCreate()
{
	// Wnd Class
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbWndExtra = NULL;
	wc.cbClsExtra = NULL;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_Title;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	WORD check = RegisterClassEx(&wc);
	assert(check != NULL);

	// Create Window
	g_Hwnd = CreateWindowW(
		wc.lpszClassName,
		wc.lpszClassName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		g_Width,
		g_Height,
		NULL,
		NULL,
		wc.hInstance,
		NULL
	);
	assert(g_Hwnd != NULL);

	ShowWindow(g_Hwnd, nCmdShow);
	UpdateWindow(g_Hwnd);
}

void Window::WindowDestroy()
{
}

WPARAM WinRun()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (true) {
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

		}
	}

	return msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	/*case WM_SIZE: {
		Width = LOWORD(lParam);
		Height = HIWORD(lParam);
	}*/
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}