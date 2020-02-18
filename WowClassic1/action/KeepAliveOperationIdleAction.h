#ifndef __KEEP_ALIVE_OPERATION_IDLE_ACTION_H__
#define __KEEP_ALIVE_OPERATION_IDLE_ACTION_H__

class KeepAliveOperationIdleAction
{
public:
	KeepAliveOperationIdleAction(int idleTicks);
	void tick();
	bool isComplete();

private:
	int elapsed;
	int idleTicks;
};

#endif
