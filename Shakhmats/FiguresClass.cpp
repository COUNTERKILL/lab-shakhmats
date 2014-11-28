#include "FigureClass.h"

TFigure::TFigure(Board *board, FigureType figureType, uchar posX, uchar posY)
{
	this->constructSuccess = false;
	this->_figureType = figureType;
	this->_posX = posX;
	this->_posY = posY;
	this->_board = board;
	if(this->_board -> AddFigure(this))
	{
		throw "Unable to set figure to this point!";
	}
	this->constructSuccess = true;
}

TFigure::~TFigure()
{
	if(this->constructSuccess)
		this->_board->RemoveFigure(this);
}

Situations TFigure::Situation()
{

}