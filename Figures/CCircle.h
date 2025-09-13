#pragma once
#include "CFigure.h"
class CCircle : public CFigure
{
public:
	Point point1;
	Point point2;
	CCircle() {};
	CCircle(Point, Point , GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool SearchPoint(int x, int y); //search a point inside circle
	virtual CCircle* deepcopy();
	int radius;
	void Save(ofstream& OutFile, int id);
	void Load(ifstream& Infile, int line,Output*);
};

