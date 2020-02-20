#ifndef __KEEP_ALIVE_OPERATION_ACTION_FACTORY_H__
#define __KEEP_ALIVE_OPERATION_ACTION_FACTORY_H__

#include "../action/OperationAction.h"

class KeepAliveOperationActionFactory
{
public:
	KeepAliveOperationActionFactory();
	void enter();
	OperationAction* create();

private:
	bool shouldIdle;
};

#endif
