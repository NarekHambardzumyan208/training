#include <iostream>
class Car {
public:
    virtual void Brake() = 0;
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Accelerate() = 0;
};
class Sportcar : private Car {
public:
    void Brake() override {
        std::cout << "Im Breaking\n";
        Stop_Lights = 1;
    }
    void Start() override {
        std::cout << "The engine has started\n";
        Motor = 1;
        Carb = 1;
    }
    void Stop() override {
        std::cout << "The engine has stoped\n";
        Motor = 0;
        Carb = 0;
    }
    void Accelerate() override{
        std::cout << "Im accelerating\n";
        Carb = 1;//carburator is open
    }
    bool Stop_Lights = 0;
    bool Motor = 0;
    bool Carb = 0;
};
class BMW : protected Sportcar
{
    int speed;
public:
    void setSpeed(int speed) {
        if (speed < 0)
        {
            cout << "The speed cant be a negative\n";
        }
        else {
            this->speed = speed;
        }
    }
    void getSpeed() {
        return speed;
    }
    bool Electro_Motor = 0;
    bool Intern_comb_engine = 0;
    //the our bmw is hybrid car
    void Brake()  override{
        std::cout << "Im Braking and bringing my energy back\n";
        Stop_Lights = 1;
        Electro_Motor = 0;
    }
    void StartCombeng() {
        std::cout << "Im starting my internal combustion engine\n";
        Intern_comb_engine = 1;
    }
    void Accelerate(int speed) override{
        if (speed > 50) {
            StartCombeng();
        }
        Carb = 1;
    }
    void Stop() override {
        std::cout << "The motors are stoped\n"; 
             Electro_Motor = 0;
         Intern_comb_engine = 0;
    }
    void Start() override {
        std::cout << "Im starting and my electrical engine too\n";
        Electro_Motor = 1;
    }
   
};
int main()
{
    BMW I7;
    I7.Start();
    I7.setSpeed(100);
    I7.Accelerate();
    I7.Brake();
    I7.Stop();
}