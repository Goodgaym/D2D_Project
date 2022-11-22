/////////////////////////////////
// Filename: main.cpp
/////////////////////////////////
#include "stdafx.h"
#include "Main.h"
#include "Systems/Window.h"

int APIENTRY WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE prevInstance,
	_In_ LPSTR lPCmdLine,
	_In_ int nCmdShow
) {

	WPARAM wParam = Window::Run(main);

	WinRun();

	return 0;
}