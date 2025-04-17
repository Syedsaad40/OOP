#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    double salary;
public:
    virtual void getdata() = 0;
    virtual void display() = 0;
    virtual double bonus() = 0;
    virtual ~Person() {}
};

class Admin : public Person {
public:
    void getdata() override {
        cout << "Enter admin name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void display() override {
        cout << "Admin: " << name << ", Salary: " << salary << endl;
    }
    double bonus() override { return salary * 0.15; }
};

class Account : public Person {
public:
    void getdata() override {
        cout << "Enter accountant name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void display() override {
        cout << "Accountant: " << name << ", Salary: " << salary << endl;
    }
    double bonus() override { return salary * 0.10; }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata();
    }
    void display() override {
        Admin::display();
    }
    double bonus() override { return Admin::bonus() + Account::bonus(); }
};

int main() {
    Person* p = new Master();
    p->getdata();
    p->display();
    cout << "Bonus: " << p->bonus() << endl;
    delete p;
    return 0;
}