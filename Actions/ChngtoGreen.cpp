#include "ChngtoGreen.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChngtoGreen::ChngtoGreen(ApplicationManager* pApp) : Action(pApp) {}

void ChngtoGreen::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL)
		pOut->PrintMessage("No figure is selected");
	else
		pOut->PrintMessage("Color changed to green");
}

void ChngtoGreen::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig()->getChngBrdr())
	{
		pManager->GetSelectedFig()->ChngDrawClr(GREEN);
		pManager->GetSelectedFig()->setChngBrdr(false);
	}
	else if (pManager->GetSelectedFig()->getChngFill())
	{
		pManager->GetSelectedFig()->ChngFillClr(GREEN);
		pManager->GetSelectedFig()->setChngFill(false);
	}
	else
		pOut->PrintMessage("Please press change fill or change border first");
}