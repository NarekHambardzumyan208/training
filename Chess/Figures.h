#pragma once
#include <string>
class Rook
{
public:
	static void Move_Rook(int x,int y,int move_x,int move_y,string** matrix);
};
class Queen
{
public:
	static void Move_Queen(int x, int y, int move_x, int move_y, string** matrix);
};
class Pawn
{
public:
	static void Move_Pawn(int x, int y, int move_x, int move_y, string** matrix);
};
class Knight
{
public:
	static void Move_Knight(int x, int y, int move_x, int move_y, string** matrix);
};
class King
{
public:
	static void Move_King(int x, int y, int move_x, int move_y, string** matrix);
};
class Bishop
{
public:
	static void Move_Bishop(int x, int y, int move_x, int move_y, string** matrix);
};




