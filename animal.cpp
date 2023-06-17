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
    Animal(const Animal&obj)
    {
         this->age = obj.age;
        this->speed = obj.speed;
         this->size = obj.size;
       this->animal_gender = obj.animal_gender;
        this->animal_move = obj.animal_move;
        this->has_heart = obj.has_heart;
        this->is_limited = obj.is_limited;
        this->animal_color = obj.animal_color;
        this->omnivorous = obj.omnivorous;
    }
    Animal& operator=(const Animal&obj)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
        }
        return *this;
    }
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
    Animal(){}
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
   virtual void swim() { cout << "im a swimming\n"; }
   virtual void sound() { cout << "im a sounding\n"; }
   virtual void flight() { cout << "im a flightingg\n"; }
};

class Fish : public Animal {
public:
    void swim() { cout << "swimming\n"; }
    virtual void dzuk() { cout << "im in a sevan\n"; }
    Fish(){}
    Fish(const Fish& obj)
    {
        this->age = obj.age;
        this->speed = obj.speed;
        this->size = obj.size;
        this->animal_gender = obj.animal_gender;
        this->animal_move = obj.animal_move;
        this->has_heart = obj.has_heart;
        this->is_limited = obj.is_limited;
        this->animal_color = obj.animal_color;
        this->omnivorous = obj.omnivorous;
        this->has_gill = obj.has_gill;
        this->deep_swimming = obj.deep_swimming;
        this->swim_ocean = obj.swim_ocean;
    }
    Fish& operator=(const Fish& obj)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
            this->has_gill = obj.has_gill;
            this->deep_swimming = obj.deep_swimming;
            this->swim_ocean = obj.swim_ocean;
        }
        return *this;
    }
    bool has_gill;
    bool deep_swimming;
    bool swim_ocean;
};

class Birds : public Animal {
public:
    void flying() { cout << "flighting\n"; }
    virtual void punch() { cout << "im a punching\n"; }
    Birds(){}
    Birds(const Birds& obj)
    {
        this->age = obj.age;
        this->speed = obj.speed;
        this->size = obj.size;
        this->animal_gender = obj.animal_gender;
        this->animal_move = obj.animal_move;
        this->has_heart = obj.has_heart;
        this->is_limited = obj.is_limited;
        this->animal_color = obj.animal_color;
        this->omnivorous = obj.omnivorous;
        this->has_nose = obj.has_nose;
        this->fly_high = obj.fly_high;
        this->can_flight = obj.can_flight;
    }
    Birds& operator=(const Birds& obj)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
            this->has_nose = obj.has_nose;
            this->fly_high = obj.fly_high;
            this->can_flight = obj.can_flight;
        }
        return *this;
    }
    bool has_nose;
    bool fly_high;
    bool can_flight;
};

class Mammal : public Animal {
public:
    void fighting() { cout << "Fighting"; }
    virtual void punch_keng() { cout << "im a punching like a kenguru\n"; }
    Mammal(){}
   Mammal(const Mammal& obj)
    {
       this->age = obj.age;
       this->speed = obj.speed;
       this->size = obj.size;
       this->animal_gender = obj.animal_gender;
       this->animal_move = obj.animal_move;
       this->has_heart = obj.has_heart;
       this->is_limited = obj.is_limited;
       this->animal_color = obj.animal_color;
       this->omnivorous = obj.omnivorous;
       this->has_nose = obj.has_nose;
       this-> laying_eggs = obj.laying_eggs;
    }
    Mammal& operator=(const Mammal& obj)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
            this->has_nose = obj.has_nose;
            this->laying_eggs = obj.laying_eggs;
        }
        return *this;
    }
    bool has_nose;
    bool laying_eggs;
};

