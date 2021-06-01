#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <cmath>
AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click the second point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	
	radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	
	while (radius>=P1.y-UI.StatusBarHeight || radius+P1.y>=UI.height-UI.StatusBarHeight)
	{
		pOut->PrintMessage("Out of boundries, Click on Center");

		//Read 1st corner and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);
		pOut->PrintMessage("Out of boundries, Click second point");

		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);

		radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	}

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle* R = new CCircle(P1, radius, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
