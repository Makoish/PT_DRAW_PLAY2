#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"
#include "..\Actions\SelectAction.h"

class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	ApplicationManager* pApp;
public:
	void IsSelected() const;
	bool checkCoordinates(double, double);
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif