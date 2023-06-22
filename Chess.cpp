// Chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class base_chessman {
private:
    std::string Color = "unknown";
    std::string Name = "unknown";
public:
    virtual void move() = 0;
    void setName(std::string Name){
        if (Name != "Knight" || Name != "Queen" || Name != "King" || Name != "Rook" || Name != "Bishop")
        {
            std::cerr << "The Name of chessman dont correct\n";
        }
        else 
        {
            this->Name = Name;
        }
    }
    void setColor(std::string Color) {
        if (Color != "Black" || Color != "White")
        {
            std::cerr << "The Name of color dont correct\n";
        }
        else
        {
            this->Color = Color;
        }
    }
    std::string getName() 
    {
        return Name;
    }
    std::string getColor()
    {
        return Color;
    }
};
class King : base_chessman
{
public:
    void move()
    {
        std::cout << "I moving any one square\n";
    }
    void getname()
    {
        std::cout << "King\n";
    }
    bool fork = 0;
    bool check = 0;
    bool checkmate = 0;
};
class Knight : base_chessman
{
public:
    void move()
    {
        std::cout << "I can move any square,that not in my rank or diagonal\n";
    }
    void getname()
    {
        std::cout << "Knight\n";
    }
};
class Pawn : base_chessman
{
public:
    void move() {
        std::cout << "I can move one square diagonal or forward";
    }
    void getname() {
        std::cout << "Pawn\n";
    }
};
class Rook  : base_chessman{
public:
    void move() {
        std::cout << "I can move any square forward or along\n";
    }
    void getname() {
        std::cout << "Rook\n";
    }
};
class Bishop : base_chessman {
public:
    void move() {
        std::cout << "I can move any square diagonally\n";
    }
    void getname() {
        std::cout << "Bishop\n";
    }
};
class Queen : base_chessman {
public:
    void move() {
        std::cout << "I can move any square diagonally,forward,or along\n";
    }
    void getname() {
        std::cout << "Queen\n";
    }
};
int main()
{
    King king;
    king.getname();
    king.move();
    Queen queen;
    queen.getname();
    queen.move();
    Rook rook;
    rook.getname();
    rook.move();
    Bishop bishop;
    bishop.getname();
    bishop.move();
    Knight knight;
    knight.getname();
    knight.move();
    Pawn pawn;
    pawn.getname();
    pawn.move();
}