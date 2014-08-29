#pragma once

#include <Windows.h>

class MouseInput
{
public:
	MouseInput(void);
	~MouseInput(void);
	static void mouseMove(HWND* hwnd, float x, float y);
	static void mouseClick(HWND* hwnd, float x, float y);
	static void mouseRightClick(HWND* hwnd, float x, float y);
};