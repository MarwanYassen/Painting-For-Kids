#include "SendBackAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"

SendBackAction::SendBackAction(ApplicationManager* pApp) :Action(pApp)
{}

void SendBackAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL) {
		pOut->PrintMessage("Figure is send back");
		shape = pManager->GetSelectedFig();
	}
	else
		pOut->PrintMessage("No figure is selected");
}

//Execute the action
void SendBackAction::Execute()
{
	ReadActionParameters();
	pManager->SendBack(shape);
}
