#pragma once
#include "Action.h"

//Add tringle  Action class
class AddTriangAction : public Action
{
private:
	Point P1,P2,P3; //tringle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriangAction(ApplicationManager* pApp);

	//Reads tringle parameters
	virtual void ReadActionParameters();

	//Add Tringle to the ApplicationManager
	virtual void Execute();

};

