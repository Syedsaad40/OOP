#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TypeSafeContainer.h"
#include "Matrix.h"
#include "SafeArray.h"
#include "DerivedTemplate.h"
#include "Stack.h"

using namespace std;

int main() {
    TypeSafeContainer container;
    container.store<int>(42);
    try {
        cout << container.get<int>() << endl;
        container.get<string>();
    } catch (const BadTypeException& e) {
        cout << "Caught: " << e.what() << endl;
    }

    Matrix<int> m1(2, 2);
    Matrix<int> m2(2, 2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    m2[0][0] = 5; m2[0][1] = 6;
    m2[1][0] = 7; m2[1][1] = 8;

    try {
        auto m3 = m1 + m2;
        auto m4 = m1 * m2;
    } catch (const DimensionMismatchException& e) {
        cout << "Caught: " << e.what() << endl;
    }

    SafeArray<int> arr(5);
    try {
        arr[0] = 10;
        arr[4] = 20;
        arr[5] = 30;
    } catch (const ArrayIndexOutOfBounds& e) {
        cout << "Caught: " << e.what() << endl;
    }

    Derived<int> d(2, 3, 4, 5);
    d.printAll();

    Stack<int> stack;
    try {
        stack.push(1);
        stack.push(2);
        cout << stack.top() << endl;
        stack.pop();
        stack.pop();
        stack.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}