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
    int m_age = 0;
    int m_speed = 0;
    int m_size = 0;
    std::string* m_types = new std::string[5];
public:
    gender m_animal_gender = unknown_gender;
    how_move m_animal_move = unknown;
    bool m_has_hearth = false;
    bool m_is_limited = false;
    color m_animal_color = no;
    std::string m_omnivorous = "";

    Animal() {}

    Animal(int m_age, int m_speed, int m_size, gender m_animal_gender, how_move m_animal_move, bool m_has_hearth,
        bool m_is_limited, color m_animal_color, std::string m_omnivorous)
        : m_age(m_age),
        m_speed(m_speed),
        m_size(m_size),
        m_animal_gender(m_animal_gender),
        m_animal_move(m_animal_move),
        m_has_hearth(m_has_hearth),
        m_is_limited(m_is_limited),
        m_animal_color(m_animal_color),
        m_omnivorous(m_omnivorous) {}
    Animal(Animal&& obj)
        : m_age(m_age),
        m_speed(m_speed),
        m_size(m_size),
        m_animal_gender(m_animal_gender),
        m_animal_move(m_animal_move),
        m_has_hearth(m_has_hearth),
        m_is_limited(m_is_limited),
        m_animal_color(m_animal_color),
        m_omnivorous(m_omnivorous), m_types(obj.m_types) {
        obj.m_age = 0;
        obj.m_speed = 0;
        obj.m_size = 0;
        obj.m_animal_gender = unknown_gender;
        obj.m_animal_move = unknown;
        obj.m_has_hearth = 0;
        obj.m_is_limited = 0;
        obj.m_animal_color = no;
        obj.m_omnivorous = "";
        obj.m_types = nullptr;
    }
    Animal(const Animal& obj)
        : m_age(m_age),
        m_speed(m_speed),
        m_size(m_size),
        m_animal_gender(m_animal_gender),
        m_animal_move(m_animal_move),
        m_has_hearth(m_has_hearth),
        m_is_limited(m_is_limited),
        m_animal_color(m_animal_color),
        m_omnivorous(m_omnivorous) {
        for (int i = 0; i < 5; i++)
        {
            m_types[i] = obj.m_types[i];
        }
    }
    Animal& operator=(Animal&& obj) {
        if (this != &obj)
        {
            m_age = obj.m_age;
            m_speed = obj.m_speed;
            m_size = obj.m_size;
            m_animal_gender = obj.m_animal_gender;
            m_animal_move = obj.m_animal_move;
            m_has_hearth = obj.m_has_hearth;
            m_is_limited = obj.m_is_limited;
            m_animal_color = obj.m_animal_color;
            m_omnivorous = obj.m_omnivorous;
            delete[] m_types;
            m_types = obj.m_types;
            obj.m_age = 0;
            obj.m_speed = 0;
            obj.m_size = 0;
            obj.m_animal_gender = unknown_gender;
            obj.m_animal_move = unknown;
            obj.m_has_hearth = 0;
            obj.m_is_limited = 0;
            obj.m_animal_color = no;
            obj.m_omnivorous = "";
            obj.m_types = nullptr;
        }
        return *this;
    }
    void setm_age(int m_age) {
        if (m_age < 0) {
            std::cerr << "m_age cannot be negative\n";
        }
        else {
            this->m_age = m_age;
        }
    }

    int getm_age() {
        return m_age;
    }

    void setm_size(int m_size) {
        if (m_size < 0) {
            std::cerr << "m_size cannot be negative\n";
        }
        else {
            this->m_size = m_size;
        }
    }

    int getm_size() {
        return m_size;
    }

    void setm_speed(int m_speed) {
        if (m_speed < 1) {
            std::cerr << "m_speed cannot be negative\n";
        }
        else {
            this->m_speed = m_speed;
        }
    }

    int getm_speed() {
        return m_speed;
    }

    void display() {
        std::cout << "m_age: " << m_age << std::endl;
        std::cout << "m_speed: " << m_speed << std::endl;
        std::cout << "m_size: " << m_size << std::endl;
        std::cout << "Gender: " << m_animal_gender << std::endl;
        std::cout << "Movement: " << m_animal_move << std::endl;
        std::cout << "Has Heart: " << (m_has_hearth ? "Yes" : "No") << std::endl;
        std::cout << "Is Limited: " << (m_is_limited ? "Yes" : "No") << std::endl;
        std::cout << "Color: " << m_animal_color << std::endl;
        std::cout << "m_omnivorous: " << m_omnivorous << std::endl;
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
    bool m_has_gill = false;
    bool m_deep_swimming = false;
    bool m_swim_ocean = false;
    Fish() {}

    Fish(int m_age, int m_speed, int m_size, bool m_has_gill, bool m_deep_swimming, bool m_swim_ocean)
        : m_has_gill(m_has_gill), m_deep_swimming(m_deep_swimming), m_swim_ocean(m_swim_ocean)
    {
        setm_age(m_age);
        setm_speed(m_speed);
        setm_size(m_size);
    }
    virtual ~Fish() = 0;
};
Fish::~Fish() {};
class Birds : public Animal {
public:
    bool m_has_nose = false;
    bool m_fly_high = false;
    bool m_can_flight = false;

    Birds() {}

    Birds(int m_age, int m_speed, int m_size, bool m_has_nose, bool m_fly_high, bool m_can_flight)
        : m_has_nose(m_has_nose), m_fly_high(m_fly_high), m_can_flight(m_can_flight)
    {
        setm_age(m_age);
        setm_speed(m_speed);
        setm_size(m_size);
    }
    virtual ~Birds() = 0;
};
Birds::~Birds() {}
class Mammal : public Animal {
public:
    bool m_has_nose = false;
    bool m_laying_eggs = false;

    Mammal() {}

    Mammal(int m_age, int m_speed, int m_size, bool m_has_nose, bool m_laying_eggs)
        : m_has_nose(m_has_nose), m_laying_eggs(m_laying_eggs)
    {
        setm_age(m_age);
        setm_speed(m_speed);
        setm_size(m_size);
    }
    virtual ~Mammal() = 0;
};
Mammal::~Mammal() {}
class Fugu : public Fish {
public:
    Fugu() {}

    Fugu(int m_age, int m_speed, int m_size, bool m_has_gill, bool m_deep_swimming, bool m_swim_ocean)
        : Fish(m_age, m_speed, m_size, m_has_gill, m_deep_swimming, m_swim_ocean) {}

    void swim() override {
        std::cout << "Swimming like a Fugu" << std::endl;
    }
};

class Eagle : public Birds {
public:
    Eagle() {}

    Eagle(int m_age, int m_speed, int m_size, bool m_has_nose, bool m_fly_high, bool m_can_flight)
        : Birds(m_age, m_speed, m_size, m_has_nose, m_fly_high, m_can_flight) {}

    void flight() override {
        std::cout << "Flying like an Eagle" << std::endl;
    }
};

class Kangaroo : public Mammal {
public:
    Kangaroo() {}

    Kangaroo(int m_age, int m_speed, int m_size, bool m_has_nose, bool m_laying_eggs)
        : Mammal(m_age, m_speed, m_size, m_has_nose, m_laying_eggs) {}

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

