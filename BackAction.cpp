#include "Action.h"
#include "..\ApplicationManager.h"
#include "BackAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BackAction::BackAction(ApplicationManager* pApp) :Action(pApp)
{
}

void BackAction::ReadActionParameters()
{
	Output*pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Back to Draw Mod");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();

}

void BackAction::Execute()
{
	ReadActionParameters();

}

