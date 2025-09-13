#include "SelectAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>


SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select: Please click a point");

	pIn->GetPointClicked(P.x, P.y);



	pOut->ClearStatusBar();

}

void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* R = pManager->GetFigure(P.x, P.y);
	if (R != NULL) {
		if (R->IsSelected()) {
			R->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		}
		else {
			R->SetSelected(true);
			pManager->SetSelectedFig(R);
		}
	}
	else {
		pManager->DeselectAll();
	}
	pOut->PrintMessage(pManager->PrintInfo());
}


