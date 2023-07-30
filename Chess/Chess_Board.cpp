#include "Chess_Board.h"
#include "Figures.cpp"
#include <iostream>
using namespace std;
#pragma region variables
   const int m_rows = 8, m_columns = 8;
	std::string W_Chessmate_types[6]{ " W.Rook "," W.Knight "," W.Bishop "," W.Queen "," W.King ","  W.Pawn " };
	bool Chess_Board::check_coords() {
		if (x < 0 || y < 0)
		{
			cout << "The block where you want to move doesn't exist\ninput again\n";
			throw std::runtime_error("Invalid coordinates.");
		}
		else if (m_matrix[x][y] == " _______ ")
		{
			return false;
		}
		else {
			return true;
		}
	}
#pragma endregion
#pragma region set_Functions
	void Chess_Board::getmove() {
		cout << "Where you want to move that figure\n";
		cin >> move_x;
		cout << "Input the y\n";
		cin >> move_y;
		while (move_x < 0 && move_y < 0) {
			cout << "Where you want to move that figure\n";
			cin >> move_x;
			cout << "Input the y\n";
			cin >> move_y;
		}
	};
	void Chess_Board::getcoords() {
		cout << "Input the coordinats of figure that you want to move(first x and y)\n";
		cin >> x;
		cout << "Input the y\n";
		cin >> y;
		while (x < 0 && y < 0)
		{
			cout << "Input the coordinats of figure that you want to move(first x and y)\n";
			cin >> x;
			cout << "Input the y\n";
			cin >> y;
		}
	};
	#pragma endregion
#pragma region Check
	bool Chess_Board::isCheck(bool isWhiteTurn)
	{
		int king_x, king_y;
		string king;

		if (isWhiteTurn)
		{
			king = " W.King ";
		}
		else
		{
			king = " B.King ";
		}

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				if (m_matrix[i][j] == king)
				{
					king_x = i;
					king_y = j;
					break;
				}
			}
		}

		string enemyRook = (isWhiteTurn) ? " B.Rook " : " W.Rook ";
		string enemyBishop = (isWhiteTurn) ? " B.Bishop " : " W.Bishop ";
		string enemyQueen = (isWhiteTurn) ? " B.Queen " : " W.Queen ";
		string enemyKnight = (isWhiteTurn) ? " B.Knight " : " W.Knight ";
		string enemyPawn = (isWhiteTurn) ? " B.Pawn " : " W.Pawn ";

		int dx[] = { -1, 1, 1, -1 };
		int dy[] = { -1, -1, 1, 1 };

		for (int k = 0; k < 4; k++)
		{
			int x = king_x + dx[k];
			int y = king_y + dy[k];

			while (x >= 0 && x < m_rows && y >= 0 && y < m_columns)
			{
				string piece = m_matrix[x][y];
				if (piece != " _______ " && (piece == enemyBishop || piece == enemyQueen))
				{
					return true;
				}
				if (piece != " _______ ")
				{
					break;
				}
				x += dx[k];
				y += dy[k];
			}
		}

		int dxRook[] = { 0, 0, 1, -1 };
		int dyRook[] = { 1, -1, 0, 0 };

		for (int k = 0; k < 4; k++)
		{
			int x = king_x + dxRook[k];
			int y = king_y + dyRook[k];

			while (x >= 0 && x < m_rows && y >= 0 && y < m_columns)
			{
				string piece = m_matrix[x][y];
				if (piece != " _______ " && (piece == enemyRook || piece == enemyQueen))
				{
					return true;
				}
				if (piece != " _______ ")
				{
					break;
				}
				x += dxRook[k];
				y += dyRook[k];
			}
		}

		int dyPawn[] = { 1, -1 };
		int dxPawn[] = { 1, 1 };

		for (int k = 0; k < 2; k++)
		{
			int x = king_x + dxPawn[k];
			int y = king_y + dyPawn[k];

			if (x >= 0 && x < m_rows && y >= 0 && y < m_columns)
			{
				string piece = m_matrix[x][y];
				if (piece == enemyPawn)
				{
					return true;
				}
			}
		}

		int dxKnight[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
		int dyKnight[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

		for (int k = 0; k < 8; k++)
		{
			int x = king_x + dxKnight[k];
			int y = king_y + dyKnight[k];

			if (x >= 0 && x < m_rows && y >= 0 && y < m_columns)
			{
				string piece = m_matrix[x][y];
				if (piece == enemyKnight)
				{
					return true;
				}
			}
		}

		return false;
	}
#pragma endregion Check
#pragma region CheckMate
	bool Chess_Board::isCheckmate(bool isWhiteTurn)
	{
		if (!Chess_Board::isCheck(isWhiteTurn))
		{
			return false; 
		}

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				if ((isWhiteTurn && m_matrix[i][j][2] == 'W') || (!isWhiteTurn && m_matrix[i][j][2] == 'B'))
				{
					for (int x = 0; x < m_rows; x++)
					{
						for (int y = 0; y < m_columns; y++)
						{
								string originalPiece = m_matrix[x][y];
								m_matrix[x][y] = m_matrix[i][j];
								m_matrix[i][j] = " _______ ";

								bool isStillCheck = isCheck(isWhiteTurn);

								m_matrix[i][j] = m_matrix[x][y];
								m_matrix[x][y] = originalPiece;

								if (!isStillCheck)
								{
									return false; 
								}
						}
					}
				}
			}
		}
		break;
		return true; 
	}

