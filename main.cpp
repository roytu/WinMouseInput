#pragma once

#include "include\MouseInput.h"
#include <windows.h>
#include <iostream>

using namespace cv;

int main()
{
	HWND hWnd = FindWindow(NULL, TEXT("Window"));
	if(hWnd == NULL)
	{
		return 1;
	}
	Sleep(1000);
	for(int x = 0; x < 10; x++) {
		for(int y = 0; y < 10; y++) {
			MouseInput::mouseClick(&hWnd, x + 300, y + 700);
		}
	}
	return 0;
}