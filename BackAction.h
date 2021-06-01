#pragma once
#include "BackAction.h"
#include "Action.h"

class BackAction : public Action
{
private:

public:
	BackAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};
