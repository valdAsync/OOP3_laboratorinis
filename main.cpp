#include <iostream>
#include <string>

using namespace std;

/* Base abstract class to represent vehicle data
 *
 */
class Vehicle {
private:
    string vehicleType;
    int rentPrice;
    string engineType;
    string color;

public:
    Vehicle(string vehicleType, int rentPrice, string engineType, string color) : vehicleType(vehicleType),
        rentPrice(rentPrice), engineType(engineType), color(color) {
    };

    virtual ~Vehicle() = default;

    virtual void printVehicleInformation() {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Rent Price: " << rentPrice << endl;
        cout << "Engine Type: " << engineType << endl;
        cout << "Color: " << color << endl;
    }

    virtual void startVehicle() {}
};

/* Derived class to represent car data
 *
 */
class Car : public Vehicle {
private:
    bool roof;
    int doors;

public:
    Car(string vehicleType = "Car", int rentPrice = 350, string engineType = "Petrol", string color = "Blue",
        bool roof = true,
        int doors = 2) : Vehicle(vehicleType, rentPrice, engineType, color), roof(roof), doors(doors) {
    };

    void printVehicleInformation() override {
        Vehicle::printVehicleInformation();
        cout << "Roof: " << roof << endl;
        cout << "Number of Doors: " << doors << endl;
    }

    void startVehicle() override {
        cout << "Starting the car with a key..." << endl;
    }
};

/* Derived class to represent motorcycle data
 *
 */
class Motorcycle : public Vehicle {
private:
    bool sidecar;

public:
    Motorcycle(string vehicleType = "Motorcycle", int rentPrice = 500, string engineType = "Electrical",
               string color = "Black",
               bool sidecar = false) : Vehicle(vehicleType, rentPrice, engineType, color), sidecar(sidecar) {
    };


    void printVehicleInformation() override {
        Vehicle::printVehicleInformation();
        cout << "Vehicle includes sidecar: " << sidecar << endl;
    }

    void startVehicle() override {
        cout << "Starting the motorcycle with a button..." << endl;
    }
};

int main() {
    Vehicle* vehiclePtr = nullptr;

    Car car("SUV", 350, "Petrol", "Blue", true, 4);
    vehiclePtr = &car;

    cout << "Details of Car:" << endl;
    vehiclePtr->printVehicleInformation();  // Calls Car's method
    vehiclePtr->startVehicle();             // Calls Car's method

    Motorcycle motorcycle("Dirt bike", 500, "Electrical", "Black", true);
    vehiclePtr = &motorcycle;

    cout << "\nDetails of Motorcycle:" << endl;
    vehiclePtr->printVehicleInformation();  // Calls Motorcycle's method
    vehiclePtr->startVehicle();             // Calls Motorcycle's method

    return 0;
}
