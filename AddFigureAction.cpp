#include "AddFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Output* pOut;
AddFigureAction::AddFigureAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Add figure action");
	pOut->ClearToolBar();
	pOut->CreateFigureToolBar();
	

}

//Execute the action
void AddFigureAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	

	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures

}
