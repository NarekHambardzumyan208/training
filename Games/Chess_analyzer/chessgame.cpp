#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
const int m_rows = 8;
const int m_columns = 8;
enum class color {
	white,
	black,
	none
};
class King {
public:
	int x = 0, y = 0;
	color figure_color = color::none;
	std::string name = "none";
	King() {};
	King(std::string name,color figure_color, int x, int y) : name(name),figure_color(figure_color), x(x), y(y) {};
	~King()  {};
};
class Queen {
public:
	int x = 0, y = 0;
	color figure_color =  color::none;
	std::string name = "none";
	Queen() {};
	Queen(std::string name,color figure_color, int x, int y) : name(name), figure_color(figure_color), x(x), y(y) {};
	~Queen()  {};

};
class Bishop {
public:
	int x = 0, y = 0;
	color figure_color = color::none;
	std::string name = "none";
	Bishop() {};
	Bishop(std::string name,color figure_color, int x, int y) : name(name),figure_color(figure_color), x(x), y(y) {};
	~Bishop()  {};

};
class Knight{
public:
	int x = 0, y = 0;
	color figure_color = color::none;
	std::string name = "none";
	Knight() {};
	Knight(std::string name, color figure_color, int x, int y) :name(name) , figure_color(figure_color), x(x), y(y) {};
	~Knight()  {};
};
class Chess_Board {
	std::string** Board = new std::string * [8];
	std::vector<std::string> Coordinates{ "WK77","BK56","BQ75","BB67","BN55" };
	King* White_King = new King(" W.King ",color::white, AsciiToCoords(Coordinates[0][2]), AsciiToCoords (Coordinates[0][3]));
	King* Black_King = new King(" B.King ", color::black, AsciiToCoords (Coordinates[1][2]), AsciiToCoords (Coordinates[1][3]));
	Queen* Black_Queen = new Queen(" B.Queen ", color::black, AsciiToCoords (Coordinates[2][2]), AsciiToCoords (Coordinates[2][3]));
	Bishop* Black_Bishop = new Bishop(" B.Bishop ", color::black, AsciiToCoords (Coordinates[3][2]), AsciiToCoords (Coordinates[3][3]));
	Knight* Black_Knight = new Knight(" B.Knight ", color::black, AsciiToCoords (Coordinates[4][2]), AsciiToCoords (Coordinates[4][3]));
public:
	int AsciiToCoords(int a)
	{
		switch (a)
		{
		case 48:
			return 0;
		case 49:
			return 1;
		case 50:
			return 2;
		case 51:
			return 3;
		case 52:
			return 4;
		case 53:
			return 5;
		case 54:
			return 6;
		case 55:
			return 7;
		case 56:
			return 8;
		case 57:
			return 9;
		default:
			return 0;


		}
	}
	void Check_Coords()
	{
		try
		{
			std::string err = "OUT OF RANGE";
			for (int i = 0;i < 5;i++)
			{
				if (AsciiToCoords(Coordinates[i][2]) >= m_rows || AsciiToCoords(Coordinates[i][3]) >= m_columns || AsciiToCoords(Coordinates[i][2]) < 0 || AsciiToCoords(Coordinates[i][3]) < 0)
				{
					throw  err;
				}
			}
		}
		catch (const std::string& err)
		{
			std::cout << err << std::endl;
		}
		catch (...)
		{
			std::cout << "Unexpected error" << std::endl;
		}
	}
	Chess_Board()
	{
		for (size_t i = 0; i < 8; i++)
		{
			Board[i] = new std::string[8];
			for (int j = 0; j < 8; j++)
			{
				Board[i][j] = " _______ ";
			}
		}
		Check_Coords();
		
			int x = White_King->x, y = White_King->y;
			Board[x][y] = White_King->name;
			x = Black_King->x, y = Black_King->y;
			Board[x][y] = Black_King->name;
			x = Black_Bishop->x, y = Black_Bishop->y;
			Board[x][y] = Black_Bishop->name;
			x = Black_Knight->x, y = Black_Knight->y;
			Board[x][y] = Black_Knight->name;
			x = Black_Queen->x, y = Black_Queen->y;
			Board[x][y] = Black_Queen->name;
 	}
	void display()
	{
		for (int i = 0; i < 8; i++)
		{
			std::cout << "[";
			for (int j = 0; j < 8;j++)
			{
				std::cout << Board[i][j] << "|";
			}
			std::cout << "]" << std::endl;
		}
	}
	bool isCheck(int x, int y) {
		int dxKnight[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
		int dyKnight[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

		for (int k = 0; k < 8; k++) {
			int dx = x + dxKnight[k];
			int dy = y + dyKnight[k];

			if (dx >= 0 && dx < m_rows && dy >= 0 && dy < m_columns) {
				std::string piece = Board[dx][dy];
				if (piece == Black_Knight->name) {
					return true;
				}
			}
		}

		int dxRook[] = { 0, 0, 1, -1 };
		int dyRook[] = { 1, -1, 0, 0 };

		for (int k = 0; k < 4; k++) {
			int dx = x + dxRook[k];
			int dy = y + dyRook[k];

			while (dx >= 0 && dx < m_rows && dy >= 0 && dy < m_columns) {
				std::string piece = Board[dx][dy];
				if (piece != " _______ " && (piece == Black_Queen->name)) {
					return true;
				}
				if (piece != " _______ ") {
					break;
				}
				dx += dxRook[k];
				dy += dyRook[k];
			}
		}

		int dxBishop[] = { -1, 1, 1, -1 };
		int dyBishop[] = { -1, -1, 1, 1 };

		for (int k = 0; k < 4; k++) {
			int dx = x + dxBishop[k];
			int dy = y + dyBishop[k];

			while (dx >= 0 && dx < m_rows && dy >= 0 && dy < m_columns) {
				std::string piece = Board[dx][dy];
				if (piece != " _______ " && (piece == Black_Bishop->name || piece == Black_Queen->name)) {
					return true;
				}
				if (piece != " _______ ") {
					break;
				}
				dx += dxBishop[k];
				dy += dyBishop[k];
			}
		}

		return false;
	}

	bool IsCheckMate() {
		int whiteKingX = White_King->x;
		int whiteKingY = White_King->y;
		if (!isCheck(whiteKingX, whiteKingY)) {
			return false;
		}
		int dxKing[] = { 1, -1, -1, 1, 1, -1, 0, 0 };
		int dyKing[] = { 1, -1, 1, -1, 0, 0, 1, -1 };
		for (int i = 0; i < 8; i++) {
			int newX = whiteKingX + dxKing[i];
			int newY = whiteKingY + dyKing[i];
			if (newX >= 0 && newX < m_rows && newY >= 0 && newY < m_columns) {
				if (!isCheck(newX, newY) && isValidMove(whiteKingX, whiteKingY, newX, newY)) {
					return false;  
				}
			}
		}
		return true;
	}

	bool isValidMove(int currentX, int currentY, int newX, int newY) {
		int dx = abs(newX - currentX);
		int dy = abs(newY - currentY);
		if (dx <= 1 && dy <= 1) {
			return true;
		}
		return false;
	}

	void start()
	{
		display();
		if (IsCheckMate())
		{
			std::cout << "White King Has mate\n";
		}
	}
	~Chess_Board() {
		for (int i = 0; i < 8; i++)
		{
			delete[] Board[i];
		}
		delete[] Board;
		delete White_King;
		delete Black_King;
		delete Black_Bishop;
		delete Black_Knight;
		delete Black_Queen;
	}
};
int main()
{
	Chess_Board* First = new Chess_Board;
	First->start();
	delete First;
	getchar();
}

