#include "BringFrontAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

BringFrontAction::BringFrontAction(ApplicationManager* pApp) :Action(pApp)
{}

void BringFrontAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL) {
		pOut->PrintMessage("Figure is brought to front");
		shape = pManager->GetSelectedFig();
	}
	else
		pOut->PrintMessage("No figure is selected");
}

//Execute the action
void BringFrontAction::Execute()
{
	ReadActionParameters();
	pManager->BringFront(shape);
}