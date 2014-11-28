#include "BoardClass.h"

Board::Board()
{
	this->_figuresCount = 0;
	for(size_t i = 0; i < 8; i++)
		for(size_t j = 0; j < 8; j++)
			this->_figures[i][j] = 0;
};

Board::~Board()
{

}

int Board::AddFigure(TFigure *figure)
{
	if(this->_figures[figure->_posX][figure->_posY])
		return -1;
	this->_figures[figure->_posX][figure->_posY] = figure;
	return 0;
}

void Board::RemoveFigure(TFigure *figure)
{
	this->_figures[figure->_posX][figure->_posY] = 0;
}