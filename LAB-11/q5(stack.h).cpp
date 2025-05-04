#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow";
    }
};

template<typename T>
class Stack {
private:
    vector<T> data;
public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw StackUnderflowException();
        }
        data.pop_back();
    }

    T top() const {
        if (data.empty()) {
            throw StackUnderflowException();
        }
        return data.back();
    }
};