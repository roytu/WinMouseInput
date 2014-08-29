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
	MouseInput::mouseMove(&hWnd, 0.1, 0.1);
	Sleep(1000);
	MouseInput::mouseMove(&hWnd, 0.1, 0.9);
	Sleep(1000);
	MouseInput::mouseMove(&hWnd, 0.9, 0.9);
	Sleep(1000);
	MouseInput::mouseMove(&hWnd, 0.9, 0.1);
	return 0;
}