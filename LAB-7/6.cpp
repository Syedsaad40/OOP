#include <iostream>
#include <string>

class Person {
protected:
    int id;
public:
    void getData(int i) { id = i; }
    void displayData() { std::cout << "ID: " << id << std::endl; }
};

class Admin : public Person {
private:
    std::string name;
    double income;
public:
    void getData(int i, std::string n, double inc) {
        Person::getData(i);
        name = n;
        income = inc;
    }
    void displayData() {
        Person::displayData();
        std::cout << "Name: " << name << "\nIncome: " << income 
                  << "\nBonus: " << income * 0.05 * 12 << std::endl;
    }
};

class Accounts : public Person {
private:
    std::string name;
    double income;
public:
    void getData(int i, std::string n, double inc) {
        Person::getData(i);
        name = n;
        income = inc;
    }
    void displayData() {
        Person::displayData();
        std::cout << "Name: " << name << "\nIncome: " << income 
                  << "\nBonus: " << income * 0.05 * 12 << std::endl;
    }
};

int main() {
    Admin admin;
    admin.getData(101, "John Doe", 5000);
    admin.displayData();

    Accounts account;
    account.getData(102, "Jane Smith", 4500);
    account.displayData();
    return 0;
}