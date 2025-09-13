#pragma once
#include "CFigure.h"
class CHexagon : public CFigure
{
public:
	Point Center;
	int L;
	CHexagon() {}
	CHexagon(Point, int, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool SearchPoint(int x, int y); //search a point inside hexagon
	virtual CHexagon* deepcopy();
	void Save(ofstream& OutFile,int id);
	void Load(ifstream& Infile, int line,Output*);
};

