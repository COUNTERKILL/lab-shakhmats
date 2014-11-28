#pragma  once

#include "FigureClass.h"

class TKing: public TFigure
{
public:
	TKing(Board *board, FigureType figureType, uchar posX, uchar posY)
		:TFigure(board, figureType, posX, posY) 
	{
		this->_figureClass = KING;
	}
	Situations Situation();
};