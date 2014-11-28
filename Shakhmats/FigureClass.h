#pragma once

class Board;
#include "FiguresEnums.h"

typedef unsigned char uchar;

class TFigure
{
public:
	uchar posX, posY;

	TFigure(Board *board, FigureType figureType, uchar posX, uchar posY);
	virtual ~TFigure();
	virtual char* Situation();
	FigureClass GetClass();
	FigureType GetType();
protected:
	virtual Situations _Situation();
	FigureClass _figureClass; // класс: (король, ладья)
	FigureType _figureType; // тип: (белые, черные)
	Board *_board;
private:
	bool constructSuccess;
};