#ifndef __KEEP_ALIVE_OPERATION_ACTION_H__
#define __KEEP_ALIVE_OPERATION_ACTION_H__

class KeepAliveOperationAction
{
public:
	virtual ~KeepAliveOperationAction();
	virtual void tick(double deltaSeconds) = 0;
	virtual bool isComplete() = 0;
};

#endif
