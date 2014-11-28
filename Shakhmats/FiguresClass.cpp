#include "FigureClass.h"
#include "BoardClass.h"

TFigure::TFigure(Board *board, FigureType figureType, uchar posX, uchar posY)
{
	this->constructSuccess = false;
	this->_figureType = figureType;
	if((posX > 7) | (posY > 7))
		throw "Выход за границы доски!";
	this->posX = posX;
	this->posY = posY;
	this->_board = board;
	this->_board -> AddFigure(this);
	this->constructSuccess = true;
}

TFigure::~TFigure()
{
	if(this->constructSuccess)
		this->_board->RemoveFigure(this);
}

FigureClass TFigure::GetClass()
{
	return this->_figureClass;
}

FigureType TFigure::GetType()
{
	return this->_figureType;
}

Situations TFigure::_Situation()
{
	return SITUATION_OK;
}

char * TFigure::Situation()
{
	Situations status = this->_Situation();
	switch(status)
	{
	case SITUATION_MAT:
		return "Мат";
		break;
	case SITUATION_PAT:
		return "Пат";
		break;
	case SITUATION_SHAH:
		return "Шах";
		break;
	case SITUATION_OK:
		return "Все ОК";
		break;
	}
	return "Неизвестная ситуация!";
}