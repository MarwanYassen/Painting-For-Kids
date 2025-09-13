#include "ChngFillClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChngFillClr::ChngFillClr(ApplicationManager* pApp) : Action(pApp) {}

void ChngFillClr::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Pick new fill color");
}

void ChngFillClr::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig()->IsCut == false) //keep cut figure greyed out
	{
		if (pManager->GetSelectedCount() == 1)
		{
			ReadActionParameters();
			pManager->Selectedarr[0]->setChngFill(true);
		}
		else if (pManager->GetSelectedCount() > 1)
			pOut->PrintMessage("Select only one figure");
		else
			pOut->PrintMessage("No figure is selected");
	}
	else
		pOut->PrintMessage("Figure has been cut");
}