#pragma once

#include <Windows.h>

class MouseInput
{
public:
	static const int SCREEN_WIDTH = 1366;
	static const int SCREEN_HEIGHT = 768;

	MouseInput(void);
	~MouseInput(void);
	static void mouseMove(HWND* hwnd, LONG x, LONG y);
	static void mouseClick(HWND* hwnd, LONG x, LONG y);
	static void mouseRightClick(HWND* hwnd, LONG x, LONG y);
};