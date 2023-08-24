#pragma once 
#include "Figures.h"
#include <string>
class Chess_Board {
	std::string Board;
	const int rows;
	const int columns;
	King White_King;
	King Black_King;
	Bishop Black_Bishop;
	Bishop White_Bishop;
	Knight Black_Knight;
	Knight White_Knight;
	Queen Black_Queen;
	Queen White_Queen;
public:
	void display();
	bool Check_Mate(int x, int y);
};