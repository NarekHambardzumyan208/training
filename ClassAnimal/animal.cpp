#include <iostream>
#include <string>

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
protected:
    int age = 0;
    int speed = 0;
    int size = 0;
    std::string* types = new std::string[5];
public:
    gender animal_gender = unknown_gender;
    how_move animal_move = unknown;
    bool has_heart = false;
    bool is_limited = false;
    color animal_color = no;
    std::string omnivorous = "";

    Animal() {}

    Animal(int age, int speed, int size, gender animal_gender, how_move animal_move, bool has_heart,
        bool is_limited, color animal_color, std::string omnivorous)
        : age(age),
        speed(speed),
        size(size),
        animal_gender(animal_gender),
        animal_move(animal_move),
        has_heart(has_heart),
        is_limited(is_limited),
        animal_color(animal_color),
        omnivorous(omnivorous) {}
    Animal(Animal&& obj)
        : age(age),
        speed(speed),
        size(size),
        animal_gender(animal_gender),
        animal_move(animal_move),
        has_heart(has_heart),
        is_limited(is_limited),
        animal_color(animal_color),
        omnivorous(omnivorous), types(obj.types){
            obj.age = 0;
            obj.speed = 0;
            obj.size = 0;
            obj.animal_gender = unknown_gender;
            obj.animal_move = unknown;
            obj.has_heart = 0;
            obj.is_limited = 0;
            obj.animal_color = no;
            obj.omnivorous = "";
            obj.types = nullptr;
        }
    Animal& operator=(Animal&& obj) {
        if (this != &obj)
        {
            age = obj.age;
            speed = obj.speed;
            size = obj.size;
            animal_gender = obj.animal_gender;
            animal_move = obj.animal_move;
            has_heart = obj.has_heart;
            is_limited = obj.is_limited;
            animal_color = obj.animal_color;
            omnivorous = obj.omnivorous;
            delete[] types;
            types = obj.types;
            obj.age = 0;
            obj.speed = 0;
            obj.size = 0;
            obj.animal_gender = unknown_gender;
            obj.animal_move = unknown;
            obj.has_heart = 0;
            obj.is_limited = 0;
            obj.animal_color = no;
            obj.omnivorous = "";
            obj.types = nullptr;
        }
        return *this;
    }
    void setAge(int age) {
        if (age < 0) {
            std::cerr << "Age cannot be negative\n";
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
            std::cerr << "Size cannot be negative\n";
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
            std::cerr << "Speed cannot be negative\n";
        }
        else {
            this->speed = speed;
        }
    }

    int getSpeed() {
        return speed;
    }

    void display() {
        std::cout << "Age: " << age << std::endl;
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Gender: " << animal_gender << std::endl;
        std::cout << "Movement: " << animal_move << std::endl;
        std::cout << "Has Heart: " << (has_heart ? "Yes" : "No") << std::endl;
        std::cout << "Is Limited: " << (is_limited ? "Yes" : "No") << std::endl;
        std::cout << "Color: " << animal_color << std::endl;
        std::cout << "Omnivorous: " << omnivorous << std::endl;
    }

    virtual void swim() {
        std::cout << "Default swim" << std::endl;
    }

    virtual void sound() {
        std::cout << "Default sound" << std::endl;
    }

    virtual void flight() {
        std::cout << "Default flight" << std::endl;
    }
    virtual ~Animal() = 0;
};
Animal::~Animal() {};
class Fish : public Animal {
public:
    bool has_gill = false;
    bool deep_swimming = false;
    bool swim_ocean = false;
    Fish() {}

    Fish(int age, int speed, int size, bool has_gill, bool deep_swimming, bool swim_ocean)
        : has_gill(has_gill), deep_swimming(deep_swimming), swim_ocean(swim_ocean)
    {
        setAge(age);
        setSpeed(speed);
        setSize(size);
    }
    virtual ~Fish() = 0;
};
Fish::~Fish() {};
class Birds : public Animal {
public:
    bool has_nose = false;
    bool fly_high = false;
    bool can_flight = false;

    Birds() {}

    Birds(int age, int speed, int size, bool has_nose, bool fly_high, bool can_flight)
        : has_nose(has_nose), fly_high(fly_high), can_flight(can_flight)
    {
        setAge(age);
        setSpeed(speed);
        setSize(size);
    }
    virtual ~Birds() = 0;
};
Birds::~Birds(){}
class Mammal : public Animal {
public:
    bool has_nose = false;
    bool laying_eggs = false;

    Mammal() {}

    Mammal(int age, int speed, int size, bool has_nose, bool laying_eggs)
        : has_nose(has_nose), laying_eggs(laying_eggs)
    {
        setAge(age);
        setSpeed(speed);
        setSize(size);
    }
    virtual ~Mammal() = 0;
};
Mammal::~Mammal(){}
class Fugu : public Fish {
public:
    Fugu() {}

    Fugu(int age, int speed, int size, bool has_gill, bool deep_swimming, bool swim_ocean)
        : Fish(age, speed, size, has_gill, deep_swimming, swim_ocean) {}

    void swim() override {
        std::cout << "Swimming like a Fugu" << std::endl;
    }
};

class Eagle : public Birds {
public:
    Eagle() {}

    Eagle(int age, int speed, int size, bool has_nose, bool fly_high, bool can_flight)
        : Birds(age, speed, size, has_nose, fly_high, can_flight) {}

    void flight() override {
        std::cout << "Flying like an Eagle" << std::endl;
    }
};

class Kangaroo : public Mammal {
public:
    Kangaroo() {}

    Kangaroo(int age, int speed, int size, bool has_nose, bool laying_eggs)
        : Mammal(age, speed, size, has_nose, laying_eggs) {}

    void sound() override {
        std::cout << "Making sound like a Kangaroo" << std::endl;
    }
};

int main() {
    Fugu fish(2, 5, 10, true, true, false);
    fish.swim();

    Eagle bird(4, 20, 30, true, true, true);
    bird.flight();

    Kangaroo mammal(6, 15, 50, true, false);
    mammal.sound();
 
    return 0;
}

