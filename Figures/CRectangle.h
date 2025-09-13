#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle() {}
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool SearchPoint(int x, int y); //search a point inside rectangle
	virtual CRectangle* deepcopy();
	int dx;
	int dy;
	int Xmax;
	int Xmin;
	int Ymax;
	int Ymin;
	void Save(ofstream& OutFile,int id);
	void Load(ifstream& Infile, int line,Output*);
};

#endif