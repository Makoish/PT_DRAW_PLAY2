#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{

}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on any figure");
	pIn->GetPointClicked(P1.x, P1.y);
	Fig = pApp->GetFigure(P1.x, P1.y);
}


void SelectAction::Execute()
{
	ReadActionParameters();

}
