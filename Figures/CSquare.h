#pragma once
#include "CFigure.h"
class CSquare : public CFigure
{
public:
	Point Center;
	int L;
	CSquare() {}
	CSquare(Point, int, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool SearchPoint(int x, int y); //search a point inside square
	virtual CSquare* deepcopy();
	void Save(ofstream& OutFile,int id);
	void Load(ifstream& Infile, int line, Output*);
};

