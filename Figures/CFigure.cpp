#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	IsCut = false;
	ChngBrdr = false;
	ChngFill = false;
}


void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}
void CFigure::setChngBrdr(bool b) {
	ChngBrdr = b;
}

bool CFigure::getChngBrdr() {
	return ChngBrdr;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
bool CFigure::getChngFill() {
	return ChngFill;
}
void CFigure::setChngFill(bool b) {
	ChngFill = b;
}

CFigure::Name CFigure::getFigName() {
	return FigName;
}

GfxInfo CFigure::GetGfxInfo() {
	return FigGfxInfo;
}

string CFigure::GetColorNameString(color Color) {
	if (Color == BLACK)  return "Black";
	else if (Color == BLUE)  return "Blue";
	else if (Color == GREEN) return "Green";
	else if (Color == ORANGE) return "Orange";
	else if (Color == RED) return "Red";
	else if (Color == YELLOW) return "Yellow";
	else { return "No Fill"; }
}
color CFigure::GetColorFromString(string Color) {
	if (Color == "Black     ")  return BLACK;
	else if (Color == "Blue      ")  return BLUE;
	else if (Color == "Green     ") return GREEN;
	else if (Color == "Orange    ") return ORANGE;
	else if (Color == "Red       ") return RED;
	else if (Color == "Yellow    ") return YELLOW;
	else return WHITE;
}