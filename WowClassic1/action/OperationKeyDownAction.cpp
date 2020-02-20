#include "OperationKeyDownAction.h"

#include <Windows.h>

OperationKeyDownAction::OperationKeyDownAction(unsigned char _keyCode)
	: keyCode(_keyCode)
{
}

void OperationKeyDownAction::tick(double deltaSeconds)
{
	keybd_event(keyCode, 0, 0, NULL);
}

bool OperationKeyDownAction::isComplete()
{
	return true;
}
