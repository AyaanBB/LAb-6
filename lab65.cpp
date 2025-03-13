#include <iostream>
using namespace std;

class Vehicle {
protected:
    string make, model;
    int year;

public:
    Vehicle(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {}

    void displayVehicle() {
        cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year << endl;
    }
};

class Car : public Vehicle {
protected:
    int numDoors;
    float fuelEfficiency; 

public:
    Car(string mk, string mdl, int yr, int doors, float mpg)
        : Vehicle(mk, mdl, yr), numDoors(doors), fuelEfficiency(mpg) {}

    void displayCar() {
        displayVehicle();
        cout << "Doors: " << numDoors << "\nFuel Efficiency: " << fuelEfficiency << " MPG" << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife; 

public:
    ElectricCar(string mk, string mdl, int yr, int doors, int battery)
        : Car(mk, mdl, yr, doors, 0), batteryLife(battery) {} // Fuel efficiency is 0 for electric cars

    void displayElectricCar() {
        displayCar();
        cout << "Battery Life: " << batteryLife << " miles per charge" << endl;
    }
};

int main() {
    ElectricCar tesla("Tesla", "Model S", 2023, 4, 370);

    cout << "Electric Car Details: "<<endl;
    tesla.displayElectricCar();

    return 0;
}
