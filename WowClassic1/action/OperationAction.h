#ifndef __OPERATION_ACTION_H__
#define __OPERATION_ACTION_H__

class OperationAction
{
public:
	virtual ~OperationAction();
	virtual void tick(double deltaSeconds) = 0;
	virtual bool isComplete() = 0;
};

#endif
