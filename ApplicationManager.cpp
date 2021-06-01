#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddFigureAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\BackAction.h"
#include "Actions\SelectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriangleAction.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case SELECT:
		pAct = new SelectAction(this);
		break;
	case BACK:
		pAct = new BackAction(this);
		break;
	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;
	case figure:
		pAct = new AddFigureAction(this);
		break;
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddCircleAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriangAction(this);
		break;
	case EXIT:
		///create ExitAction here
		break;
	case STATUS:
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
	
}

////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
CFigure* ApplicationManager::GetFigure(double x, double y) const
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->checkCoordinates(x, y))
			return FigList[i];
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
