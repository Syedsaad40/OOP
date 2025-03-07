#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountnumber;
    double balance;

public:
    BankAccount(string s) : accountnumber(s), balance(0) {}

    virtual double deposit(double s) {
        balance += s;
        return balance;
    }

    virtual double withdraw(double s) {
        if (balance >= s) {
            balance -= s;
            return balance;
        } else {
            cout << "Insufficient funds." << endl;
            return balance;
        }
    }

    string get_accnum() const {
        return accountnumber;
    }

    double get_balance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
    static double interestRate;

public:
    SavingsAccount(string s) : BankAccount(s) {}

    double apply_interest() {
        balance += balance * (interestRate / 100);
        return balance;
    }
};

double SavingsAccount::interestRate = 10.5;

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(string s, double limit = 1000.56) : BankAccount(s), overdraftLimit(limit) {}

    double withdraw(double s) override {
        if (balance + overdraftLimit >= s) {
            balance -= s;
            return balance;
        } else {
            cout << "Caution!!! Overdraft limit exceeded." << endl;
            return balance;
        }
    }
};

class BusinessAccount : public BankAccount {
    static double corporateTaxRate;

public:
    BusinessAccount(string s) : BankAccount(s) {}

    double deposit(double s) override {
        double tax = s * (corporateTaxRate / 100);
        balance += (s - tax);
        return balance;
    }
};

double BusinessAccount::corporateTaxRate = 15.0;

class User {
protected:
    string name;
    string role;

public:
    User(string n, string r) : name(n), role(r) {}

    virtual void performAction() = 0;
};

class Customer : public User {
public:
    Customer(string n) : User(n, "Customer") {}

    void performAction() override {
        cout << "Customer can only deposit or withdraw from accounts." << endl;
    }
};

class Teller : public User {
public:
    Teller(string n) : User(n, "Teller") {}

    void performAction() override {
        cout << "Teller can deposit, withdraw, or freeze accounts." << endl;
    }
};

class Manager : public User {
public:
    Manager(string n) : User(n, "Manager") {}

    void performAction() override {
        cout << "Manager can deposit, withdraw, freeze accounts, and adjust account limits." << endl;
    }
};

int main() {
    SavingsAccount savings("12345");
    CheckingAccount checking("67890");
    BusinessAccount business("11223");

    Customer cust("John Doe");
    Teller teller("Jane Smith");
    Manager manager("Boss Man");

    cout << "Customer's account balance: $" << savings.get_balance() << endl;
    savings.deposit(500);
    cout << "Customer's account balance after deposit: $" << savings.get_balance() << endl;
    savings.withdraw(100);
    cout << "Customer's account balance after withdrawal: $" << savings.get_balance() << endl;

    cout << "\nTeller Actions: " << endl;
    teller.performAction();
    checking.deposit(500);
    cout << "Checking account balance after deposit: $" << checking.get_balance() << endl;
    checking.withdraw(200);
    cout << "Checking account balance after withdrawal: $" << checking.get_balance() << endl;

    cout << "\nManager Actions: " << endl;
    manager.performAction();
    business.deposit(1000);
    cout << "Business account balance after deposit: $" << business.get_balance() << endl;

    savings.apply_interest();
    cout << "Savings account balance after applying interest: $" << savings.get_balance() << endl;

    checking.withdraw(2000);

    return 0;
}
