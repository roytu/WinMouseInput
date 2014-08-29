#pragma once

#include "MouseInput.h"
#include <windows.h>
#include <iostream>

int main()
{
	HWND hWnd = GetDesktopWindow();
	if(hWnd == NULL)
	{
		return 1;
	}
	Sleep(1000);
	MouseInput::mouseClick(&hWnd, 200, 200);
	Sleep(1000);
	MouseInput::mouseClick(&hWnd, 400, 200);
	Sleep(1000);
	MouseInput::mouseClick(&hWnd, 400, 400);
	Sleep(1000);
	MouseInput::mouseClick(&hWnd, 200, 400);
	return 0;
}