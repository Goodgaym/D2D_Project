#pragma once

class Window {
public:
	static WPARAM WinRun(class IExcute* main);

private:
	static void WindowCreate();
	static void WindowDestroy();

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	static class IExcute* mainExcute;
};