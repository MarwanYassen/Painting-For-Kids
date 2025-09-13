#include "Cut.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp){}

void Cut::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL)
		pOut->PrintMessage("Figure cut to clipboard");
	else
		pOut->PrintMessage("No figure is selected");
}

void Cut::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig() != NULL)
	{
		CFigure* Fig = pManager->GetSelectedFig();
		if (pManager->GetSelectedCount() == 1)
		{
			Fig->IsCut = true;
			pManager->CopytoClipboard(Fig->deepcopy());
			Fig->ChngFillClr(GRAY);
			Fig->ChngDrawClr(GRAY);
		}
		else if (pManager->GetSelectedCount() > 1)
			pOut->PrintMessage("Select only one figure");
	}
}