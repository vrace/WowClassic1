#ifndef __KEEP_ALIVE_OPERATION_JUMP_ACTION_H__
#define __KEEP_ALIVE_OPERATION_JUMP_ACTION_H__

class KeepAliveOperationJumpAction
{
public:
	KeepAliveOperationJumpAction();
	void tick();

private:
	int currentTick;
};

#endif
