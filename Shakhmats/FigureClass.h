#pragma once

#include "FiguresEnums.h"
#include "BoardClass.h"

typedef unsigned char uchar;

class TFigure
{
public:
	uchar _posX, _posY;

	TFigure(Board *board, FigureType figureType, uchar posX, uchar posY);
	virtual ~TFigure();
	virtual Situations Situation();
protected:
	FigureClass _figureClass;
private:
	Board *_board;
	FigureType _figureType;
	bool constructSuccess;
};