#include "KeepAliveOperationForwardAction.h"

#include <Windows.h>

KeepAliveOperationForwardAction::KeepAliveOperationForwardAction()
	: keyStatus(0)
	, elapsed(0)
	, actionMax((200 + rand() % 300) / 1000.0)
{
}

void KeepAliveOperationForwardAction::tick(double deltaSeconds)
{
	elapsed += deltaSeconds;

	if (!keyStatus)
	{
		keybd_event('W', 0, 0, NULL);
		keyStatus++;
	}
	else if (keyStatus == 1 && elapsed >= actionMax)
	{
		keybd_event('W', 0, KEYEVENTF_KEYUP, NULL);
		keyStatus++;
	}
}

bool KeepAliveOperationForwardAction::isComplete()
{
	return keyStatus >= 2 && elapsed >= actionMax;
}
