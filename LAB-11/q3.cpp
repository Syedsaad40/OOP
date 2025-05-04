#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds";
    }
};

template<typename T>
class SafeArray {
private:
    vector<T> data;
public:
    SafeArray(size_t size) : data(size) {}

    T& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(data.size())) {
            throw ArrayIndexOutOfBounds();
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(data.size())) {
            throw ArrayIndexOutOfBounds();
        }
        return data[index];
    }
};