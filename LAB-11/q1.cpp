#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <any>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Bad type requested";
    }
};

class TypeSafeContainer {
private:
    any data;
public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    template<typename T>
    T get() const {
        if (!data.has_value()) {
            throw BadTypeException();
        }
        try {
            return any_cast<T>(data);
        } catch (const bad_any_cast&) {
            throw BadTypeException();
        }
    }
};