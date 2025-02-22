#include<iostream>
#include<string>
using namespace std;

class Student {
    const int roll_no;
public:
    Student(int n) : roll_no(n) {}
    int getRollNo() const {
        return roll_no;
    }
};

int main() {
    int roll;
    cout << "Enter roll number: ";
    cin >> roll;
    Student s(roll);
    cout << "The constant roll no of the student is: " << s.getRollNo() << endl;

    return 0;
}