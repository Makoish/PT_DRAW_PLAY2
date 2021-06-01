#ifndef ADD_FIGURE_ACTION_H
#define ADD_FIGURE_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddFigureAction : public Action
{
private:
	Point P1;
public:
	AddFigureAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	//Reads rectangle parameters

	//Add rectangle to the ApplicationManager
	

};

#endif