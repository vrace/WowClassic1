#include "OperationKeyPressAction.h"
#include "OperationKeyDownAction.h"
#include "OperationKeyUpAction.h"
#include "OperationWaitAction.h"

#include <Windows.h>

OperationKeyPressAction::OperationKeyPressAction(unsigned char keyCode)
{
	addAction(new OperationKeyDownAction(keyCode));
	addAction(new OperationWaitAction((1000 + rand() % 3000) / 1000.0));
	addAction(new OperationKeyUpAction(keyCode));
}
