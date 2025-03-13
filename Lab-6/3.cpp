#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    string name;
    string id;
public:
    Employee(string a, string b) : name(a), id(b) {}

    virtual void displaydetails() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
};

class IBiller {
public:
    virtual void generateBill() = 0;
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(string a, string b) : Employee(a, b) {}

    void takeOrder() override {
        cout << "Waiter " << name << " is taking the order." << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(string a, string b) : Employee(a, b) {}

    void prepareOrder() override {
        cout << "Chef " << name << " is preparing the order." << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(string a, string b) : Employee(a, b) {}

    void generateBill() override {
        cout << "Cashier " << name << " is generating the bill." << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(string a, string b) : Employee(a, b) {}

    void takeOrder() override {
        cout << "Manager " << name << " is taking the order." << endl;
    }

    void generateBill() override {
        cout << "Manager " << name << " is generating the bill." << endl;
    }
};

class Menu {
protected:
    string name;
    double price;
public:
    Menu(string n, double p) : name(n), price(p) {}

    virtual double calculateTotal() {
        return price;
    }
};

class FoodMenu : public Menu {
public:
    FoodMenu(string n, double p) : Menu(n, p) {}

    double calculateTotal() override {
        return price * 1.1; 
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(string n, double p) : Menu(n, p) {}

    double calculateTotal() override {
        return price * 1.2;
    }
};

int main() {
    Waiter waiter("John", "W001");
    Chef chef("Alice", "C001");
    Cashier cashier("Bob", "CH001");
    Manager manager("Eve", "M001");

    vector<IOrderTaker*> orderTakers = { &waiter, &manager };
    vector<IOrderPreparer*> orderPreparers = { &chef };
    vector<IBiller*> billers = { &cashier, &manager };

    for (auto orderTaker : orderTakers) {
        orderTaker->takeOrder();
    }

    for (auto orderPreparer : orderPreparers) {
        orderPreparer->prepareOrder();
    }

    for (auto biller : billers) {
        biller->generateBill();
    }

    FoodMenu foodMenu("Burger", 10.0);
    BeverageMenu beverageMenu("Soda", 2.0);

    cout << "Food Menu Total: " << foodMenu.calculateTotal() << endl;
    cout << "Beverage Menu Total: " << beverageMenu.calculateTotal() << endl;

    return 0;
}