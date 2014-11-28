#include <iostream>
#include "BoardClass.h"
#include "KingClass.h"
#include "KnightClass.h"
#include "locale.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
	Board board;
	TKing wKing(&board, WHITE, 0, 5);
	TKing bKing(&board, BLACK, 0, 7);
	//TKing bKing1(&board, BLACK, 0, 1);
	TKnight bKnight(&board, BLACK, 5, 5);
	TKnight bKnight1(&board, BLACK, 5, 6);
	//TKnight bKnight3(&board, BLACK, 5, 6);
	TKnight bKnight2(&board, BLACK, 0, 0);
	TKnight wKnight(&board, WHITE, 1, 4);
	cout << wKing.Situation() << endl;
	board.Print();
	}
	catch(char *e)
	{
		cout<<"Ошибка: " << e << endl;
	}
	catch(...)
	{
		cout<<"Другая ошибка!" << endl;
	}
	return 0;
}