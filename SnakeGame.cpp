#include "SnakeGame.h"
#include "SnakeList.h"


SnakeGame::SnakeGame()
{

	GameSnake = new SnakeList(7, 7, nullptr, nullptr);
	GameSnake->exist = false;

}


SnakeGame::~SnakeGame()
{
}



void SnakeGame::setboardmatrix() {

	for (int i = 0; i <ROW; i++) {

		for (int j = 0; j < COL; j++) {

			matrix[i][j] = -1;
		}
	}

	placeSnake();
	if (GameSnake->exist == false) {
		makerandome();
	}
	else {

		matrix[ra_r][ra_c] = 0;

	}

}

void SnakeGame::placeSnake() {

	SnakeList* temp = GameSnake;

	while (temp != nullptr) {

		int trow = temp->getrow();
		int tcol = temp->getcol();

		matrix[trow][tcol] = 1;

		if (temp->getprev() == nullptr)
		{
			matrix[trow][tcol] = 2;
		}


		temp = temp->getnext();



	}

	delete temp;
}

void SnakeGame::printmatrix() {

	setboardmatrix();

	cout << "\n";
	for (int i = 0; i < ROW; i++) {
		cout << "";


		for (int j = 0; j < COL; j++) {


			if (matrix[i][j] == -1) {

				cout << "   ";

			}
			else if (matrix[i][j] == 2) {

				cout << " O ";
			}
			else if (matrix[i][j] == 1) {

				cout << " o ";
			}
			else if (matrix[ra_r][ra_c] == 0)
			{
				cout << " 0 ";
			}

		}


		cout << "\n";

	}
	cout << "\n";


}

void SnakeGame::makerandome() {

	int randcol = rand() % COL;
	int randrow = rand() % ROW;



	while (matrix[randrow][randcol] != -1) {
		int randcol = rand() % COL;
		int randrow = rand() % ROW;
	}
	GameSnake->exist = true;
	ra_r = randrow;
	ra_c = randcol;
	matrix[randrow][randcol] = 0;

}


