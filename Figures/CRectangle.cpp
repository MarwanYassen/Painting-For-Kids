#include "CRectangle.h"
#include <iostream>
#include <fstream> // For file handling
#include <iomanip> // For setw()
#include "../ApplicationManager.h"
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	FigName = RECTANGLE;
	dx = abs(Corner1.x - Corner2.x); dy = abs(Corner1.y - Corner2.y);
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::SearchPoint(int x, int y)
{
	if (Corner1.x > Corner2.x) {
		Xmax = Corner1.x;
		Xmin = Corner2.x;
	}
	else if(Corner1.x < Corner2.x) {
		Xmax = Corner2.x;
		Xmin = Corner1.x;
	}
	if (Corner1.y > Corner2.y) {
		Ymax = Corner1.y;
		Ymin = Corner2.y;
	}
	else if (Corner1.y < Corner2.y) {
		Ymax = Corner2.y;
		Ymin = Corner1.y;
	}
	if (x <= Xmax && x >= Xmin && y <= Ymax && y >= Ymin) {
		return true;
	}
	else {
		return false;
	}
}

void CRectangle::Save(ofstream& outFile,int id) {
	string fill = (FigGfxInfo.isFilled == true) ? GetColorNameString(FigGfxInfo.FillClr) : "No Fill";
	outFile << left << setw(10) << "Rectangle" << setw(5) << id << setw(10) 
		<< Corner1.x<< setw(10) << Corner1.y<<setw(10) <<
		Corner2.x << setw(10) << Corner2.y << 
		setw(10) << GetColorNameString(FigGfxInfo.DrawClr) << setw(10) << fill << endl;
}
CRectangle* CRectangle::deepcopy() {

	return new CRectangle(*this);
}
void CRectangle::Load(ifstream& infile, int lineNum,Output*pOut) {
	infile.seekg(0, ios::beg);//to start reading from the begining
	for (int i = 0; i < lineNum; i++)
		infile.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');//skip to line
	string line;
	getline(infile, line);
	Corner1.x = stoi(line.substr(15, 25));
	Corner1.y = stoi(line.substr(25, 35));
	Corner2.x = stoi(line.substr(35, 45));
	Corner2.y = stoi(line.substr(45, 55));
	string color = line.substr(55, 75);
	FigGfxInfo.DrawClr = GetColorFromString(color.substr(0, 10));
	FigGfxInfo.FillClr = GetColorFromString(color.substr(10, 20));
	if (FigGfxInfo.FillClr == WHITE)
		FigGfxInfo.isFilled = false;
	Draw(pOut);
}
