#include "KeepAliveOperationForwardAction.h"
#include "../step/KeepAliveOperationActionKeyDownStep.h"
#include "../step/KeepAliveOperationActionKeyUpStep.h"
#include "../step/KeepAliveOperationActionWaitStep.h"

#include <Windows.h>

KeepAliveOperationForwardAction::KeepAliveOperationForwardAction()
	: KeepAliveOperationSequenceAction(&steps)
{
	steps.add(new KeepAliveOperationActionKeyDownStep('W'));
	steps.add(new KeepAliveOperationActionWaitStep((1000 + rand() % 3000) / 1000.0));
	steps.add(new KeepAliveOperationActionKeyUpStep('W'));
}
