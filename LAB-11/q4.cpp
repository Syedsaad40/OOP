#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() const { return a * b; }
};

template<typename T>
class Derived : public Base<T> {
private:
    T c, d;
public:
    Derived(T w, T x, T y, T z) : Base<T>(w, x), c(y), d(z) {}
    T multiplyDerived() const { return c * d; }
    void printAll() const {
        cout << "Base product: " << this->multiplyBase() << endl;
        cout << "Derived product: " << multiplyDerived() << endl;
    }
};