#pragma endregion
#pragma region Default initilizaion
	void Chess_Board::def_init() {
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
			m_matrix[7][i] = BChessmate_types[i];
			m_matrix[6][i] = "  B.Pawn ";
		}
	
	};//default chess board
	void Chess_Board::display() {
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
#pragma endregion display
#pragma region White Select and Move Figure
	void Chess_Board::Select_Figure() {
		getcoords();
		if (check_coords() == 0 || x >= m_rows || y >= m_columns) {
			cerr << "There wasn't a figure or the coordinates are illegal.\n";
			cout << "Something went wrong.\n";
			Select_Figure();
		}
	}

	void Chess_Board::Move_Figure() {
		Select_Figure();
		getmove();
		if (move_x >= m_rows || move_y >= m_columns) {
			cerr << "The coordinates are illegal.\n";
			cout << "Something went wrong.\n";
			Move_Figure();
		}
		if (move_x == x && move_y == y) {
			cerr << "Error: you didn't move the figure.\n";
			cout << "Something went wrong.\n";
			Move_Figure();
		}
		if (m_matrix[x][y] == " W.Rook ") {
			Rook::Move_Rook(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " W.Knight ") {
			Knight::Move_Knight(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " W.Bishop ") {
			Bishop::Move_Bishop(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " W.Queen ") {
			Queen::Move_Queen(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " W.King ") {
			King::Move_King(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == "  W.Pawn ") {
			Pawn::Move_Pawn(x, y, move_x, move_y, m_matrix);
		}
		else {
			cerr << "Something went wrong. Invalid figure selected.\n";
			throw abort;
		}
		cout << "If the move is skipped, it means you made an illegal move (Cheater).\n";
	}
#pragma endregion

#pragma region Black Select and Move
	void Chess_Board::Black_Select() {
		getcoords();
		if (check_coords() == 0 || x >= m_rows || y >= m_columns) {
			cerr << "There wasn't a figure or the coordinates are illegal.\n";
			cout << "Something went wrong.\n";
			Black_Select();
		}
	}

	void Chess_Board::Black_Move() {
		Black_Select();
		getmove();
		if (move_x >= m_rows || move_y >= m_columns) {
			cerr << "The coordinates are illegal.\n";
			cout << "Something went wrong.\n";
			Black_Move();
		}
		if (move_x == x && move_y == y) {
			cerr << "Error: you didn't move the figure.\n";
			cout << "Something went wrong.\n";
			Black_Move();
		}
		if (m_matrix[x][y] == " B.Rook ") {
			Rook::Move_Rook(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " B.Knight ") {
			Knight::Move_Knight(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " B.Bishop ") {
			Bishop::Move_Bishop(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " B.Queen ") {
			Queen::Move_Queen(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == " B.King ") {
			King::Move_King(x, y, move_x, move_y, m_matrix);
		}
		else if (m_matrix[x][y] == "  B.Pawn ") {
			Pawn::Move_Pawn(x, y, move_x, move_y, m_matrix);
		}
		else {
			cerr << "Something went wrong. Invalid figure selected.\n";
			throw abort;
		}
		cout << "If the move is skipped, it means you made an illegal move (Cheater).\n";
	}
#pragma endregion
	    void Chess_Board::Start() {
		def_init();
	    bool a;
		cout << "Hello To Chess Game Play as you want to play\n";
		cout << "Instructions:For first you must to input the\n";
		cout << "coordinats of chessman that you want to play\n";
		cout << "the secont you must be right input the coordinats\n";
		cout << "where you want to go your figure\n Nice game\n";
		while (true)
		{
			cout << "\n The White Move\n";
			display();
			Move_Figure();
			a = isCheckmate(1);
			system("cls");
			cout << "\nThe Black Move\n";
			display();
			Black_Move();
			a = isCheckmate(0);
			system("cls");
		}
		if (a) {
			cout << "You Win\nGOOD PLAYER\n";
		}
	}
		int main() 
		{
		Chess_Board* Game = new Chess_Board;
		Game -> Start();
		delete Game;
	    }
