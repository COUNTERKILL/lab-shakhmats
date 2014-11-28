#include "BoardClass.h"
#include "TextColor.h"
#include <iostream>

using namespace std;

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

void Board::AddFigure(TFigure *figure)
{
	if(!this->PointIsFree(figure->posX, figure->posY))
		throw "Клетка уже занята!";
	this->_figures[figure->posX][figure->posY] = figure;
	this->_figuresCount++;
	return;
}

void Board::RemoveFigure(TFigure *figure)
{
	this->_figures[figure->posX][figure->posY] = 0;
	this->_figuresCount--;
	return;
}

bool Board::PointIsFree(uchar posX, uchar posY)
{
	return this->_figures[posX][posY] == 0;
}


void Board::CreateAnalysis(FigureType figureType, bool  pointsOnShah[8][8])
{
	for(size_t i = 0; i < 8; i++)
		for(size_t j = 0; j < 8; j++)
			if(this->_figures[i][j] != 0)
				if(this->_figures[i][j]->GetType() == figureType)
				{
					switch(this->_figures[i][j]->GetClass())
					{
					case KNIGHT:
						for(size_t k = 0; k < 8; k++)
						{
							// помечаем поля по вертикали и горизонтали от фигуры как "под шахом"
							pointsOnShah[k][j] = true;
							pointsOnShah[i][k] = true;
						}
						break;
					case KING:
						for(int IndIAboutKing = -1; IndIAboutKing < 2; IndIAboutKing++)
							for(int IndJAboutKing = -1; IndJAboutKing < 2; IndJAboutKing++)
								if((i+IndIAboutKing < 8) & (i+IndIAboutKing >= 0) & (j+IndJAboutKing < 8) & (j+IndJAboutKing >= 0))
								{
									pointsOnShah[i+IndIAboutKing][j+IndJAboutKing] = true;
								}
						break;
					}
				}
	return;
}

size_t Board::GetFiguresCount(FigureClass figureClass)
{
	size_t figuresCount = 0;
	for(size_t i = 0; i < 8; i++)
		for(size_t j = 0; j < 8; j++)
			if(this->_figures[i][j])
				if(this->_figures[i][j]->GetClass() == figureClass)
					figuresCount++;
	return figuresCount;
}

size_t Board::GetFiguresCount(FigureType figureType)
{
	size_t figuresCount = 0;
	for(size_t i = 0; i < 8; i++)
		for(size_t j = 0; j < 8; j++)
			if(this->_figures[i][j])
				if(this->_figures[i][j]->GetType() == figureType)
					figuresCount++;
	return figuresCount;
}

size_t Board::GetFiguresCount(FigureClass figureClass, FigureType figureType)
{
	size_t figuresCount = 0;
	for(size_t i = 0; i < 8; i++)
		for(size_t j = 0; j < 8; j++)
			if(this->_figures[i][j])
				if((this->_figures[i][j]->GetType() == figureType) & (this->_figures[i][j]->GetClass() == figureClass))
					figuresCount++;
	return figuresCount;
}

void Board::Print()
{
	for(size_t i = 0; i < 8; i++)
	{
		for(size_t j = 0; j < 8; j++)
		{
			SetColor(Green, Green);
			if(this->_figures[i][j])
			{
				switch(_figures[i][j]->GetType())
				{
				case BLACK:
					SetColor(Black, Green);
					break;
				case WHITE:
					SetColor(White, Green);
					break;
				}
				switch(this->_figures[i][j]->GetClass())
				{
				case KING:
					cout << "К";
					break;
				case KNIGHT:
					cout << "Л";
					break;
				}
			}
			else
				cout << "*";
		}
		cout << endl;
	}
	SetColor(White, Black);
}