#ifndef __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__
#define __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__

#include "KeepAliveOperationSequenceAction.h"
#include "KeepAliveOperationSequenceActionStepsImpl.h"

class KeepAliveOperationForwardAction : public KeepAliveOperationSequenceAction
{
public:
	KeepAliveOperationForwardAction();

private:
	KeepAliveOperationSequenceActionStepsImpl steps;
};

#endif
