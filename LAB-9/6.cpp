#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;
public:
    Car(string m, double p) : model(m), price(p) {}
    string getModel() { return model; }
    double getPrice() { return price; }
    virtual void setPrice(double p) = 0;
    virtual ~Car() {}
};

class Color : public Car {
    string color;
public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}
    void setPrice(double p) override { price = p; }
    void display() {
        cout << "Model: " << model << ", Price: $" << price 
             << ", Color: " << color << endl;
    }
};

class Company : public Car {
    string company;
public:
    Company(string m, double p, string c) : Car(m, p), company(c) {}
    void setPrice(double p) override { price = p * 0.9; } // 10% discount
    void display() {
        cout << "Model: " << model << ", Price: $" << price 
             << ", Company: " << company << endl;
    }
};

int main() {
    Color c("Sedan", 25000, "Red");
    Company co("SUV", 40000, "Toyota");
    
    c.display();
    co.display();
    
    c.setPrice(26000);
    co.setPrice(42000);
    
    c.display();
    co.display();
    
    return 0;
}