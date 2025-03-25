#include <iostream>

class Shape {
private:
    double area;
public:
    Shape(double a = 0) : area(a) {}
    double Area() const { return area; }
    Shape operator+(const Shape& other) {
        return Shape(area + other.area);
    }
    friend std::ostream& operator<<(std::ostream& os, const Shape& s) {
        os << s.area;
        return os;
    }
};

int main() {
    Shape shape1(10.5), shape2(20.3);
    Shape total = shape1 + shape2;
    std::cout << "Total area: " << total << std::endl;
    return 0;
}