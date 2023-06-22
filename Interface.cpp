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
int main()
{
    Sportcar Ferrari;
    Ferrari.Start();
    Ferrari.Accelerate();
    Ferrari.Brake();
    Ferrari.Stop();
}