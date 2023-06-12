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
class pupil {
    int age;
    int schoolroom;
    int grade;
public:
    pupil() {
        cout << "The object of class pupil was created\n";
    }
    pupil& operator=(const pupil& obj)
    {
        if (this != &obj)
        {
            age = obj.age;
            schoolroom = obj.schoolroom;
            grade = obj.grade;
            grade = obj.grade;
            surname = obj.surname;
            name = obj.name;
            this->directing = obj.directing;
            this->gender = obj.gender;
            this->studing = obj.studing;
        }
        return *this;
    }
    pupil(const pupil& obj)
    {
            age = obj.age;
            schoolroom = obj.schoolroom;
            grade = obj.grade;
            grade = obj.grade;
            surname = obj.surname;
            name = obj.name;
            this->directing = obj.directing;
            this->gender = obj.gender;
            this->studing = obj.studing;
    }
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
    void setschoolroom(int schoolroom)
    {
        if (schoolroom < 1)
        {
            cerr << "The human in the scholl must be minimum in 1st schoolroom\n";
        }
        else {
            this->schoolroom = schoolroom;
        }
    }
    int getschoolroom()
    {
        return schoolroom;
    }
    directing directing;
    studing studing;
    gender gender;
    string name = " ";
    string surname = "dont had";
    void display() {
        cout << "\n name " << name << "\n surname " << surname << "\n age   " << getage();
        cout << "schoolroom " << getschoolroom() << "\nstuding " << this->studing << "\n gender" << this->gender;
        cout << "\ndirecting " << directing << "\ngrade " << getgrade() << endl;
}

};

int main()
{
    pupil Narek;
    Narek.name = "Narek";
    Narek.surname = "Hambardzumyan";
    Narek.setage(19);
    Narek.directing = physics;
    Narek.gender = boy;
    Narek.studing = good;
    Narek.setschoolroom(9);
    Narek.setgrade(9);
    Narek.display();
}
