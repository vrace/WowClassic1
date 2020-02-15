#include "MainWindow.h"

#include <Windows.h>

#include "../resource.h"
#include "../enum/WowOperation.h"
#include "ChooseOperationWindow.h"

static WowOperation theOperation = woIdle;

void MainWindowInit(HWND hwnd)
{
	HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
	SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
	SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
}

void MainWindowChangeOperation(HWND hwnd)
{
	int op = ShowChooseOperation(hwnd);
	if (op >= 0)
		theOperation = (WowOperation)op;
}

BOOL MainWindowCommand(HWND hwnd, WORD id)
{
	switch (id)
	{
	case IDOK:
	case IDCANCEL:
		EndDialog(hwnd, 0);
		return TRUE;

	case IDC_CHANGE_OPERATION:
		MainWindowChangeOperation(hwnd);
		return TRUE;

	default:
		break;
	}

	return FALSE;
}

void MainWindowTick(HWND hwnd)
{

}

INT_PTR CALLBACK MainWindowProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		MainWindowInit(hwnd);
		return TRUE;

	case WM_COMMAND:
		return MainWindowCommand(hwnd, LOWORD(wParam));

	case WM_TIMER:
		MainWindowTick(hwnd);
		return TRUE;

	default:
		break;
	}

	return FALSE;
}

void ShowMainWindow()
{
	DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_MAIN), NULL, MainWindowProc);
}
