#include "Paste.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"

Paste::Paste(ApplicationManager* pApp): Action(pApp){}

void Paste::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

		switch (pManager->GetFigName()) {
		case CFigure::RECTANGLE:
			pOut->PrintMessage("Click the new top-left corner of the rectangle");
			break;

		case CFigure::SQUARE:
			pOut->PrintMessage("Click the new center of the square");
			break;

		case CFigure::CIRCLE:
			pOut->PrintMessage("Click the new center of the circle");
			break;

		case CFigure::TRIANGLE:
			pOut->PrintMessage("Click a new corner of the triangle");
			break;

		case CFigure::HEXAGON:
			pOut->PrintMessage("Click the new center of the hexagon");
			break;
		}
		pIn->GetPointClicked(P.x, P.y);
		pOut->ClearStatusBar();
	}
	

void Paste::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetClipboard() != NULL) {
		GfxInfo i = pManager->GetClipboard()->GetGfxInfo();
		if (pManager->GetClipboard()->IsCut)
		{
			pManager->GetClipboard()->IsCut = false;
	    }
			ReadActionParameters();
			switch (pManager->GetFigName()) {

			case CFigure::CIRCLE:
			{
				CCircle* Cptr = dynamic_cast<CCircle*>(pManager->GetClipboard());
				Point p2; p2.x = P.x + Cptr->radius; p2.y = P.y;
				Cptr = new CCircle(P, p2, i);
				pManager->AddFigure(Cptr);
				break;
			}
			case CFigure::RECTANGLE:
			{
				CRectangle* Rptr = dynamic_cast<CRectangle*>(pManager->GetClipboard());
				Point p2; p2.x = P.x + Rptr->dx; p2.y = P.y + Rptr->dy;
				Rptr = new CRectangle(P, p2, i);
				pManager->AddFigure(Rptr);
				break;
			}
			case CFigure::SQUARE:
			{
				CSquare* Sptr = dynamic_cast<CSquare*>(pManager->GetClipboard());
				int L = 150;
				Sptr = new CSquare(P, L, i);
				pManager->AddFigure(Sptr);
				break;
			}
			case CFigure::HEXAGON:
			{
				CHexagon* Hptr = dynamic_cast<CHexagon*>(pManager->GetClipboard());
				int L = 150;
				Hptr = new CHexagon(P, L, i);
				pManager->AddFigure(Hptr);
				break;
			}
			case CFigure::TRIANGLE:
			{
				CTriangle* Tptr = dynamic_cast<CTriangle*>(pManager->GetClipboard());
				Point Pi1 = Tptr->get1stpoint();
				int dx = P.x - Pi1.x; int dy = P.y - Pi1.y;
				Point p2; p2.x = Tptr->get2ndpoint().x + dx; p2.y = Tptr->get2ndpoint().y + dy;
				Point p3; p3.x = Tptr->get3rdpoint().x + dx; p3.y = Tptr->get3rdpoint().y + dy;
				Tptr = new CTriangle(P, p2, p3, i);
				pManager->AddFigure(Tptr);
				break;
			}
			}
	}
	else
		pOut->PrintMessage("No figure is copied or cut");
	CFigure** FigArr = pManager->GetFigList();
	for (int i = 0; i < 200; i++)
		if (FigArr[i] != NULL && FigArr[i]->IsCut)
		{
			pManager->DeleteFigure(FigArr[i]);
			break;
		}
}

