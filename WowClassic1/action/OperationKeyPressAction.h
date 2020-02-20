#ifndef __OPERATION_KEY_PRESS_ACTION_H__
#define __OPERATION_KEY_PRESS_ACTION_H__

#include "OperationSequenceAction.h"

class OperationKeyPressAction : public OperationSequenceAction
{
public:
	OperationKeyPressAction(unsigned char keyCode);
};

#endif
