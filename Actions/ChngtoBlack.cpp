#include "ChngtoBlack.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChngtoBlack::ChngtoBlack(ApplicationManager* pApp) : Action(pApp){}

void ChngtoBlack::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL)
		pOut->PrintMessage("No figure is selected");
	else
		pOut->PrintMessage("Color changed to black");
}

void ChngtoBlack::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig()->getChngBrdr())
	{
		pManager->GetSelectedFig()->ChngDrawClr(BLACK);
		pManager->GetSelectedFig()->setChngBrdr(false);
	}
	else if (pManager->GetSelectedFig()->getChngFill())
	{
		pManager->GetSelectedFig()->ChngFillClr(BLACK);
		pManager->GetSelectedFig()->setChngFill(false);
	}
	else
		pOut->PrintMessage("Please press change fill or change border first");
}