#ifndef __KEEP_ALIVE_OPERATION_JUMP_ACTION_H__
#define __KEEP_ALIVE_OPERATION_JUMP_ACTION_H__

#include "KeepAliveOperationAction.h"
#include "KeepAliveOperationSequenceAction.h"
#include "KeepAliveOperationSequenceActionStepsImpl.h"

class KeepAliveOperationJumpAction : public KeepAliveOperationSequenceAction
{
public:
	KeepAliveOperationJumpAction();

private:
	KeepAliveOperationSequenceActionStepsImpl steps;
};

#endif
