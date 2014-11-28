#pragma  once

#include "FigureClass.h"
#include "BoardClass.h"

class TKing: public TFigure
{
public:
	TKing(Board *board, FigureType figureType, uchar posX, uchar posY)
		:TFigure(board, figureType, posX, posY) 
	{
		if(board->GetFiguresCount(KING, figureType))
			throw "Король уже есть! Другому не бывать!";
		this->_figureClass = KING;
	}
protected:
	Situations _Situation();
};