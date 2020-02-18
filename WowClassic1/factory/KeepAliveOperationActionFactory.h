#ifndef __KEEP_ALIVE_OPERATION_ACTION_FACTORY_H__
#define __KEEP_ALIVE_OPERATION_ACTION_FACTORY_H__

#include "../action/KeepAliveOperationAction.h"

class KeepAliveOperationActionFactory
{
public:
	KeepAliveOperationActionFactory();
	void enter();
	KeepAliveOperationAction* create();

private:
	bool shouldIdle;
};

#endif
