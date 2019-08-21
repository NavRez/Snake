#pragma once
#include "SnakeList.h"
class SnakeGame
{
public:
	SnakeGame();
	~SnakeGame();
	void setboardmatrix();
	void placeSnake();
	void printmatrix();
	void makerandome();
	void reprint();
	void ClearScreen();
	void change(int&,int&);
	int divide(int, int);

protected:

	const int ROW = 24;
	const int COL = 24;
	int matrix[24][24];
	SnakeList* GameSnake;
	int ra_r;
	int ra_c;

};

