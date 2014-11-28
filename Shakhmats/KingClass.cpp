#include "KingClass.h"

/*
	TGing::Situation()
	������� ������������, ��� ���� ���� ��������� ����� (�.�. ������ ���� ��������� � ������������� ������)
*/
Situations TKing::_Situation()
{
	bool pointsOnShah[8][8] = {0};
	// ���� �������� ������ 2 ������, �� ���
	if((this->_board->GetFiguresCount(BLACK) == 1) & (this->_board->GetFiguresCount(WHITE) == 1))
		return SITUATION_PAT;
	// ������ ����� ����� ������������ ���� ������
	switch(this->_figureType)
	{
	case WHITE: 
		this->_board->CreateAnalysis(BLACK, pointsOnShah);
		break;
	case BLACK: 
		this->_board->CreateAnalysis(WHITE, pointsOnShah);
		break;
	}
	if(!pointsOnShah[this->posX][this->posY])
		return SITUATION_OK;
	for(int IndIAboutKing = -1; IndIAboutKing < 2; IndIAboutKing++)
		for(int IndJAboutKing = -1; IndJAboutKing < 2; IndJAboutKing = IndJAboutKing++)
		{
			if((IndJAboutKing == IndIAboutKing) & (IndIAboutKing == 0)) continue;
			if((this->posX+IndIAboutKing < 8) 
				& (this->posX+IndIAboutKing >= 0) 
				& (this->posY+IndJAboutKing < 8) 
				& (this->posY+IndJAboutKing >= 0))
			{
				// ���� ���� ��������� ���� ������ ������, �� �� ���
				if((!pointsOnShah[this->posX+IndIAboutKing][this->posY+IndJAboutKing]) 
					& this->_board->PointIsFree(this->posX+IndIAboutKing, this->posY+IndJAboutKing))
				{
					return SITUATION_SHAH;
				}
			}
		}
	return SITUATION_MAT;
}