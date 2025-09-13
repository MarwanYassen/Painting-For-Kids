#include "CSquare.h"
#include <iostream>
#include <fstream> // For file handling
#include <iomanip> // For setw()
#include "../ApplicationManager.h"
CSquare::CSquare(Point P1, int l , GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	L = l;
	FigName = SQUARE;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSqu(Center, L , FigGfxInfo, Selected);
}

bool CSquare::SearchPoint(int x, int y)
{
	if (x > Center.x - L && x< Center.x + L && y>Center.y - L && y < Center.y + L)
		return true;
	else
		return false;
}
CSquare* CSquare::deepcopy() {

	return new CSquare(*this);
}
void CSquare::Save(ofstream& outFile, int id) {
	string fill = (FigGfxInfo.isFilled == true) ? GetColorNameString(FigGfxInfo.FillClr) : "No Fill";
	outFile << left << setw(10) << "Square" << setw(5) << id << setw(10) <<
		Center.x << setw(10) << Center.y <<
		setw(10) << L <<
		setw(10) << GetColorNameString(FigGfxInfo.DrawClr) << setw(10) << fill << endl;
}
void CSquare::Load(ifstream& infile, int lineNum,Output*pOut) {
	infile.seekg(0, ios::beg);//to start reading from the begining
	for (int i = 0; i < lineNum; i++)
		infile.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');//skip to line
	string line;
	getline(infile, line);
	Center.x = stoi(line.substr(15, 25));
	Center.y = stoi(line.substr(25, 35));
	L = stoi(line.substr(35, 45));
	string color = line.substr(45, 65);
	FigGfxInfo.DrawClr = GetColorFromString(color.substr(0, 10));
	FigGfxInfo.FillClr = GetColorFromString(color.substr(10, 20));
	if (FigGfxInfo.FillClr == WHITE)
		FigGfxInfo.isFilled = false;
	Draw(pOut);
}
