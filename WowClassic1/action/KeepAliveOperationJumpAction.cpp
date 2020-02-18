#include "KeepAliveOperationJumpAction.h"

#include <Windows.h>

KeepAliveOperationJumpAction::KeepAliveOperationJumpAction()
	: keyStatus(0)
	, elapsed(0)
	, actionMax((200 + rand() % 300) / 1000.0)
{
}

void KeepAliveOperationJumpAction::tick(double deltaSeconds)
{
	elapsed += deltaSeconds;

	if (!keyStatus)
	{
		keybd_event(VK_SPACE, 0, 0, NULL);
		keyStatus++;
	}
	else if (keyStatus == 1 && elapsed >= actionMax)
	{
		keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, NULL);
		keyStatus++;
	}
}

bool KeepAliveOperationJumpAction::isComplete()
{
	return keyStatus >= 2 && elapsed >= actionMax;
}
