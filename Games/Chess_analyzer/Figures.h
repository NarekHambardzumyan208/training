#pragma once
#include <string>
enum class color {
	white,
	black
};
struct Figure {
	int x, y;
	color figure_color;
	std::string name;
};
class King :public Figure {
	King(color figure_color, int x, int y) : figure_color(figure_color), x(x), y(y);
	~King() override {};
};
class Queen : public Figure {
	Queen(color figure_color, int x, int y) : figure_color(figure_color), x(x), y(y);
	~Queen() override {};

};
class Bishop : public Figure {
	Bishop(color figure_color, int x, int y) : figure_color(figure_color), x(x), y(y);
	~Bishop() override {};

};
class Knight : public Figure {
	Knight(color figure_color, int x, int y) : figure_color(figure_color), x(x), y(y);
	~Knight() override {};

};