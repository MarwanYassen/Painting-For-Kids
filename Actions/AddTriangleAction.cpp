#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp):Action(pApp){}

void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first point");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second point");
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third point");
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	CTriangle* R = new CTriangle(P1, P2,P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(R);
}
