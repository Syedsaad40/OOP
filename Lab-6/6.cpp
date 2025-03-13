#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;
public:
    Student(string n, int r) : name(n), rollNo(r) {}

    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

class Marks : public Student {
protected:
    int marks[3];
public:
    Marks(string n, int r, int m1, int m2, int m3) : Student(n, r) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void displayMarks() {
        cout << "Marks in Course 1: " << marks[0] << endl;
        cout << "Marks in Course 2: " << marks[1] << endl;
        cout << "Marks in Course 3: " << marks[2] << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int r, int m1, int m2, int m3) : Marks(n, r, m1, m2, m3) {}

    void displayResult() {
        int total = marks[0] + marks[1] + marks[2];
        double average = total / 3.0;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    Result r("Ali", 101, 85, 90, 78);
    r.displayStudent();
    r.displayMarks();
    r.displayResult();
    return 0;
}