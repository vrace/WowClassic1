#include "KeepAliveOperationJumpAction.h"

#include <Windows.h>

KeepAliveOperationJumpAction::KeepAliveOperationJumpAction()
	: currentTick(2)
{

}

void KeepAliveOperationJumpAction::tick()
{
	currentTick++;

	switch (currentTick)
	{
	case 1:
		keybd_event(VK_SPACE, 0, 0, NULL);
		break;

	case 2:
		keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, NULL);
		break;

	case 100:
		currentTick = 0;
		break;

	default:
		break;
	}
}
