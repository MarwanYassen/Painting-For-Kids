#include "ClearAll.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAll::ClearAll(ApplicationManager* pApp):Action(pApp)
{
	P = new Point;
}

void ClearAll::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You are going to clear all figures, Click anywhere to confirm action");

	pIn->GetPointClicked(P->x, P->y);

	pOut->ClearStatusBar();
}

void ClearAll::Execute()
{
	ReadActionParameters();

	if (P != NULL) {
		pManager->ClearFigures();
	}
}

ClearAll::~ClearAll()
{
	delete P;
}
