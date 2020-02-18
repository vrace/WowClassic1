#include "KeepAliveOperationJumpAction.h"

#include <Windows.h>

KeepAliveOperationJumpAction::KeepAliveOperationJumpAction()
	: elapsed(0)
	, totalTicks(2 + rand() % 10)
{
}

void KeepAliveOperationJumpAction::tick()
{
	elapsed++;

	if (elapsed == 1)
	{
		keybd_event(VK_SPACE, 0, 0, NULL);
	}
	else if (elapsed == totalTicks)
	{
		keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, NULL);
	}
}

bool KeepAliveOperationJumpAction::isComplete()
{
	return elapsed >= totalTicks;
}
