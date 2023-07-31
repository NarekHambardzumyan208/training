#pragma once
#include <string>
class Figure {
public:
	static void Move_Rook(int x, int y, int move_x, int move_y, string** matrix);
	static void Move_Queen(int x, int y, int move_x, int move_y, string** matrix);
	static void Move_Pawn(int x, int y, int move_x, int move_y, string** matrix);
	static void Move_Knight(int x, int y, int move_x, int move_y, string** matrix);
	static void Move_King(int x, int y, int move_x, int move_y, string** matrix);
	static void Move_Bishop(int x, int y, int move_x, int move_y, string** matrix);
};