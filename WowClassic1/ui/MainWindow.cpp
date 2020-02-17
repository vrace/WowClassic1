#include "MainWindow.h"

#include <Windows.h>
#include <memory>

#include "../resource.h"
#include "../enum/WowOperation.h"
#include "../controller/OperationController.h"
#include "../controller/IdleOperationController.h"
#include "../controller/KeepAliveOperationController.h"
#include "ChooseOperationWindow.h"

static WowOperation theOperation = woIdle;
static std::unique_ptr<OperationController> theControllers[woOperationCount];

void MainWindowInit(HWND hwnd)
{
	theControllers[woIdle].reset(new IdleOperationController());
	theControllers[woQueue].reset(new IdleOperationController());
	theControllers[woKeepAlive].reset(new KeepAliveOperationController());

	theOperation = woIdle;
	theControllers[theOperation]->enter();

	HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
	SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
	SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

	SetTimer(hwnd, WM_TIMER + 100, 100, NULL);
}

void MainWindowChangeOperation(HWND hwnd)
{
	WowOperation op = (WowOperation)ShowChooseOperation(hwnd);
	if (op >= 0 && op != theOperation)
	{
		theOperation = op;
		theControllers[theOperation]->enter();
	}
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
	theControllers[theOperation]->tick();
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
