#include "AddtriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddTriangAction::AddTriangAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New triangle : Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y >= 0 && P1.y <= UI.ToolBarHeight || P1.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("Out of boundries, Click another point");
		pIn->GetPointClicked(P1.x, P1.y);

	}
	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	while (P2.y >= 0 && P2.y <= UI.ToolBarHeight || P2.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("Out of boundries, Click another point");
		pIn->GetPointClicked(P2.x, P2.y);

	}
	//Read 3nd corner and store in point P3
	pOut->PrintMessage("New Rectangle: Click at third corner");
	pIn->GetPointClicked(P3.x, P3.y);

	while (P3.y >= 0 && P3.y <= UI.ToolBarHeight || P3.y >= UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("Out of boundries, Click another point");
		pIn->GetPointClicked(P3.x, P3.y);

	}

	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CTriangle* R = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}