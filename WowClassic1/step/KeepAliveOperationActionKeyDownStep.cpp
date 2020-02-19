#include "KeepAliveOperationActionKeyDownStep.h"
#include <Windows.h>

KeepAliveOperationActionKeyDownStep::KeepAliveOperationActionKeyDownStep(unsigned char _keyCode)
	: keyCode(_keyCode)
{
}

double KeepAliveOperationActionKeyDownStep::expectedDuration()
{
	return 0;
}

void KeepAliveOperationActionKeyDownStep::perform()
{
	keybd_event(keyCode, 0, 0, NULL);
}
