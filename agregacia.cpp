#include <iostream>
using namespace std;
enum gender {
    boy,
    girl,
};
enum studing{
    good,
    bad,
    excellent,
    worst,
    normal,
};
enum directing {
    music,
    math,
    physics,
    physical_education,
    chess,
    hadnt_yet,
    history,
    languages,
    chemistry,
};
class person {
    int age;
    int classs;
    int grade;
public:
    void setgrade(int grade)
    {
        if (grade < 0)
        {
            cerr << "the grade cant  have a negative value\n";
        }
        else {
            this->grade = grade;
        }
    }
    int getgrade()
    {
        return grade;
    }
    void setage(int age)
    {
        if (age < 7)
        {
            cerr << "The human cant be a negative age or dont 7 age11\n";
        }
        else {
            this->age = age;
        }
    }
    int getage() 
    { 
    return age; 
    }
    void setclass(int classs)
    {
        if (classs < 1)
        {
            cerr << "The human in the scholl must be minimum in 1 class\n";
        }
        else {
            this->classs = classs;
        }
    }
    int getclass()
    {
        return classs;
    }
    directing directing;
    studing studying;
    gender genderr;
    string name = " ";
    string surname = "dont had";
    void display() {
        cout << "\n name " << name << "\n surname " << surname << "\n age   " << getage();
        cout << "class " << getclass() << "\nstuding " << studying << "\n gender" << this->genderr;
        cout << "\ndirecting " << directing << "\ngrade " << getgrade() << endl;
}

};

int main()
{
    person Narek;
    Narek.name = "Narek";
    Narek.surname = "Hambardzumyan";
    Narek.setage(19);
    Narek.directing = physics;
    Narek.genderr = boy;
    Narek.studying = good;
    Narek.setclass(9);
    Narek.setgrade(9);
    Narek.display();
}
