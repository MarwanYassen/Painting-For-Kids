#include "ChngtoYellow.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Actions\SelectAction.h"

ChngtoYellow::ChngtoYellow(ApplicationManager* pApp) : Action(pApp) {}

void ChngtoYellow::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL)
		pOut->PrintMessage("No figure is selected");
	else
		pOut->PrintMessage("Color changed to yellow");
}

void ChngtoYellow::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig()->getChngBrdr())
	{
		pManager->GetSelectedFig()->ChngDrawClr(YELLOW);
		pManager->GetSelectedFig()->setChngBrdr(false);
	}
	else if (pManager->GetSelectedFig()->getChngFill())
	{
		pManager->GetSelectedFig()->ChngFillClr(YELLOW);
		pManager->GetSelectedFig()->setChngFill(false);
	}
	else
		pOut->PrintMessage("Please press change fill or change border first");
}