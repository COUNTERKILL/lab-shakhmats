#pragma once

#include "FigureClass.h"

class Board
{
public:
	Board();
	~Board();
	int AddFigure(TFigure *figure);
	void RemoveFigure(TFigure *figure);
private:
	TFigure* _figures[8][8];
	size_t _figuresCount;

	bool PointIsFree(uchar posX, uchar posY);
};