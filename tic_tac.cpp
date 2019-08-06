/*
Игра "Крестики - Нолики"
​
пустая клетка - "0"
крестик - "1"
нолик - "-1"
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int SIZE = 3;
const int TOE = 1; //Крестик
const int TAC = -1; //Нолик

int gameBoard[SIZE][SIZE];

void InitializationGameBoard(); //заполнение нулями поле

bool CheckCoordinates(int x, int y); //проверка координат свободна ли клетка

bool CheckGameBooard(int x, int y); //проверка координат входят ли они в область 3х3

void StepGamer(int gamer); // ввод Х и 0

bool CheckWin(int win); //проверкан а победу

void ShowGameBoard(); // заполнение поля символами " "; " Х "; " 0 "

void StepAi(int gamer);

void StepSuperAi(int gamer, int step);


int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(NULL));
	int choise;

	//Вывести на экран приветствие

	cout << "\t\t\t\t\<<TIC-TAC-TOE>>" << endl;
	cout << endl;
	cout << "Приветствуем Вас в игре <<Крестики-нолики>> !!" << endl;
	cout << endl;
	cout << "В игре есть 2 режима: 1х1 с компьютером либо 1х1 с человеком" << endl;
	cout << endl;

	int mode;
	int diff;
	do
	{
		do
		{
			cout << "Выберете режим: 1 - c компьтером. 2 - с человеком." << endl;
			cin >> mode;
			if (mode == 1)
			{
				do
				{
					cout << "Вы выбрали режим игры с компьтером, выберете сложность, 1 - легкий, 2 - сложный. " << endl;
					cin >> diff;
					if (diff == 1)
					{
						cout << "легкий режим:\n";
						break;
					}
					else if (diff == 2)
					{
						cout << "сложный режим:\n";
						break;
					}
					else
					{
						cout << "Неверный режиим!\n";
					}
					

				} while (1 <= diff < 3);
				break;
			}
			else if (mode == 2)
			{
				cout << "Вы выбрали режим игры 1х1" << endl;
				break;
			}
			else
			{
				cout << "Неверный режим!" << endl;
			}


		} while (1 <= mode < 3);

		cout << endl;
		system("pause");
		cout << endl;
		system("cls");
		InitializationGameBoard();

		ShowGameBoard();

		for (int step = 1; step <= 5; step++)
		{
			cout << "Ход Крестика" << endl;
			StepGamer(TOE);
			system("cls");
			ShowGameBoard();
			if (step == 5)
			{
				cout << "Ничья!" << endl;
				break;
			}
			if (CheckWin(3))
			{
				cout << "Крестик победил!" << endl;
				break;
			}
			else
			{
				cout << "Ход Нолика" << endl;
				if (mode == 2)
					StepGamer(TAC);
				if (mode == 1)
				{
					switch (diff)
					{
					case 1:
						StepAi(TAC);
						break;
					case 2:
						StepSuperAi(TAC, step);
						break;
					}
				}
			}
			system("cls");
			ShowGameBoard();
			if (CheckWin(-3))
			{
				cout << "Нолик победил!" << endl;
				break;
			}

		}
		
		cout << "Желаете сыграть еще раз?\n";
		cout << " 1 - да, 2 - нет\n";
		cin >> choise;
	} while (choise == 1);
		
}			
void InitializationGameBoard()	//заполнение нулями поле
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
}
bool CheckCoordinates(int x, int y)  //проверка координат свободна ли клетка
{
	if (gameBoard[x][y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CheckGameBooard(int x, int y)		//проверка координат входят ли они в область 3х3
{
	if (x >= 0 && x < 3 && y >= 0 && y < 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void StepGamer(int gamer)  // ввод Х и 0
{
	int x, y;
	do
	{
		do
		{
			cout << "Введите координаты" << endl;
			cout << "X: "; cin >> x; cout << endl;
			cout << "Y: "; cin >> y; cout << endl;
		} while (!CheckGameBooard(x, y));	//проверка координат входят ли они в область 3х3
	} while (!CheckCoordinates(x, y));			//проверка координат свободна ли клетка
	gameBoard[x][y] = gamer;
}
bool CheckWin(int win)		//проверкан а победу
{
	int MirrorGameBord[SIZE][SIZE];
	int sum_row0, sum_row1, sum_row2, sum_col0, sum_col1, sum_col2, sum_diag1, sum_diag2;

	for (int i = 0; i < SIZE; i++)
	{
		sum_row0 = 0;
		sum_row1 = 0;
		sum_row2 = 0;
		sum_col0 = 0;
		sum_col1 = 0;
		sum_col2 = 0;
		sum_diag1 = 0;
		sum_diag2 = 0;

		for (int j = 0; j < SIZE; j++)
		{
			MirrorGameBord[i][j] = gameBoard[j][i];
			sum_row0 = gameBoard[0][0] + gameBoard[0][1] + gameBoard[0][2];
			sum_row1 = gameBoard[1][0] + gameBoard[1][1] + gameBoard[1][2];
			sum_row2 = gameBoard[2][0] + gameBoard[2][1] + gameBoard[2][2];
			sum_col0 = gameBoard[0][0] + gameBoard[1][0] + gameBoard[2][0];
			sum_col1 = gameBoard[0][1] + gameBoard[1][1] + gameBoard[2][1];
			sum_col2 = gameBoard[0][2] + gameBoard[1][2] + gameBoard[2][2];
			sum_diag1 += gameBoard[j][j];
			sum_diag2 = gameBoard[0][2] + gameBoard[1][1] + gameBoard[2][0];
		}

	}
		if (sum_row0 == win || sum_row1 == win || sum_row2 == win || sum_col0 == win || sum_col1 == win || sum_col2 == win || sum_diag1 == win || sum_diag2 == win)
		{
			return true;
		}
		else
		{
			return false;
		}
}

void ShowGameBoard()		// заполнение поля символами " "; " Х "; " 0 "
{
	int c = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			switch (gameBoard[i][j])
			{
			case 0:
				cout << "|   |";
				break;
			case TOE:
				cout << "| X |";
				break;
			case TAC:
				cout << "| O |";
				break;
			}
			if (j == 2)
				cout << "  |" << c;
		}
		c++;
		cout << endl;
		cout << "---------------";
		cout << endl;
		if (i == 2)
			cout << " |0|  |1|  |2|  " << endl;
	}
}

void StepAi(int gamer)
{
	int x, y;
	do 
	{
		x = rand() % 3;
		y = rand() % 3;
	} while (!CheckCoordinates(x, y));
		gameBoard[x][y] = gamer;		   
	
}

void StepSuperAi(int gamer, int step)
{
	int x, y;

	int MirrorGameBord[SIZE][SIZE];
	int sum_row0, sum_row1, sum_row2, sum_col0, sum_col1, sum_col2, sum_diag1, sum_diag2;

	for (int i = 0; i < SIZE; i++)
	{
		sum_row0 = 0;
		sum_row1 = 0;
		sum_row2 = 0;
		sum_col0 = 0;
		sum_col1 = 0;
		sum_col2 = 0;
		sum_diag1 = 0;
		sum_diag2 = 0;
		for (int j = 0; j < SIZE; j++)
		{
			MirrorGameBord[i][j] = gameBoard[j][i];
			sum_row0 = gameBoard[0][0] + gameBoard[0][1] + gameBoard[0][2];
			sum_row1 = gameBoard[1][0] + gameBoard[1][1] + gameBoard[1][2];
			sum_row2 = gameBoard[2][0] + gameBoard[2][1] + gameBoard[2][2];
			sum_col0 = gameBoard[0][0] + gameBoard[1][0] + gameBoard[2][0];
			sum_col1 = gameBoard[0][1] + gameBoard[1][1] + gameBoard[2][1];
			sum_col2 = gameBoard[0][2] + gameBoard[1][2] + gameBoard[2][2];
			sum_diag1 += gameBoard[j][j];
			sum_diag2 = gameBoard[0][2] + gameBoard[1][1] + gameBoard[2][0];

		}
		
	}	


		int c = 0;
		do
		{


		switch (step)
		{

			case 1:
				if (gameBoard[0][0] == TOE || gameBoard[2][0] == TOE || gameBoard[0][2] == TOE || gameBoard[2][2] == TOE)
				{					
					x = 1;
					y = 1;

					break;
				}
				else if (gameBoard[1][1] == TOE)
				{
					c = rand() % 4 + 1;
					if (c == 1)
					{						
						x = 0;
						y = 0;
					}
						
					else if (c == 2)
					{						
						x = 0;
						y = 2;
					}
						
					else if  (c == 3)
					{						
						x = 2;
						y = 0;

					}
						
					else if (c == 4)
					{						
						x = 2;
						y = 2;
					}
						
					break;
				}

				else if (gameBoard[0][1] == TOE || gameBoard[1][0] == TOE || gameBoard[1][2] == TOE || gameBoard[2][1] == TOE)
				{					
					x = 1;
					y = 1;
					break;
				}

			case 2:
				if ((gameBoard[0][0] == TOE && gameBoard[2][2] == TOE) || (gameBoard[0][2] == TOE && gameBoard[2][0] == TOE))
				{
					c = rand() % 4 + 1;
					if (c == 1)
					{						
						x = 0;
						y = 1;
					}
					if (c == 2)
					{						
						x = 1;
						y = 0;
					}
						
					if (c == 3)
					{						
						x = 1;
						y = 2;
					}
						
					if (c == 4)
					{						
						x = 2;
						y = 1;
					}
						
					break;
				}
				else if ((gameBoard[0][0] == TOE && gameBoard[0][1] == TOE) || (gameBoard[0][0] == TOE && gameBoard[0][2] == TOE) || (gameBoard[0][1] == TOE && gameBoard[0][2] == TOE))
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{						
						x = 0;
						y = 1;
					}
						
					if (c == 2) 
					{						
						x = 0;
						y = 2;						
					}
					if (c == 3)
					{
						x = 0;
						y = 0;
					}
					break;
				}

				else if ((gameBoard[2][0] == TOE && gameBoard[2][1] == TOE) || (gameBoard[2][0] == TOE && gameBoard[2][2] == TOE) || (gameBoard[2][1] == TOE && gameBoard[2][2] == TOE))
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 0;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					
					if (c == 3)
					{
						x = 2;
						y = 2;
					}
					break;
				}
				
				else if ((gameBoard[0][0] == TOE && gameBoard[1][0] == TOE) || (gameBoard[0][0] == TOE && gameBoard[2][0] == TOE) || (gameBoard[1][0] == TOE && gameBoard[2][0] == TOE))
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 0;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 0;
					}
					if (c == 3)
					{
						x = 2;
						y = 0;
					}
					break;
				}

				else if ((gameBoard[2][2] == TOE && gameBoard[0][2] == TOE) || (gameBoard[2][2] == TOE && gameBoard[1][2] == TOE) || (gameBoard[0][2] == TOE && gameBoard[1][2] == TOE))
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 2;
					}

					if (c == 2)
					{
						x = 0;
						y = 2;
					}

					if (c == 3)
					{
						x = 1;
						y = 2;
					}
					break;
				}

				else if ((gameBoard[0][0] == TOE && gameBoard[1][2] == TOE) || (gameBoard[0][0] == TOE && gameBoard[2][1] == TOE))
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 1;
						y = 2;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}	
					break;
				}

				else if ((gameBoard[0][2] == TOE && gameBoard[1][0] == TOE) || (gameBoard[0][2] == TOE && gameBoard[2][1] == TOE))
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					break;
				}


				else if ((gameBoard[2][0] == TOE && gameBoard[0][1] == TOE) || (gameBoard[2][0] == TOE && gameBoard[1][2] == TOE))
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 1;
						y = 2;
					}
					break;
				}

				else if ((gameBoard[2][2] == TOE && gameBoard[1][0] == TOE) || (gameBoard[2][2] == TOE && gameBoard[0][1] == TOE))
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 0;
						y = 1;
					}
					break;
				}

				else if ((gameBoard[1][1] == TOE && gameBoard[0][1] == TOE) || (gameBoard[1][1] == TOE && gameBoard[2][1] == TOE))
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					break;
				}

				else if ((gameBoard[1][1] == TOE && gameBoard[1][0] == TOE) || (gameBoard[1][1] == TOE && gameBoard[1][2] == TOE))
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 2;
					}
					break;
				}								

				else if ((gameBoard[1][1] == TOE && gameBoard[2][2] == TOE) || (gameBoard[1][1] == TOE && gameBoard[0][2] == TOE) || (gameBoard[1][1] == TOE && gameBoard[0][0] == TOE) || (gameBoard[1][1] == TOE && gameBoard[2][0] == TOE))
				{
					if (sum_diag1 == 2)
					{
						c = rand() % 2 + 1;
						if (c == 1)
						{
							x = 0;
							y = 0;
						}

						if (c == 2)
						{
							x = 2;
							y = 2;
						}
						break;
					}

					else if (sum_diag2 == 2)
					{
						c = rand() % 2 + 1;
						if (c == 1)
						{
							x = 0;
							y = 2;
						}

						if (c == 2)
						{
							x = 2;
							y = 0;
						}
						break;

					}								

					else if ((sum_diag2 == 1 && gameBoard[0][2] == TAC) || (sum_diag2 == 1 && gameBoard[2][0] == TAC))
					{
							c = rand() % 2 + 1;
							if (c == 1)
							{
								x = 0;
								y = 0;
							}

							if (c == 2)
							{
								x = 2;
								y = 2;
							}
							break;

					}

					else if ((sum_diag1 == 1 && gameBoard[0][0] == TAC) || (sum_diag1 == 1 && gameBoard[2][2] == TAC));
						{
							c = rand() % 2 + 1;
							if (c == 1)
							{
								x = 0;
								y = 2;
							}

							if (c == 2)
							{
								x = 2;
								y = 0;
							}
							break;
						}
						break;
				}
				

				else if (gameBoard[0][1] == TOE && gameBoard[1][0] == TOE)
					{
						x = 0;
						y = 0;
						break;
					}

				else if (gameBoard[0][1] == TOE && gameBoard[1][2] == TOE)
					{
						x = 0;
						y = 2;
						break;
					}

				else if (gameBoard[1][2] == TOE && gameBoard[2][1] == TOE)
					{
						x = 2;
						y = 2;
						break;
					}

				else if (gameBoard[2][1] == TOE && gameBoard[1][0] == TOE)
					{
						x = 2;
						y = 0;
						break;
					}

				else if ((gameBoard[1][0] == TOE && gameBoard[1][2] == TOE) || (gameBoard[0][1] == TOE && gameBoard[2][1] == TOE))
					{
						c = rand() % 4 + 1;
						if (c == 1)
						{
							x = 0;
							y = 0;
						}

						else if (c == 2)
						{
							x = 0;
							y = 2;
						}

						else if (c == 3)
						{
							x = 2;
							y = 0;
						}

						else if (c == 4);
						{
							x = 2;
							y = 2;
						}
						break;
				}

			case 3:

				if ((gameBoard[0][0] == TAC || gameBoard[0][1] == TAC || gameBoard[0][2] == TAC) && sum_row0 == -2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 0;
						y = 2;
					}
					if (c == 3)
					{
						x = 0;
						y = 0;
					}
					break;
				}

				else if ((gameBoard[1][0] == TAC || gameBoard[1][1] == TAC || gameBoard[1][2] == TAC) && sum_row1 == -2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 1;
					}
					if (c == 3)
					{
						x = 1;
						y = 2;
					}
					break;
				}

				else if ((gameBoard[2][0] == TAC || gameBoard[2][1] == TAC || gameBoard[2][2] == TAC) && sum_row2 == -2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 0;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					if (c == 3)
					{
						x = 2;
						y = 2;
					}
					break;
				}

				else if ((gameBoard[0][0] == TAC || gameBoard[1][0] == TAC || gameBoard[2][0] == TAC) && sum_col0 == -2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 0;
					}
					if (c == 3)
					{
						x = 0;
						y = 0;
					}
					break;
				}

				else if ((gameBoard[0][1] == TAC || gameBoard[1][1] == TAC || gameBoard[2][1] == TAC) && sum_col1 == -2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 1;
						y = 1;
					}
					if (c == 3)
					{
						x = 2;
						y = 1;
					}
					break;
				}

				else if ((gameBoard[0][2] == TAC || gameBoard[1][2] == TAC || gameBoard[2][2] == TAC) && sum_col2 == -2)
				{
				c = rand() % 3 + 1;
				if (c == 1)
				{
					x = 0;
					y = 2;
				}

				if (c == 2)
				{
					x = 1;
					y = 2;
				}
				if (c == 3)
				{
					x = 2;
					y = 2;
				}
				break;
				}

				else if ((gameBoard[0][0] == TAC || gameBoard[1][1] == TAC || gameBoard[2][2] == TAC) && sum_diag1 == -2)
				{
				c = rand() % 3 + 1;
				if (c == 1)
				{
					x = 0;
					y = 0;
				}

				if (c == 2)
				{
					x = 1;
					y = 1;
				}
				if (c == 3)
				{
					x = 2;
					y = 2;
				}
				break;
				}

				else if ((gameBoard[0][2] == TAC || gameBoard[1][1] == TAC || gameBoard[2][0] == TAC) && sum_diag2 == -2)
				{
				c = rand() % 3 + 1;
				if (c == 1)
				{
					x = 2;
					y = 0;
				}

				if (c == 2)
				{
					x = 1;
					y = 1;
				}
				if (c == 3)
				{
					x = 0;
					y = 2;
				}
				break;
				}

				else if (gameBoard[0][0] == TOE && gameBoard[2][0] == TOE && gameBoard[1][2] == TOE)
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					break;
				}

				else if (gameBoard[0][0] == TOE && gameBoard[0][2] == TOE && gameBoard[2][1] == TOE)
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 2;
					}
					break;
				}

				else if (gameBoard[0][2] == TOE && gameBoard[2][2] == TOE && gameBoard[1][0] == TOE)
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					break;
				}

				else if (gameBoard[2][0] == TOE && gameBoard[2][2] == TOE && gameBoard[0][1] == TOE)
				{
					c = rand() % 2 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 2;
					}
					break;
				}

				else if ((gameBoard[0][0] == TOE || gameBoard[0][1] == TOE || gameBoard[0][2] == TOE) && sum_row0 ==2 )
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 0;
						y = 1;
					}

					if (c == 2)
					{
						x = 0;
						y = 2;
					}
					if (c == 3)
					{
						x = 0;
						y = 0;
					}
					break;
				}

				else if ((gameBoard[1][0] == TOE || gameBoard[1][1] == TOE || gameBoard[1][2] == TOE) && sum_row1 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 1;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 2;
					}
					if (c == 3)
					{
						x = 1;
						y = 2;
					}
					break;
				}

				else if ((gameBoard[2][0] == TOE || gameBoard[2][1] == TOE || gameBoard[2][2] == TOE) && sum_row2 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 0;
					}

					if (c == 2)
					{
						x = 2;
						y = 1;
					}
					if (c == 3)
					{
						x = 2;
						y = 2;
				}
				break;
				}

				else if ((gameBoard[0][0] == TOE || gameBoard[1][0] == TOE || gameBoard[2][0] == TOE) && sum_col0 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 0;
					}

					if (c == 2)
					{
						x = 1;
						y = 0;
					}
					if (c == 3)
					{
						x = 0;
						y = 0;
					}
				break;
				}

				else if ((gameBoard[0][1] == TOE || gameBoard[1][1] == TOE || gameBoard[2][1] == TOE) && sum_col1 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 1;
					}

					if (c == 2)
					{
						x = 1;
						y = 1;
					}
					if (c == 3)
					{
						x = 0;
						y = 1;
					}
				break;
				}

				else if ((gameBoard[0][2] == TOE || gameBoard[1][2] == TOE || gameBoard[2][2] == TOE) && sum_col2 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 2;
					}

					if (c == 2)
					{
						x = 1;
						y = 2;
					}
					if (c == 3)
					{
						x = 0;
						y = 2;
					}
				break;
				}

				else if ((gameBoard[0][0] == TOE || gameBoard[1][1] == TOE || gameBoard[2][2] == TOE) && sum_diag1 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 2;
						y = 2;
					}

					if (c == 2)
					{
						x = 1;
						y = 1;
					}
					if (c == 3)
					{
						x = 0;
						y = 0;
					}
				break;
				}

				else if ((gameBoard[0][2] == TOE || gameBoard[1][1] == TOE || gameBoard[2][0] == TOE) && sum_diag2 == 2)
				{
					c = rand() % 3 + 1;
					if (c == 1)
					{
						x = 0;
						y = 2;
					}

					if (c == 2)
					{
						x = 1;
						y = 1;
					}
					if (c == 3)
					{
						x = 2;
						y = 0;
					}
				break;
				}

				case 4:
					if ((gameBoard[0][0] == TAC || gameBoard[0][1] == TAC || gameBoard[0][2] == TAC) && sum_row0 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 0;
							y = 1;
						}

						if (c == 2)
						{
							x = 0;
							y = 2;
						}
						if (c == 3)
						{
							x = 0;
							y = 0;
						}
						break;
					}

					else if ((gameBoard[1][0] == TAC || gameBoard[1][1] == TAC || gameBoard[1][2] == TAC) && sum_row1 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 1;
							y = 0;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 1;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[2][0] == TAC || gameBoard[2][1] == TAC || gameBoard[2][2] == TAC) && sum_row2 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 0;
						}

						if (c == 2)
						{
							x = 2;
							y = 1;
						}
						if (c == 3)
						{
							x = 2;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[0][0] == TAC || gameBoard[1][0] == TAC || gameBoard[2][0] == TAC) && sum_col0 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 0;
						}

						if (c == 2)
						{
							x = 1;
							y = 0;
						}
						if (c == 3)
						{
							x = 0;
							y = 0;
						}
						break;
					}

					else if ((gameBoard[0][1] == TAC || gameBoard[1][1] == TAC || gameBoard[2][1] == TAC) && sum_col1 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 0;
							y = 1;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 2;
							y = 1;
						}
						break;
					}

					else if ((gameBoard[0][2] == TAC || gameBoard[1][2] == TAC || gameBoard[2][2] == TAC) && sum_col2 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 0;
							y = 2;
						}

						if (c == 2)
						{
							x = 1;
							y = 2;
						}
						if (c == 3)
						{
							x = 2;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[0][0] == TAC || gameBoard[1][1] == TAC || gameBoard[2][2] == TAC) && sum_diag1 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 0;
							y = 0;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 2;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[0][2] == TAC || gameBoard[1][1] == TAC || gameBoard[2][0] == TAC) && sum_diag2 == -2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 0;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 0;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[0][0] == TOE || gameBoard[0][1] == TOE || gameBoard[0][2] == TOE) && sum_row0 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 0;
							y = 1;
						}

						if (c == 2)
						{
							x = 0;
							y = 2;
						}
						if (c == 3)
						{
							x = 0;
							y = 0;
						}
						break;
					}

					else if ((gameBoard[1][0] == TOE || gameBoard[1][1] == TOE || gameBoard[1][2] == TOE) && sum_row1 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 1;
							y = 0;
						}

						if (c == 2)
						{
							x = 1;
							y = 2;
						}
						if (c == 3)
						{
							x = 1;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[2][0] == TOE || gameBoard[2][1] == TOE || gameBoard[2][2] == TOE) && sum_row2 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 0;
						}

						if (c == 2)
						{
							x = 2;
							y = 1;
						}
						if (c == 3)
						{
							x = 2;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[0][0] == TOE || gameBoard[1][0] == TOE || gameBoard[2][0] == TOE) && sum_col0 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 0;
						}

						if (c == 2)
						{
							x = 1;
							y = 0;
						}
						if (c == 3)
						{
							x = 0;
							y = 0;
						}
						break;
					}

					else if ((gameBoard[0][1] == TOE || gameBoard[1][1] == TOE || gameBoard[2][1] == TOE) && sum_col1 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 1;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 0;
							y = 1;
						}
						break;
					}

					else if ((gameBoard[0][2] == TOE || gameBoard[1][2] == TOE || gameBoard[2][2] == TOE) && sum_col2 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 2;
						}

						if (c == 2)
						{
							x = 1;
							y = 2;
						}
						if (c == 3)
						{
							x = 0;
							y = 2;
						}
						break;
					}

					else if ((gameBoard[0][0] == TOE || gameBoard[1][1] == TOE || gameBoard[2][2] == TOE) && sum_diag1 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 2;
							y = 2;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 0;
							y = 0;
						}
						break;
					}

					else if ((gameBoard[0][2] == TOE || gameBoard[1][1] == TOE || gameBoard[2][0] == TOE) && sum_diag2 == 2)
					{
						c = rand() % 3 + 1;
						if (c == 1)
						{
							x = 0;
							y = 2;
						}

						if (c == 2)
						{
							x = 1;
							y = 1;
						}
						if (c == 3)
						{
							x = 2;
							y = 0;
						}
						break;
					}

					else
					{
						x = rand() % 3;
						y = rand() % 3;
				    }		
								
			default:
				break;

		}

		} while (!CheckCoordinates(x, y));
		gameBoard[x][y] = gamer;
			
	
	
}