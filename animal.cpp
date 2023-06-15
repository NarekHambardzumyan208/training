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
public:
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

class Fish : public Animal {
public:
    bool has_gill;
    bool deep_swimming;
    bool swim_ocean;
};

class Birds : public Animal {
public:
    bool has_nose;
    bool fly_high;
    bool can_flight;
};

class Mammal : public Animal {
public:
    bool has_nose;
    bool laying_eggs;
};

class Ishxan : public Fish {
public:
    bool ocean_swim;
};

class Arciv : public Birds {
public:
    bool sound;
    bool killing;
};

class Kenguru : public Mammal {
public:
    bool foot_attack;
    bool pouch;
};

int main() {
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

    Fish fishObj;
    fishObj.setAge(2);
    fishObj.setSpeed(5);
    fishObj.setSize(10);
    fishObj.animal_gender = unknown_gender;
    fishObj.animal_move = swim;
    fishObj.has_heart = true;
    fishObj.is_limited = true;
    fishObj.animal_color = blue;
    fishObj.omnivorous = "No";
    fishObj.has_gill = true;
    fishObj.deep_swimming = true;
    fishObj.swim_ocean = true;
    fishObj.display();

    Birds birdsObj;
    birdsObj.setAge(3);
    birdsObj.setSpeed(15);
    birdsObj.setSize(8);
    birdsObj.animal_gender = male;
    birdsObj.animal_move = fly;
    birdsObj.has_heart = true;
    birdsObj.is_limited = false;
    birdsObj.animal_color = yellow;
    birdsObj.omnivorous = "Yes";
    birdsObj.has_nose = true;
    birdsObj.fly_high = true;
    birdsObj.can_flight = true;
    birdsObj.display();

    Mammal mammalObj;
    mammalObj.setAge(4);
    mammalObj.setSpeed(12);
    mammalObj.setSize(25);
    mammalObj.animal_gender = female;
    mammalObj.animal_move = walk;
    mammalObj.has_heart = true;
    mammalObj.is_limited = false;
    mammalObj.animal_color = purple;
    mammalObj.omnivorous = "No";
    mammalObj.has_nose = true;
    mammalObj.laying_eggs = false;
    mammalObj.display();

    Ishxan ishxanobj;
    ishxanobj.setAge(2);
    ishxanobj.setSpeed(5);
    ishxanobj.setSize(10);
    ishxanobj.animal_gender = unknown_gender;
    ishxanobj.animal_move = swim;
    ishxanobj.has_heart = true;
    ishxanobj.is_limited = true;
    ishxanobj.animal_color = blue;
    ishxanobj.omnivorous = "No";
    ishxanobj.has_gill = true;
    ishxanobj.deep_swimming = true;
    ishxanobj.swim_ocean = true;
    ishxanobj.display();

    Arciv arcivobj;
    arcivobj.setAge(3);
    arcivobj.setSpeed(15);
    arcivobj.setSize(8);
    arcivobj.animal_gender = male;
    arcivobj.animal_move = fly;
    arcivobj.has_heart = true;
    arcivobj.is_limited = false;
    arcivobj.animal_color = yellow;
    arcivobj.omnivorous = "Yes";
    arcivobj.has_nose = true;
    arcivobj.fly_high = true;
    arcivobj.can_flight = true;
    arcivobj.sound = true;
    arcivobj.killing = true;
    arcivobj.display();

    Kenguru kenguruobj;
    kenguruobj.setAge(4);
    kenguruobj.setSpeed(12);
    kenguruobj.setSize(25);
    kenguruobj.animal_gender = female;
    kenguruobj.animal_move = walk;
    kenguruobj.has_heart = true;
    kenguruobj.is_limited = false;
    kenguruobj.animal_color = yellow;
    kenguruobj.omnivorous = "No";
    kenguruobj.has_nose = true;
    kenguruobj.laying_eggs = false;
    kenguruobj.display();

    return 0;
}

