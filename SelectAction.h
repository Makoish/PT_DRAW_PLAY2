#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class SelectAction : public Action
{
private:
	Point P1;
	CFigure * Fig;
	ApplicationManager* pApp;
public:
	SelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
