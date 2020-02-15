#include "ChooseOperationWindow.h"

#include <Windows.h>
#include <windowsx.h>

#include "../resource.h"

static int theOperation = 0;

void ChooseOperationInit(HWND hwnd)
{
	theOperation = 0;
	Button_SetCheck(GetDlgItem(hwnd, IDC_IDLE), BST_CHECKED);
}

int ChooseOperationFindChecked(HWND hwnd)
{
	int radioButtons[] = { IDC_IDLE, IDC_QUEUE, IDC_KEEP_ALIVE };
	
	for (int i = 0; i < sizeof(radioButtons) / sizeof(radioButtons[0]); i++)
	{
		if (Button_GetCheck(GetDlgItem(hwnd, radioButtons[i])) == BST_CHECKED)
			return i;
	}

	return -1;
}

BOOL ChooseOperationCommand(HWND hwnd, WORD id)
{
	switch (id)
	{
	case IDOK:
		theOperation = ChooseOperationFindChecked(hwnd);
		// fall through
	case IDCANCEL:
		EndDialog(hwnd, id);
		return TRUE;

	default:
		break;
	}

	return FALSE;
}

INT_PTR CALLBACK ChooseOperationProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		ChooseOperationInit(hwnd);
		return TRUE;

	case WM_COMMAND:
		return ChooseOperationCommand(hwnd, LOWORD(wParam));

	default:
		break;
	}

	return FALSE;
}

int ShowChooseOperation(HWND hParent)
{
	if (DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_CHANGE_OPERATION), hParent, ChooseOperationProc) == IDCANCEL)
		return -1;

	return theOperation;
}
