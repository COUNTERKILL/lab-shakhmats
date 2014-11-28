#pragma once

#include "FigureClass.h"
#include <iostream>

class Board
{
public:
	Board();
	~Board();
	void AddFigure(TFigure *figure);
	void RemoveFigure(TFigure *figure);
	void CreateAnalysis(FigureType figureType, bool  pointsOnShah[8][8]);

	size_t GetFiguresCount(FigureClass figureClass);
	size_t GetFiguresCount(FigureType figureType);
	size_t GetFiguresCount(FigureClass figureClass, FigureType figureType);
	bool PointIsFree(uchar posX, uchar posY);

	void Print();

	size_t _figuresCount;
private:
	TFigure* _figures[8][8];
};