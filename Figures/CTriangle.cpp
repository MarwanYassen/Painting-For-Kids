#include "CTriangle.h"
#include "../ApplicationManager.h"
#include <iostream>
#include <fstream> // For file handling
#include <iomanip> // For setw()
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	vertex1 = P1;
	vertex2 = P2;
	vertex3 = P3;
	FigName = TRIANGLE;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(vertex1, vertex2, vertex3, FigGfxInfo, Selected);
}
int CTriangle::CalcArea(Point P1, Point P2, Point P3)
{
	return 0.5 * std::abs((P1.x - P3.x) * (P2.y - P1.y) - (P1.x - P2.x) * (P3.y - P1.y));
}

bool CTriangle::SearchPoint(int x, int y)
{
	Point P;
	P.x = x;
	P.y = y;

	//using barycentric coordinate method 
	if (CalcArea(P, vertex2, vertex3) + CalcArea(P, vertex1, vertex3) + CalcArea(P, vertex1, vertex2) <= CalcArea(vertex1, vertex2, vertex3)) {
		return true;
	}
	else
		return false;
}
Point CTriangle::get1stpoint() {
	return vertex1;
}

Point CTriangle::get2ndpoint() {
	return vertex2;
}

Point CTriangle::get3rdpoint() {
	return vertex3;
}

CTriangle* CTriangle::deepcopy() {

	return new CTriangle(*this);
}
void CTriangle::Save(ofstream& outFile, int id) {
	string fill = (FigGfxInfo.isFilled == true) ? GetColorNameString(FigGfxInfo.FillClr) : "No Fill";
	outFile << left << setw(10) << "Triangle" << setw(5) << id << setw(10) <<
		vertex1.x << setw(10) << vertex1.y << setw(10) 
		<< vertex2.x<<setw(10)<<vertex2.y<< setw(10)<<
		vertex3.x<<setw(10)<<vertex3.y <<
		setw(10) << GetColorNameString(FigGfxInfo.DrawClr) << setw(10) << fill << endl;
}
void CTriangle::Load(ifstream& Infile, int lineNum,Output*pOut){
	Infile.seekg(0, ios::beg);//to start reading from the begining
	for (int i = 0; i<lineNum; i++)
		Infile.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');//skip to line
	string line;
	getline(Infile, line);
	vertex1.x = stoi(line.substr(15, 25));
	vertex1.y = stoi(line.substr(25, 35));
	vertex2.x = stoi(line.substr(35, 45));
	vertex2.y = stoi(line.substr(45, 55));
	vertex3.x = stoi(line.substr(55, 65));
	vertex3.y = stoi(line.substr(65, 75));
	string color = line.substr(75,95);
	FigGfxInfo.DrawClr = GetColorFromString(color.substr(0,10));
	FigGfxInfo.FillClr = GetColorFromString(color.substr(10,20));
	if (FigGfxInfo.FillClr == WHITE)
		FigGfxInfo.isFilled = false;
	Draw(pOut);
}

