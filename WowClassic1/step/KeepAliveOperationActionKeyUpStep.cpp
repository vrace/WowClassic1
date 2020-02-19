#include "KeepAliveOperationActionKeyUpStep.h"
#include <Windows.h>

KeepAliveOperationActionKeyUpStep::KeepAliveOperationActionKeyUpStep(unsigned char _keyCode)
	: keyCode(_keyCode)
{
}

double KeepAliveOperationActionKeyUpStep::expectedDuration()
{
	return 0;
}

void KeepAliveOperationActionKeyUpStep::perform()
{
	keybd_event(keyCode, 0, KEYEVENTF_KEYUP, NULL);
}
