#include "KeepAliveOperationActionWaitStep.h"

KeepAliveOperationActionWaitStep::KeepAliveOperationActionWaitStep(double _duration)
	: duration(_duration)
{
}

double KeepAliveOperationActionWaitStep::expectedDuration()
{
	return duration;
}

void KeepAliveOperationActionWaitStep::perform()
{
}
