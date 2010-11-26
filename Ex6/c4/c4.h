//

template<int Rows, int Cols>
class connect4
{
public:
	connect4()
	{
		clear();
	}

	void clear()
	{
		for (int row = 0; row < Rows; ++row)
			for (int col = 0; col < Cols; ++col)
				grid[col][row] = 0;
	}

	bool insert(int col, char player)
	{
		for (int row = 0; row < Rows; ++row)
		{
			if (!grid[col][row])
			{
				grid[col][row] = player;
				return true;
			}
		}
		return false;
	}

	char operator()(int col, int row) const
	{
		return grid[col][row];
	}

	// check: this spot will lead to a win
	bool check_pos(int col, int row, char player) const
	{
		return check_line(col, row, +1, +0, player) || //
				check_line(col, row, +1, +1, player) || //
				check_line(col, row, +0, +1, player) || //
				check_line(col, row, -1, +1, player) || //
				check_line(col, row, -1, +0, player) || //
				check_line(col, row, -1, -1, player) || //
				check_line(col, row, +0, -1, player) || //
				check_line(col, row, +1, -1, player);
	}

	//field is free, field below is invalid or occupied
	bool accessible(int col, int row) const
	{
		return !grid[col][row] && (!valid(col, row - 1) || grid[col][row - 1]);
	}

	// checks for 4 in a row, returns id of winning player (or zero)
	char winner() const
	{
		for (int row = 0; row < Rows; ++row)
		{
			for (int col = 0; col < Cols; ++col)
			{
				char player = grid[col][row];
				if (player && check_pos(col, row, player))
					return player;
			}
		}
		return 0;
	}

private:
	bool valid(int c, int r) const
	{
		return c >= 0 && c < Cols && r >= 0 && r < Rows;
	}

	// check row of three next in specified direction
	// this field leads to a win
	bool check_line(int col, int row, int dc, int dr, char player) const
	{
		for (int i = 3; i; --i)
		{
			col += dc;
			row += dr;

			if (!valid(col, row))
				return false;

			if (grid[col][row] != player)
				return false;
		}
		return true;
	}

private:
	char grid[Cols][Rows];
};
