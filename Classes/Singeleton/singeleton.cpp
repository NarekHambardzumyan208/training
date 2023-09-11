#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    int getData() const {
        return data;
    }
    void setData(int value) {
        data = value;
    }
    private:
    Singleton() : data(0) {}
    int data;
};

int main() {
    Singleton& instance = Singleton::getInstance();
    instance.setData(42);
    int value = instance.getData();
    std::cout << "Data from Singleton: " << value << std::endl;
    return 0;
}
