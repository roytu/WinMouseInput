#pragma once

#include "MouseInput.h"
#include <iostream>

const int MOUSE_DELAY = 10;

MouseInput::MouseInput(void)
{
}


MouseInput::~MouseInput(void)
{
}

void MouseInput::mouseClick(HWND* hwnd, LONG x, LONG y)
{
	RECT rect;
	GetWindowRect(*hwnd, &rect);

	x += rect.left;
	y += rect.top;

	SetForegroundWindow(*hwnd);
	SetCursorPos(x, y);
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_LBUTTONDOWN, 0, MAKELPARAM(x, y));
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_LBUTTONUP, 0, MAKELPARAM(x, y));
}

void MouseInput::mouseRightClick(HWND* hwnd, LONG x, LONG y)
{
	RECT rect;
	GetWindowRect(*hwnd, &rect);

	x += rect.left;
	y += rect.top;

	SetForegroundWindow(*hwnd);
	SetCursorPos(x, y);
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_RBUTTONDOWN, 0, MAKELPARAM(x, y));
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_RBUTTONUP, 0, MAKELPARAM(x, y));
}