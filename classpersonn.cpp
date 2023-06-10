// classpersonn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class person {
    int salary;
    int age; 
    string haswork;
public:
    void set_work(string haswork)
    {
        if (haswork != "yes" || haswork != "No")
            cerr << "The haswork must be yes or no\n";
        else
            this->haswork = haswork;
    }
    string getwork(){
        return haswork;
    }
    void setsalary(int salary)
    {
        if (salary < 0)
        {
            cerr << "salary must be a bigger than zero\n";
        }
        else {
            this->salary = salary;
        }
    }
    int getsalary(){
        return salary;
    }
    void setage(int age)
    {
        if (age < 18)
        {
            cerr << "The human cant be a negative age or dont 18 age11\n";
        }
        else {
            this->age = age;
        }
    }
    int getage() { return age; }
    bool credithistory = 0;
    bool hascredit = 0;
    bool regedinourbank = 0;
    bool hascredcard = false;
    string name = " ";
    string surname = "dont had";
    string pasportnum = "dont had";
    void display() {
        cout << "\ncredit history " << credithistory << "\n has credit " << hascredit << "\n has credit card " << hascredcard << "\n registered in our bank " << regedinourbank << "\n name " << name << "\n surname " << surname << "\n pasportnum " << "\n age   " << getage() << "\n salary " << getsalary() << "\n has work  " << getwork();
    }
};
int main()
{
    person Narek;
    Narek.credithistory = 0;
    Narek.hascredcard = 1;
    Narek.hascredit = 0;
    Narek.name = "Narek";
    Narek.surname = "Hambardzumyan";
    Narek.pasportnum = " AN675983 ";
    Narek.regedinourbank = 1;
    Narek.setage(19);
    Narek.setsalary(500000);
    Narek.set_work("yes");
    Narek.display();
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
