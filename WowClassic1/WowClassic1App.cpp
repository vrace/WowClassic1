#include <Windows.h>
#include "ui/MainWindow.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	srand((UINT)GetCurrentTime());
	ShowMainWindow();
	return 0;
}
