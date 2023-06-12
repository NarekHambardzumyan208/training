#include <iostream>
#include <string>
#include <vector>

class Car; 

class Parking {
private:
    std::string name;
    std::vector<Car*> cars;

public:
    Parking(const std::string& parkingName) : name(parkingName) {}

    void addCar(Car* car) {
        cars.push_back(car);
    }

    void removeCar(Car* car) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (*it == car) {
                cars.erase(it);
                break;
            }
        }
    }

    void displayCars() {
        std::cout << "Cars parked at " << name << ":\n";
        for (const auto& car : cars) {
            std::cout << "- " << car->getLicensePlate() << "\n";
        }
        std::cout << "=============================\n";
    }
};

class Car {
private:
    std::string licensePlate;
    Parking* parking;

public:
    Car(const std::string& plate) : licensePlate(plate), parking(nullptr) {}

    void assignParking(Parking* p) {
        if (parking == nullptr) {
            parking = p;
            parking->addCar(this);
        }
        else {
            std::cout << "Car " << licensePlate << " is already assigned to a parking.\n";
        }
    }

    void removeParking() {
        if (parking != nullptr) {
            parking->removeCar(this);
            parking = nullptr;
        }
        else {
            std::cout << "Car " << licensePlate << " is not assigned to any parking.\n";
        }
    }

    std::string getLicensePlate() const {
        return licensePlate;
    }

    Parking* getParking() const {
        return parking;
    }
};

int main() {
    Parking parking("Parking Lot");
    Car car1("ABC123");
    Car car2("XYZ789");

    car1.assignParking(&parking);
    car2.assignParking(&parking);

    parking.displayCars();

    car1.removeParking();
    parking.displayCars();

    return 0;
}
 