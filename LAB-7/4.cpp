#include <iostream>

class Number {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}
    Number operator--() {
        value *= 4;
        return *this;
    }
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }
    friend std::ostream& operator<<(std::ostream& os, const Number& n) {
        os << n.value;
        return os;
    }
};

int main() {
    Number n(16);
    std::cout << "Original: " << n << std::endl;
    std::cout << "Prefix --: " << --n << std::endl;
    std::cout << "Postfix --: " << n-- << std::endl;
    std::cout << "After: " << n << std::endl;
    return 0;
}