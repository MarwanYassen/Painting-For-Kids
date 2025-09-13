#include "ChngtoOrange.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Actions\SelectAction.h"

ChngtoOrange::ChngtoOrange(ApplicationManager* pApp) : Action(pApp) {}

void ChngtoOrange::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL)
		pOut->PrintMessage("No figure is selected");
	else
		pOut->PrintMessage("Color changed to orange");
}

void ChngtoOrange::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig()->getChngBrdr())
	{
		pManager->GetSelectedFig()->ChngDrawClr(ORANGE);
		pManager->GetSelectedFig()->setChngBrdr(false);
	}
	else if (pManager->GetSelectedFig()->getChngFill())
	{
		pManager->GetSelectedFig()->ChngFillClr(ORANGE);
		pManager->GetSelectedFig()->setChngFill(false);
	}
	else
		pOut->PrintMessage("Please press change fill or change border first");
}