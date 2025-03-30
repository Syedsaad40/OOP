#include<iostream>
#include<string>
using namespace std;

class Shape{
protected:
    int x, y;
    string color;
    int borderthickness;
public:
    Shape(int a, int b, string c, int d): x(a), y(b), color(c), borderthickness(d) {}
    virtual void draw(){
        cout << "Drawing the desired shape at:" << x << "," << y << endl;
    }
    virtual void calculateArea(){
        cout << "Calculating the area for the desired shape" << endl;
    }
    virtual void calculatePerimeter(){
        cout << "Calculating the perimeter for the desired shape" << endl;
    }
};

class Circle: public Shape{
    double radius;
public:
    Circle(int a, int b, string c, int d, double e): Shape(a, b, c, d), radius(e) {}
    void draw() override {
        cout << "Drawing circle at:" << x << "," << y << endl;
    }
    void calculateArea() override {
        double b = 3.142 * radius * radius;
        cout << "The Area of the Circle is:" << b << endl;
    }
    void calculatePerimeter() override {
        double b = 2 * 3.142 * radius;
        cout << "The perimeter of the circle is:" << b << endl;
    }
};

class Rectangle: public Shape{
    int width, height, tlfx, tlfy;
public:
    Rectangle(int a, int b, string c, int d, int e, int f, int g, int h): Shape(a, b, c, d), width(e), height(f), tlfx(g), tlfy(h) {}
    void draw() override {
        cout << "Drawing rectangle at:" << x << "," << y << endl;
    }
    void calculateArea() override {
        int b = width * height;
        cout << "The Area of the rectangle is:" << b << endl;
    }
    void calculatePerimeter() override {
        double b = 2 * (width + height);
        cout << "The perimeter of the rectangle is:" << b << endl;
    }
    void gettopleftpos(){
        cout << "The top left position is:" << tlfx << "," << tlfy << endl;
    }
};

class Triangle: public Shape{
    int base, height;
public:
    Triangle(int a, int b, string c, int d, int e, int f): Shape(a, b, c, d), base(e), height(f) {}
    void draw() override {
        cout << "Drawing triangle at:" << x << "," << y << endl;
    }
    void calculateArea() override {
        double b = 0.5 * base * height;
        cout << "The Area of the triangle is:" << b << endl;
    }
    void calculatePerimeter() override {
        double h = base + height;
        double b = base + height + h;
        cout << "The perimeter of the triangle is:" << b << endl;
    }
};

class Polygon: public Shape{
    int numsides, sidelength;
public:
    Polygon(int a, int b, string c, int d, int e, int f): Shape(a, b, c, d), numsides(e), sidelength(f) {}
    void draw() override {
        cout << "Drawing polygon at:" << x << "," << y << endl;
    }
    void calculateArea() override {
        double b = numsides * sidelength * sidelength;
        cout << "The Area of the polygon is:" << b << endl;
    }
    void calculatePerimeter() override {
        double b = numsides * sidelength;
        cout << "The perimeter of the Polygon is:" << b << endl;
    }
};

int main(){
    Circle circle(10, 20, "red", 2, 5.0);
    Rectangle rect(30, 40, "blue", 1, 8, 6, 30, 40);
    Triangle tri(50, 60, "green", 3, 4, 5);
    Polygon poly(70, 80, "yellow", 1, 6, 2);

    Shape* shapes[] = {&circle, &rect, &tri, &poly};

    for(Shape* shape : shapes){
        shape->draw();
        shape->calculateArea();
        shape->calculatePerimeter();
        cout << endl;
    }

    rect.gettopleftpos();

    return 0;
}