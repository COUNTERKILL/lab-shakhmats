#pragma  once

#include "FigureClass.h"

class TKnight: public TFigure
{
public:
	TKnight(Board *board, FigureType figureType, uchar posX, uchar posY)
		:TFigure(board, figureType, posX, posY) 
	{
		this->_figureClass = KNIGHT;
	}
protected:
	Situations _Situation();
};