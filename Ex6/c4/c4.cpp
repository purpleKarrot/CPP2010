// connect 4

#include <iostream>
#include <cstdlib>
#include "c4.h"

char print(char cell)
{
	if (cell == 1)
		return 'x';
	if (cell == 2)
		return 'o';
	return ' ';
}

template<int Rows, int Cols>
void print(const connect4<Rows, Cols>& c4)
{
	for (int row = Rows; row; --row)
	{
		std::cout << "| ";

		for (int col = 0; col < Cols; ++col)
			std::cout << print(c4(col, row - 1));

		std::cout << " |" << std::endl;
	}
}

template<int Rows, int Cols>
int strategy(const connect4<Rows, Cols>& c4, char player)
{
	// human player
	if (player == 1)
	{
		int i;
		std::cout << "chose col: ";
		std::cin >> i;
		return i;
	}

	// computer player, attack
	for (int row = 0; row < Rows; ++row)
	{
		for (int col = 0; col < Cols; ++col)
		{
			if (c4.accessible(col, row) && c4.check_pos(col, row, 2))
			{
				return col;
			}
		}
	}

	// computer player, defend
	for (int row = 0; row < Rows; ++row)
	{
		for (int col = 0; col < Cols; ++col)
		{
			if (c4.accessible(col, row) && c4.check_pos(col, row, 1))
			{
				return col;
			}
		}
	}

	// chose randomly
	return rand() % Cols;
}

int main(int argc, char* argv[])
{
	connect4<6, 7> c4;
	srand(time(0));

	for (int k = 0; k < 100; ++k)
	{
		char player = k % 2 + 1;

		c4.insert(strategy(c4, player), player);
		print(c4);
		std::cout << ".........................." << std::endl;

		int winner = c4.winner();
		if (winner)
		{
			std::cout << "player " << winner << " wins!" << std::endl;
			return 0;
		}
	}
}
