#pragma once
#include "CFigure.h"
class CTriangle : public CFigure
{
public:
	Point vertex1;
	Point vertex2;
	Point vertex3;
	CTriangle() {}
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool SearchPoint(int x, int y); //search a point inside triangle
	int CalcArea(Point, Point, Point);
	virtual Point get1stpoint();
	virtual Point get2ndpoint();
	virtual Point get3rdpoint();
	virtual CTriangle* deepcopy();
	void Save(ofstream& OutFile,int id);
	void Load(ifstream& Infile, int line,Output*pout);
};

