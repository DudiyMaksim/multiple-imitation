#include <iostream>
using namespace std;

class Vehicle {
    string make;
    string model;
    int year;
public:
    Vehicle(string make, string model, int year) : make{ make }, model{ model }, year{ year } {};
    virtual void displayInfo() const {
        cout << "make: " << this->make << endl << "model: " << this->model << endl << "year: " << this->year << endl;
    }
    string getMake() const {
        return this->make;
    }
    string getModel() const {
        return this->model;
    }
    int getYear() const {
        return this->year;
    }
};

class Engine {
    int horsepower;
    double displacement;
public:
    Engine(int horsepower, double displacement) : horsepower{ horsepower }, displacement{ displacement } {};
    int getHorsepower() const {
        return this->horsepower;
    }
    double getDisplacement() const {
        return this->displacement;
    }
};

class Car :Vehicle, Engine {
    int numberOfDoors;
public:
    Car(string make, string model, int year, int horsepower, double displacement, int numberOfDoors) : Vehicle{ make, model, year }, Engine{ horsepower, displacement }, numberOfDoors{ numberOfDoors } {};
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "displacement: " << getDisplacement() << endl << "horsepower: " << getHorsepower() << endl << "numberOfDoors: " << numberOfDoors << endl;
    }
    int getNumberOfDoors() const {
        return this->numberOfDoors;
    }

};

class Truck : Vehicle, Engine {
    double loadCapacity;
public:
    Truck(string make, string model, int year, int horsepower, double displacement, double loadCapacity) : Vehicle{ make,model ,year }, Engine{ horsepower,displacement }, loadCapacity{ loadCapacity } {};
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "displacement: " << getDisplacement() << endl << "horsepower: " << getHorsepower() << endl << "loadCapacity: " << loadCapacity << endl;
    }
    double getLoadCapacity() const {
        return this->loadCapacity;
    }
};

class ElectricVehicle : Vehicle {
    double batteryCapacity;
    int range;
public:
    ElectricVehicle(string make, string model, int year, double batteryCapacity, int range) :Vehicle{ make,model,year }, batteryCapacity{ batteryCapacity }, range{ range } {};
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "batteryCapacity: " << batteryCapacity << endl << "range: " << range << endl;
    }
    double getBatteryCapacity() const {
        return this->batteryCapacity;
    }

    int getRange() const {
        return this->range;
    }
};

class ElectricCar : ElectricVehicle, Car {
public:
    ElectricCar(string make, string model, int year, int horsepower, double displacement, int numberOfDoors, double batteryCapacity, int range) : ElectricVehicle{ make,model,year,batteryCapacity,range }, Car{ make,model,year,horsepower,displacement,numberOfDoors } {};
    void displayInfo() const override {
        Car::displayInfo();
        cout << "batteryCapacity: " << getBatteryCapacity() << endl << "range: " << getRange() << endl;
    }
};
int main() {
    Car car("Toyota", "Corolla", 2024, 150, 1.8, 4);
    Truck truck("Volvo", "FH16", 2023, 600, 12.8, 15000);
    ElectricVehicle ev("Tesla", "Model S", 2024, 100.0, 600);
    ElectricCar eCar("Tesla", "Model 3", 2024, 283, 0.0, 4, 75.0, 500);

    cout << "Car Information:" << endl;
    car.displayInfo();
    cout << endl;

    cout << "Truck Information:" << endl;
    truck.displayInfo();
    cout << endl;

    cout << "Electric Vehicle Information:" << endl;
    ev.displayInfo();
    cout << endl;

    cout << "Electric Car Information:" << endl;
    eCar.displayInfo();
    cout << endl;

    return 0;
}