void SnakeGame::reprint() {


	printmatrix();
	cout << "Welcome to the Snake game made for C++, Press the arrow keys to move the snake around\nIf you connect with a 0, you will grow \nBut don't hit yourself or the wall or else you'll lose\nPress the arrow keys when you're ready";
	int c = 0;
	int d = c;
	int count = 1;
	bool truth = false;
	switch (c = _getch()) {

	default:

		try {
			while (count > 0) {


				if (count == 1) {


					if (GetAsyncKeyState(VK_UP)) {

						GameSnake->setcheck(VK_UP);
					}
					else if (GetAsyncKeyState(VK_DOWN)) {

						GameSnake->setcheck(VK_DOWN);
					}
					else if (GetAsyncKeyState(VK_LEFT)) {

						GameSnake->setcheck(VK_LEFT);
					}
					else if (GetAsyncKeyState(VK_RIGHT)) {

						GameSnake->setcheck(VK_RIGHT);
					}


				}

				ClearScreen();
				printmatrix();

				if ((GetAsyncKeyState(VK_UP) && truth == false && GameSnake->getcheck() == VK_UP) || (d == VK_UP)) {
					truth = true;
					d = VK_UP;

					while (true)
					{
						if (GameSnake->getrow() - 1 < 0 || matrix[GameSnake->getrow() - 1][GameSnake->getcol()] == 1) {
							c = divide(c, 0);
							break;

						}
						else if (matrix[GameSnake->getrow() - 1][GameSnake->getcol()] == 0) {

							GameSnake->addHead(GameSnake, ra_r, ra_c);
							count++;
						}
						else
						{
							GameSnake->move(GameSnake, GameSnake->getrow() - 1, GameSnake->getcol());

							if (GetAsyncKeyState(VK_DOWN) || d == VK_DOWN) {
								d = VK_UP;
								truth = true;

								GameSnake->setcheck(VK_UP);

								if (count > 0) {

									count = count;
								}

								break;
							}

							if (GetAsyncKeyState(VK_LEFT) || d == VK_LEFT) {
								d = VK_LEFT;
								truth = false;
								GameSnake->setcheck(VK_LEFT);
								if (count > 0) {

									count = count;
								}

								break;
							}
							else if (GetAsyncKeyState(VK_RIGHT) || d == VK_RIGHT) {
								d = VK_RIGHT;
								truth = false;
								GameSnake->setcheck(VK_RIGHT);
								if (count > 0) {

									count = count;
								}

								break;
							}
							else
							{
								;
							}



						}
						ClearScreen();
						printmatrix();
						Sleep(32);
					}

				}
				else if ((GetAsyncKeyState(VK_DOWN) && truth == false && GameSnake->getcheck() == VK_DOWN) || d == VK_DOWN)
				{
					truth = true;
					d = VK_DOWN;
					while (1) {
						if (GameSnake->getrow() + 1 > ROW - 1 || matrix[GameSnake->getrow() + 1][GameSnake->getcol()] == 1) {
							c = divide(c, 0);
							break;
						}
						else if (matrix[GameSnake->getrow() + 1][GameSnake->getcol()] == 0) {

							GameSnake->addHead(GameSnake, ra_r, ra_c);
							count++;
						}
						else
						{
							GameSnake->move(GameSnake, GameSnake->getrow() + 1, GameSnake->getcol());

							if (GetAsyncKeyState(VK_UP) || d == VK_UP) {
								d = VK_DOWN;
								truth = true;
								GameSnake->setcheck(VK_DOWN);
								if (count > 0) {

									count = count;
								}

								break;
							}

							if (GetAsyncKeyState(VK_LEFT) || d == VK_LEFT) {
								d = VK_LEFT;
								truth = false;
								GameSnake->setcheck(VK_LEFT);
								if (count > 0) {

									count = count;
								}

								break;
							}
							else if (GetAsyncKeyState(VK_RIGHT) || d == VK_RIGHT) {

								d = VK_RIGHT;
								truth = false;
								GameSnake->setcheck(VK_RIGHT);
								if (count > 0) {

									count = count;
								}

								break;
							}
							else
							{
								;
							}



						}

						ClearScreen();
						printmatrix();
						Sleep(32);
					}
				}
				else if ((GetAsyncKeyState(VK_LEFT) && truth == false) || d == VK_LEFT) {
					truth = true;
					d = VK_LEFT;
					while (1) {
						if (GameSnake->getcol() - 1 < 0 || matrix[GameSnake->getrow()][GameSnake->getcol() - 1] == 1) {

							c = divide(c, 0);
						}
						else if (matrix[GameSnake->getrow()][GameSnake->getcol() - 1] == 0) {

							GameSnake->addHead(GameSnake, ra_r, ra_c);
							count++;
						}
						else {
							GameSnake->move(GameSnake, GameSnake->getrow(), GameSnake->getcol() - 1);

							if (GetAsyncKeyState(VK_RIGHT) || d == VK_RIGHT) {
								d = VK_LEFT;
								truth = true;
								GameSnake->setcheck(VK_LEFT);
								if (count > 0) {

									count = count;
								}

								break;
							}

							if (GetAsyncKeyState(VK_UP) || d == VK_UP) {
								d = VK_UP;
								truth = false;
								GameSnake->setcheck(VK_UP);
								if (count > 0) {

									count = count;
								}
								break;
							}
							else if (GetAsyncKeyState(VK_DOWN) || d == VK_DOWN) {
								d = VK_DOWN;
								truth = false;
								GameSnake->setcheck(VK_DOWN);
								if (count > 0) {

									count = count;
								}
								break;
							}
							else
							{
								;
							}



						}
						ClearScreen();
						printmatrix();
						Sleep(32);


					}
				}
				else if ((GetAsyncKeyState(VK_RIGHT) && truth == false) || d == VK_RIGHT)
				{
					truth = true;
					d = VK_RIGHT;
					while (1) {
						if (GameSnake->getcol() + 1 > ROW - 1 || matrix[GameSnake->getrow()][GameSnake->getcol() + 1] == 1) {

							c = divide(c, 0);
						}
						else if (matrix[GameSnake->getrow()][GameSnake->getcol() + 1] == 0) {

							GameSnake->addHead(GameSnake, ra_r, ra_c);
							count++;
						}
						else {
							GameSnake->move(GameSnake, GameSnake->getrow(), GameSnake->getcol() + 1);

							if (GetAsyncKeyState(VK_LEFT) || d == VK_LEFT) {
								d = VK_RIGHT;
								truth = true;
								GameSnake->setcheck(VK_RIGHT);
								if (count > 0) {

									count = count;
								}

								break;
							}

							if (GetAsyncKeyState(VK_UP) || d == VK_UP) {
								d = VK_UP;
								truth = false;
								GameSnake->setcheck(VK_UP);
								if (count > 0) {

									count = count;
								}
								break;
							}
							else if (GetAsyncKeyState(VK_DOWN) || d == VK_DOWN) {
								d = VK_DOWN;
								GameSnake->setcheck(VK_DOWN);
								truth = false;
								if (count > 0) {

									count = count;
								}
								break;
							}




						}
						ClearScreen();
						printmatrix();
						Sleep(32);
					}
				}





				count++;
				ClearScreen();
				Sleep(32);
			}
		}
		catch (const char* word) {

			cout << word << endl;

		}

	}



}


void SnakeGame::ClearScreen()
{
	DWORD n;
	DWORD size;
	COORD coord = { 0 };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
	SetConsoleCursorPosition(h, coord);
}

void SnakeGame::change(int& tochange, int& newval) {

	tochange = newval;

}

int SnakeGame::divide(int a, int b) {

	if (b == 0) {

		throw "Game Over, Snake cannot proceed this path !";
	}

	return (a / b);

}