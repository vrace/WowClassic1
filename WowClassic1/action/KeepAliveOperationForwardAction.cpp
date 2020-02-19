#include "KeepAliveOperationForwardAction.h"

#include <Windows.h>

KeepAliveOperationForwardAction::KeepAliveOperationForwardAction()
	: KeepAliveOperationSequenceAction(&steps)
{
}

KeepAliveOperationForwardActionSteps::KeepAliveOperationForwardActionSteps()
	: waitPeriod((200 + rand() % 300) / 1000.0)
{
}

int KeepAliveOperationForwardActionSteps::numberOfSteps()
{
	return 3;
}

double KeepAliveOperationForwardActionSteps::expectedDurationForStepAtIndex(int index)
{
	switch (index)
	{
	case 0:
		return 0;

	case 1:
		return waitPeriod;

	case 2:
		return 0;

	default:
		break;
	}

	return 0;
}

void KeepAliveOperationForwardActionSteps::performStepAtIndex(int index)
{
	switch (index)
	{
	case 0:
		keybd_event('W', 0, 0, NULL);
		break;

	case 2:
		keybd_event('W', 0, KEYEVENTF_KEYUP, NULL);
		break;

	default:
		break;
	}
}
