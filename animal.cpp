#include <iostream>
#include <string>
using namespace std;

enum how_move {
    walk,
    crawl,
    fly,
    swim,
    unknown,
};

enum color {
    green,
    red,
    blue,
    orange,
    pink,
    yellow,
    purple,
};

enum gender {
    male,
    female,
    unknown_gender,
};

class Animal {
protected:
    int age = 0;
    int speed = 0;
    int size = 0;

public:
    gender animal_gender = unknown_gender;
    how_move animal_move = unknown;
    bool has_heart = false;
    bool is_limited = false;
    color animal_color;
    string omnivorous = "";

    void setAge(int age) {
        if (age < 0) {
            cerr << "Age cannot be negative\n";
        }
        else {
            this->age = age;
        }
    }

    int getAge() {
        return age;
    }

    void setSize(int size) {
        if (size < 0) {
            cerr << "Size cannot be negative\n";
        }
        else {
            this->size = size;
        }
    }

    int getSize() {
        return size;
    }

    void setSpeed(int speed) {
        if (speed < 1) {
            cerr << "Speed cannot be negative\n";
        }
        else {
            this->speed = speed;
        }
    }

    int getSpeed() {
        return speed;
    }

    void display() {
        cout << "Age: " << age << endl;
        cout << "Speed: " << speed << endl;
        cout << "Size: " << size << endl;
        cout << "Gender: " << animal_gender << endl;
        cout << "Movement: " << animal_move << endl;
        cout << "Has Heart: " << (has_heart ? "Yes" : "No") << endl;
        cout << "Is Limited: " << (is_limited ? "Yes" : "No") << endl;
        cout << "Color: " << animal_color << endl;
        cout << "Omnivorous: " << omnivorous << endl;
    }
};

int main()
{
    Animal obj;
    obj.setAge(5);
    obj.setSpeed(10);
    obj.setSize(20);
    obj.animal_gender = female;
    obj.animal_move = walk;
    obj.has_heart = true;
    obj.is_limited = false;
    obj.animal_color = red;
    obj.omnivorous = "Yes";

    obj.display();

    return 0;
}
