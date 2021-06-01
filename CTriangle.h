#pragma once
#include "CFigure.h"
#include "..\Actions\SelectAction.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	ApplicationManager* pApp;
public:
	void IsSelected() const;
	virtual bool checkCoordinates(double, double);
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};


