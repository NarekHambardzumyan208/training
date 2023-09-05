#include <iostream>
#include <string>
class Alpha {
    std::string name;
public:
    Alpha() { std::cout << __func__ << std::endl; }
    Alpha(std::string b) :name(b) { std::cout << "Parametrized\n"; }
    Alpha(const Alpha& obj) : name(obj.name) { std::cout << "call copy constructor\n" << std::endl; }
    void setname(std::string name) { this->name = name; }
    std::string getname() const { return name; }
    ~Alpha() { std::cout << __func__ << std::endl; }
};
void print(Alpha& obj) {//lvalue reference
    std::cout << "Lvalue reference \n";
    std::cout << obj.getname() << std::endl;
}
void printl(Alpha obj) {//lvalue
    std::cout << "Lvalue \n";
    std::cout << obj.getname() << std::endl;
}
void print(const Alpha& obj) {// const lvalue reference
    std::cout << "const lvalue reference \n";
    std::cout << obj.getname() << std::endl;
}
void print(Alpha&& obj)
{
    std::cout << "rvalue Reference\n";
    std::cout << obj.getname() << std::endl;
}//rvalue reference;
void print(const Alpha&& obj)
{
    std::cout << "const rvalue reference\n";
    std::cout << obj.getname() << std::endl;
}//const rvalue reference
int main()
{
    Alpha B("\n");
    const Alpha G("\n");
    Alpha&& S = Alpha("\n");
    const Alpha&& A = Alpha("\n");
    printl(B);//lvalue
    print(B);//lvalue ref
    print(G);//const lvalue
    print(S);//rvalue ref
    print(A);//const rvalue ref
    std::cout << "\n";
}
