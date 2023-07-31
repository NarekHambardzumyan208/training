#pragma once
#include <iostream>
using namespace std;
class Chess_Board
{
protected:
	int x = -1, y = -1;
	int move_x = -1, move_y = -1;
	string** m_matrix;
	const int m_rows = 8, m_columns = 8;
	void getmove();
	void getcoords();
	bool check_coords();//if there was figure return 1 else 0
public:
	bool isCheck(bool);
	bool isCheckAfterMove(int,int,int,int,bool);
	bool isMate(bool);
	void def_init();//default chess board
	void display();
	void Select_Figure();
	void Black_Select();
	void Black_Move();
	void Move_Figure();
	void Start();
	Chess_Board(Chess_Board&& other) = delete;
	~Chess_Board() {
		for (int i = 0; i < m_rows; i++)
		{
			delete[] m_matrix[i];
			m_matrix[i] = nullptr;
		}
		delete[] m_matrix;
		m_matrix = nullptr;
	}
	Chess_Board() {
		m_matrix = new std::string * [m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_matrix[i] = new std::string[m_columns];
		}
	};

	Chess_Board& operator=(Chess_Board&& other) = delete;
};

