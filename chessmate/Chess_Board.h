#pragma once
#include <string>
int x = -1, y = -1;
int move_x = -1, move_y = -1;
std::string** m_matrix;
class Chess_Board
{
protected:
	const int m_rows = 8, m_columns = 8;
	void Swap();
	void getmove();
	void getcoords();
	bool check_coords();//if there was figure return 1 else 0
	bool check_coords(int x, int y);
public:
	void def_init();//default chess board
	void display();
	void Select_Figure();
	void Black_Select();
	void Black_Move();
	void getcoords();
	void getmove();
	void Move_Figure();
	void Start();
		Chess_Board() {};
		~Chess_Board() noexcept {};
	Chess_Board(Chess_Board&& other) = delete;
	Chess_Board& operator=(Chess_Board&& other) = delete;
};