class Ishxan : public Fish {
public:
    void dzuk() { cout << "in sevan)\n"; }
    Ishxan(){}
    Ishxan(const Ishxan& obj)
    {
        this->age = obj.age;
        this->speed = obj.speed;
        this->size = obj.size;
        this->animal_gender = obj.animal_gender;
        this->animal_move = obj.animal_move;
        this->has_heart = obj.has_heart;
        this->is_limited = obj.is_limited;
        this->animal_color = obj.animal_color;
        this->omnivorous = obj.omnivorous;
        this->ocean_swim = obj.ocean_swim;
        this->has_gill = obj.has_gill;
        this->deep_swimming = obj.deep_swimming;
        this->swim_ocean = obj.swim_ocean;
    }
    Ishxan& operator=(const Ishxan& obj)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
            this->ocean_swim = obj.ocean_swim;
            this->has_gill = obj.has_gill;
            this->deep_swimming = obj.deep_swimming;
            this->swim_ocean = obj.swim_ocean;
        }
        return *this;
    }
    bool ocean_swim;
};

class Arciv : public Birds {
public:
    Arciv() {}
    void punch() { cout << "punching\n"; }
    Arciv(const Arciv& obj)
    {
        this->age = obj.age;
        this->speed = obj.speed;
        this->size = obj.size;
        this->animal_gender = obj.animal_gender;
        this->animal_move = obj.animal_move;
        this->has_heart = obj.has_heart;
        this->is_limited = obj.is_limited;
        this->animal_color = obj.animal_color;
        this->omnivorous = obj.omnivorous;
        this->has_nose = obj.has_nose;
        this->fly_high = obj.fly_high;
        this->can_flight = obj.can_flight;
        this->sound = obj.sound;
        this->killing = obj.killing;
    }
    Arciv& operator=(const Arciv& obj)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
            this->has_nose = obj.has_nose;
            this->fly_high = obj.fly_high;
            this->can_flight = obj.can_flight;
            this->sound = obj.sound;
            this->killing = obj.killing;
        }
        return *this;
    }
    bool sound;
    bool killing;
};

class Kenguru : public Mammal {
public:
    Kenguru() {}
    void punch_keng() { cout << "punching like a kenguru"; }
    Kenguru(const Kenguru& obj)
    {
        this->age = obj.age;
        this->speed = obj.speed;
        this->size = obj.size;
        this->animal_gender = obj.animal_gender;
        this->animal_move = obj.animal_move;
        this->has_heart = obj.has_heart;
        this->is_limited = obj.is_limited;
        this->animal_color = obj.animal_color;
        this->omnivorous = obj.omnivorous;
        this->has_nose = obj.has_nose;
        this->foot_attack = obj.foot_attack;
        this->pouch = obj.pouch;
        this->laying_eggs = obj.laying_eggs;
    }
    Kenguru& operator=(const Kenguru& obj)
    {
        if (this != &obj)
        {
            this->foot_attack = obj.foot_attack;
            this->pouch = obj.pouch;
            this->age = obj.age;
            this->speed = obj.speed;
            this->size = obj.size;
            this->animal_gender = obj.animal_gender;
            this->animal_move = obj.animal_move;
            this->has_heart = obj.has_heart;
            this->is_limited = obj.is_limited;
            this->animal_color = obj.animal_color;
            this->omnivorous = obj.omnivorous;
            this->has_nose = obj.has_nose;
            this->laying_eggs = obj.laying_eggs;
        }
        return *this;
    }
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

    Ishxan Ishxanobj;
    Ishxanobj.setAge(2);
    Ishxanobj.setSpeed(5);
    Ishxanobj.setSize(10);
    Ishxanobj.animal_gender = unknown_gender;
    Ishxanobj.animal_move = swim;
    Ishxanobj.has_heart = true;
    Ishxanobj.is_limited = true;
    Ishxanobj.animal_color = blue;
    Ishxanobj.omnivorous = "No";
    Ishxanobj.has_gill = true;
    Ishxanobj.deep_swimming = true;
    Ishxanobj.swim_ocean = true;
    Ishxanobj.display();

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

