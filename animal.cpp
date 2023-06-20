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
    no,
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
    color animal_color = no;
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
    Animal(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
    
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
   virtual void swim() { cout << "im a swimming\n"; }
   Animal(){}
   virtual void sound() { cout << "im a sounding\n"; }
   virtual void flight() { cout << "im a flightingg\n"; }
};

class Fish : public Animal {
public:
    void swim() override final { cout << "swimming\n"; } 
    virtual void dzuk() { cout << "im in a sevan\n"; }
    Fish(){}
    Fish(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous,bool has_gill,bool deep_swimming,bool swim_inocean) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
        this->has_gill = has_gill;
        this->deep_swimming = deep_swimming;
        this->swim_ocean = swim_inocean;
    }
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
    bool has_gill =0;
    bool deep_swimming = 0;
    bool swim_ocean = 0;
};

class Birds : public Animal {
public:
    void flight() override final{ cout << "flighting\n"; } 
    virtual void punch() { cout << "im a punching\n"; }
    Birds(){}
    Birds(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous,bool has_nose,bool fly_high,bool can_flight) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
        this->has_nose = has_nose;
        this->can_flight = can_flight;
        this->fly_high = fly_high;
    }
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
    bool has_nose = 0;
    bool fly_high  = 0;
    bool can_flight = 0;
};

class Mammal : public Animal {
public:
    void sound() override final{ cout << "screaming\n"; }
    virtual void punch_keng() { cout << "im a punching like a kenguru\n"; }
    Mammal(){}
    Mammal(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous,bool has_nose,bool laying_eggs) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
        this->has_nose = has_nose;
        this->laying_eggs = laying_eggs;
    }
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
    bool has_nose = 0;
    bool laying_eggs = 0;
};

class Ishxan : public Fish {
public:
    void dzuk() override final { cout << "in sevan)\n"; }
    void dead() { cout << "brbrbrbr\n"; }
    Ishxan(){}
    Ishxan(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous, bool has_gill, bool deep_swimming, bool swim_inocean) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
        this->has_gill = has_gill;
        this->deep_swimming = deep_swimming;
        this->swim_ocean = swim_inocean;
    }
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
            this->has_gill = obj.has_gill;
            this->deep_swimming = obj.deep_swimming;
            this->swim_ocean = obj.swim_ocean;
        }
        return *this;
    }
};

class Eagle : public Birds {
public:
    Eagle() {}
    Eagle(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous, bool has_nose, bool fly_high, bool can_flight,bool sound, bool killing) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
        this->has_nose = has_nose;
        this->can_flight = can_flight;
        this->fly_high = fly_high;
        this->sound = sound;
        this->killing = killing;
    }
    void punch() override final{ cout << "punching\n"; }
   virtual void flighting() { cout << "crrr crrr crrrr\n"; }
    Eagle(const Eagle& obj)
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
        this->can_flight = obj.can_flight;
        this->sound = obj.sound;
        this->killing = obj.killing;
    }
    Eagle& operator=(const Eagle& obj)
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
            this->can_flight = obj.can_flight;
            this->sound = obj.sound;
            this->killing = obj.killing;
        }
        return *this;
    }
    bool sound = 0;
    bool killing = 0;
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
    Kenguru(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart, bool is_limited, color animal_color, string omnivorous, bool has_nose, bool laying_eggs,bool foot_attack,bool pouch) {
        setAge(age);
        setSpeed(speed);
        setSize(size);
        this->animal_gender = animal_gender;
        this->animal_color = animal_color;
        this->animal_move = animal_move;
        this->has_heart = has_heart;
        this->is_limited = is_limited;
        this->omnivorous = omnivorous;
        this->has_nose = has_nose;
        this->laying_eggs = laying_eggs;
        this->pouch = pouch;
        this->foot_attack = foot_attack;
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
    bool foot_attack = 0;
    bool pouch = 0;
};

int main() {
    Animal** obj = new Animal * [7];

    obj[0] = new Animal(5, 10, 20, female, walk, 1, 0, red, "Yes");
    obj[1] = new Fish(2, 5, 10, male, swim, 1, 1, blue, "No", 1, 0, 1);
    obj[2] = new Birds(2, 5, 10, female, fly, 1, 1, blue, "Yes", 1, 0,1);
    obj[3] = new Mammal(4,12,25,female,walk,true,false,purple,"No",true,false);
    obj[4] = new Ishxan(2,5,10,unknown_gender,swim,true,true,blue,"No",true,true,true);
    obj[5] = new Eagle(3,15,8,male,fly,1,0,yellow,"Yes",1,1,1,1,true);
    obj[6] = new Kenguru(4,12,25,female,walk,true,false,yellow,"No",true,false,true,true);
    obj[1]->swim();
    obj[2]->sound();
    obj[3]->flight();
    obj[0]->display();
    obj[1]->display();
    obj[2]->display();
    obj[3]->display();
    obj[4]->display();
    obj[5]->display();
    obj[6]->display();
    return 0;
}

