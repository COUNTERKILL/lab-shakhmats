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
			throw "������ ��� ����! ������� �� ������!";
		this->_figureClass = KING;
	}
protected:
	Situations _Situation();
};