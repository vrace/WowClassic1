#include "OperationKeyUpAction.h"

#include <Windows.h>

OperationKeyUpAction::OperationKeyUpAction(unsigned char _keyCode)
	: keyCode(_keyCode)
{
}

void OperationKeyUpAction::tick(double deltaSeconds)
{
	keybd_event(keyCode, 0, KEYEVENTF_KEYUP, NULL);
}

bool OperationKeyUpAction::isComplete()
{
	return true;
}
