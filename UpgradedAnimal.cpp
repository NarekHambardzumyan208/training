#include <iostream>
class Animal {
protected:
    bool hungry = 0;
    int age = 0;
    std::string name = "";
public:
    Animal(){}
    Animal(bool hungry,std::string name,int age): hungry(hungry), name(name),age(age){}
    virtual void sound(){
        std::cout << "Animal sound\n";
    };
    Animal(int age) :age(age){}
    void operator()() {
        std::cout << "Im a Functor\n";
        std::cout << "This is the name of animal\n" << name;
    }
    bool operator<(const Animal&obj) {
        return age < obj.age;
    }
    bool operator>(const Animal& obj) {
        return age > obj.age;
    }
    bool operator==(const Animal& obj) {
        return age == obj.age;
    }
    Animal& operator++() {
        ++age;
        return*this;
    }
    Animal operator++(int) {
        Animal temp(*this);
        ++(*this);
        return temp;
    }
    void getage() {
        std::cout << "age\n" << age;
    };
};
class Mammal :virtual protected Animal {
public:
    Mammal() {}
    Mammal(std::string mammalname, bool hungry,int age) :Animal(hungry,mammalname,age){}
    void sound(){
        std::cout << "Mammal sound\n";
    }
};
class Fish :virtual protected Animal {
public:
    Fish(){}
    Fish(std::string FishName,bool hungry,int age) : Animal(hungry, FishName, age){}
    void sound() {
        std::cout << "Fish sound\n";
    }
};
class Frog :virtual protected Fish,virtual protected Mammal {
public:
    Frog(std::string FrogName, bool hungry, int age) : Animal(hungry,FrogName,age){}
    void sound() {
        std::cout << "grr,grr\n";
    }
    void getage() {
        std::cout << "age\n" << age;
    };
};
class Lion: protected Mammal {
public:
    Lion(std::string LionName,bool hungry,int age) : Mammal(LionName,hungry,age){}
    void sound() final
    { 
        std::cout << "Roarr!!!!\n";
    }
};
int main()
{
    Animal Kiosa(1, "Armenian", 5);
    Kiosa();
    Animal Rebato(1, "American", 25);
    std::cout << "Is Kiosa obj younger Rebato obj2\n" << (Kiosa < Rebato) << "\n";
    std::cout << "Is Kiosa obj older Rebato obj2\n" << (Kiosa > Rebato) << "\n";
    std::cout << "Is Kiosa obj = Rebato obj2 age\n" << (Kiosa == Rebato) << "\n";
    ++Rebato;
    Rebato.getage();
    Rebato++;
    Rebato.getage();
    Lion Armenian("Caucauss", 1, 15);
    Armenian.sound();
    Frog Caucauss("Armenian", 1, 25);
    Caucauss.sound();
    Caucauss.getage();
}
