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

void MouseInput::mouseMove(HWND* hwnd, float x, float y)
{
	RECT rect;
	GetWindowRect(*hwnd, &rect);

	x += rect.left;
	y += rect.top;

	SetForegroundWindow(*hwnd);
	SetCursorPos(x * GetSystemMetrics(SM_CXSCREEN), y * GetSystemMetrics(SM_CYSCREEN));
	Sleep(MOUSE_DELAY);
}

void MouseInput::mouseClick(HWND* hwnd, float x, float y)
{
	RECT rect;
	GetWindowRect(*hwnd, &rect);

	x += rect.left;
	y += rect.top;

	SetForegroundWindow(*hwnd);
	SetCursorPos(x * GetSystemMetrics(SM_CXSCREEN), y * GetSystemMetrics(SM_CYSCREEN));
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_LBUTTONDOWN, 0, MAKELPARAM(x, y));
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_LBUTTONUP, 0, MAKELPARAM(x, y));
}

void MouseInput::mouseRightClick(HWND* hwnd, float x, float y)
{
	RECT rect;
	GetWindowRect(*hwnd, &rect);

	x += rect.left;
	y += rect.top;

	SetForegroundWindow(*hwnd);
	SetCursorPos(x * GetSystemMetrics(SM_CXSCREEN), y * GetSystemMetrics(SM_CYSCREEN));
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_RBUTTONDOWN, 0, MAKELPARAM(x, y));
	Sleep(MOUSE_DELAY);
	PostMessage(*hwnd, WM_RBUTTONUP, 0, MAKELPARAM(x, y));
}