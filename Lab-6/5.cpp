#include <iostream>
#include <string>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double a) : price(a) {}
};

class Car : public Vehicles {
protected:
    int capacity;
    int numdoor;
    string fueltype;
public:
    Car(double a, int b, int c, string d) : Vehicles(a), capacity(b), numdoor(c), fueltype(d) {}
};

class Motorcycle : public Vehicles {
protected:
    int numcylinder;
    int numgear;
    int numwheels;
public:
    Motorcycle(double a, int b, int c, int d) : Vehicles(a), numcylinder(b), numgear(c), numwheels(d) {}
};

class Audi : public Car {
    int model;
public:
    Audi(double a, int b, int c, string d, int e) : Car(a, b, c, d), model(e) {}

    void displaydetails() {
        cout << "Car details:" << endl;
        cout << "Price: " << price << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Num Of Doors: " << numdoor << endl;
        cout << "Fuel Type: " << fueltype << endl;
        cout << "Model: " << model << endl;
    }
};

class Yamaha : public Motorcycle {
    int make;
public:
    Yamaha(double a, int b, int c, int d, int e) : Motorcycle(a, b, c, d), make(e) {}

    void displaydetails() {
        cout << "Motorcycle details:" << endl;
        cout << "Price: " << price << endl;
        cout << "Num of cylinders: " << numcylinder << endl;
        cout << "Num of Gear: " << numgear << endl;
        cout << "Num of Wheels: " << numwheels << endl;
        cout << "Make: " << make << endl;
    }
};

int main() {
    Audi a(150000.26, 4, 4, "Diesel", 2020);
    Yamaha y(10000.56, 2, 5, 2, 2015);
    a.displaydetails();
    y.displaydetails();
    return 0;
}