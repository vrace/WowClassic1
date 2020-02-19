#include "KeepAliveOperationJumpAction.h"
#include "../step/KeepAliveOperationActionKeyDownStep.h"
#include "../step/KeepAliveOperationActionKeyUpStep.h"
#include "../step/KeepAliveOperationActionWaitStep.h"

#include <Windows.h>

KeepAliveOperationJumpAction::KeepAliveOperationJumpAction()
	: KeepAliveOperationSequenceAction(&steps)
{
	steps.add(new KeepAliveOperationActionKeyDownStep(VK_SPACE));
	steps.add(new KeepAliveOperationActionWaitStep((1000 + rand() % 3000) / 1000.0));
	steps.add(new KeepAliveOperationActionKeyUpStep(VK_SPACE));
}
