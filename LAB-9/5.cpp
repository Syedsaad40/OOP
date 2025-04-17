#include<iostream>
#include<string>
#include<vector>
using namespace std;

const double pie = 3.142;

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    int radius;
public:
    Circle(int a) : radius(a) {}
    double calculateArea() override {
        return pie * radius * radius;
    }
};

class Rectangle : public Shape {
    double length;
    double width;
public:
    Rectangle(double a, double b) : length(a), width(b) {}
    double calculateArea() override {
        return length * width;
    }
};

int main() {
    Circle c(10);
    Rectangle r(3.56, 4.67);
    
    Shape* shapes[] = {&c, &r};
    
    cout << "The area of the circle is: " << shapes[0]->calculateArea() << endl;
    cout << "The area of the rectangle is: " << shapes[1]->calculateArea() << endl;
    
    return 0;
}