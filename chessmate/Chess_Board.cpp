#include <iostream>
#include "Chess_Board.h"
#include "Bishop.cpp"
#include "King.cpp"
#include "Knight.cpp"
#include "Pawn.cpp"
#include "Queen.cpp"
#include "Rook.cpp"
using namespace std;
int x = -1, y = -1;
int move_x = -1, move_y = -1;
std::string** m_matrix;

class Chess_Board {
protected:
	 const int m_rows = 8, m_columns = 8;
	std::string** m_matrix;
	std::string B_Chessmate_types[5]{ " B.Rook "," B.Knight "," B.Bishop "," B.Queen "," B.King ","  W.Pawn " };
	std::string W_Chessmate_types[5]{ " W.Rook "," W.Knight "," W.Bishop "," W.Queen "," W.King ","  W.Pawn " };
	void Swap() {};
	void getmove() {
		while (move_x < 0 && move_y < 0) {
			cout << "Where you want to move that figure\n";
			cin >> move_x;
			cout << "Input the y\n";
			cin >> move_y;
		}
	};
	void getcoords() {
		while (x < 0 && y < 0)
		{
			cout << "Input the coordinats of figure that you want to move(first x and y)\n";
			cin >> x;
			cout << "Input the y\n";
			cin >> y;
		}
	};
	bool check_coords() {
		if (x < 0 || y < 0)
		{
			cout << "The block where you want to move doesent have\n";
			throw std::abort;
		}
		else if (m_matrix[x][y] == " _______ ")
		{
			return 0;
		}
		else {
			return 1;
		}
	};//if there was figure return 1 else 0
	bool check_coords(int x, int y) {
		if (x < 0 || y < 0)
		{
			cout << "The block where you want to move doesent \n input again\n";
			throw std::abort;
		}
		else if (m_matrix[x][y] == " _______ ")
		{
			return 0;
		}
		else {
			return 1;
		}
	};
public:
	void def_init() {
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_matrix[i][j] = " _______ ";
			}
		}
		string BChessmate_types[9]{ " B.Rook "," B.Knight "," B.Bishop "," B.Queen "," B.King "," B.Bishop "," B.Knight "," B.Rook " };
		string WChessmate_types[9]{ " W.Rook "," W.Knight "," W.Bishop "," W.Queen "," W.King "," W.Bishop "," W.Knight "," W.Rook " };
		for (int i = 0; i < 8; i++)
		{
			m_matrix[0][i] = WChessmate_types[i];
			m_matrix[1][i] = "  W.Pawn ";
		}
		for (int i = 0; i < 8; i++)
		{
			m_matrix[7][i] = BChessmate_types[i];
			m_matrix[6][i] = "  B.Pawn ";
		}
	};//default chess board
	void display() {
			char a = 'A';
			for (int i = 0; i < m_rows; i++)
			{

				cout << "     " << a << "   |";
				++a;
			}
			cout << std::endl;
			for (int i = 0; i < m_rows; i++)
			{
				cout << std::endl << i << "[";
				for (int j = 0; j < m_columns; j++)
				{
					cout << m_matrix[i][j] << "|";
				}
				cout << "]\n";
			}
	};
	void Select_Figure() {
		getcoords();
		if (check_coords() == 0)
		{
			cerr << "There wasnt figure\n";
			cout << "Something went wrong\n";
			Select_Figure();
		}
		else if (x > m_rows || y > m_columns)
		{
			cerr << "the cordinats are illegal\n";
			cout << "Something went wrong\n";
			Select_Figure();
		}
		for (size_t i = 0; i < m_rows; i++)
		{
			if (W_Chessmate_types[i] == m_matrix[x][y]) {
				return;
			}
		}
		cout << "Something went wrong\n";
		Select_Figure();
	};
	void Black_Select() {
		getcoords();
		if (check_coords() == 0)
		{
			cerr << "There wasnt figure\n";
			cout << "Something went wrong\n";
			Black_Select();
		}
		else if (x > m_rows || y > m_columns)
		{
			cerr << "the cordinats are illegal\n";
			cout << "Something went wrong\n";
			Black_Select();
		}
		for (size_t i = 0; i < m_rows; i++)
		{
			if (B_Chessmate_types[i] == m_matrix[x][y]) {
				return;
			}
		}
		cout << "Something went wrong\n";
		Black_Select();
	}
	void Black_Move() {
		Select_Figure();
		getmove();
		if (move_x > 8 || move_y > 8)
		{
			cerr << "the cordinats are illegal\n";
			cout << "Something went wrong\n";
			getmove();
		}
		if (move_x == x && move_y == y)
		{
			cerr << "Error:you want to dont move figure\n";
			cout << "Something went wrong\n";
			Move_Figure();
		}
		for (int i = 0; i < m_rows; i++)
		{
			if (W_Chessmate_types[i] == m_matrix[move_x][move_y]) {
				cerr << "ERROR:There was your figure\n";
				cout << "Something went wrong\n";
				Move_Figure();
			}
		}
		Rook::Move_Rook();
		Knight::Move_Knight();
		Bishop::Move_Bishop();
		Queen::Move_Queen();
		King::Move_King();
		Pawn::Move_Pawn();
	}
	void Move_Figure() {
		Select_Figure();
		getmove();
		if (move_x > 8 || move_y > 8)
		{
			cerr << "the cordinats are illegal\n";
			cout << "Something went wrong\n";
			getmove();
		}
		if (move_x == x && move_y == y)
		{
			cerr << "Error:you want to dont move figure\n";
			cout << "Something went wrong\n";
			Move_Figure();
		}
		for (int i = 0; i < m_rows; i++)
		{
			if (W_Chessmate_types[i] == m_matrix[move_x][move_y]) {
				cerr << "ERROR:There was your figure\n";
				cout << "Something went wrong\n";
				Move_Figure();
			}
		}
			Rook::Move_Rook();
			Knight::Move_Knight();
			Bishop::Move_Bishop();
			Queen::Move_Queen();
			King::Move_King();
			Pawn::Move_Pawn();
	};

	void Swap(string* a,string * b) {
		string temp = *a;
		*a = *b;
		*b = " _______ ";
	};
	void Start() {
		def_init();
		cout << "Hello To Chess Game Play as you want to play\n";
		cout << "Instructions:For first you must to input the\n";
		cout << "coordinats of chessman that you want to play\n";
		cout << "the secont you must be right input the coordinats\n";
		cout << "where you want to go your figure\n Nice game\n";
		display();
		while (true)
		{
			cout << "\n The White Move\n";
			Move_Figure();
			//check mate or not
			system("cls");
			cout << "\nThe Black Move\n";
		    Black_Move();
			//check mate or not
			system("cls");
		}
	}
	Chess_Board() {
		m_matrix = new string * [m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_matrix[i] = new string[m_columns];
		}
	};
	~Chess_Board() noexcept {
		for (int i = 0; i < m_rows; i++)
		{
			delete[] m_matrix[i];
			m_matrix[i] = nullptr;
		}
		delete[] m_matrix;
		m_matrix = nullptr;
	}
	Chess_Board(Chess_Board&& other) = delete;
	Chess_Board& operator=(Chess_Board&& other) = delete;
};