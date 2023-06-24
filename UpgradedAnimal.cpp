// UpgradedAnimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Animal {
protected:
    bool hungry = 0;
    std::string name;
public:
    Animal(bool hungry,std::string name): hungry(hungry), name(name){}
    virtual void sound(){
        std::cout << "Animal sound\n";
    };
};
class Mammal : protected Animal {
public:
    Mammal(std::string mammalname, bool hungry) : Animal(hungry, mammalname){}
    void sound(){
        std::cout << "Mammal sound\n";
    }
};
class Lion: protected Mammal {
public:
    Lion(std::string LionName,bool hungry) : Mammal(LionName,hungry){}
    void sound() final
    { 
        std::cout << "Roarr!!!!\n";
    }
};
int main()
{
    Lion Armenian("Caucauss", 1);
    Armenian.sound();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
