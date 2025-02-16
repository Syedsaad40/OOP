#include<iostream>
using namespace std;

class Account {
    double balance = 0;

public:
    double credit(double amount) {
        balance += amount;
        return balance;
    }

    double debit(double amount) {
        balance -= amount;
        return balance;
    }

    double get_balance() const {
        return balance;
    }
};

int main() {
    Account a;
    Account a1;
    a.credit(1500);
    a.debit(700);
    cout << "Balance remaining for a: " << a.get_balance() << endl;
    a1.debit(1500);
    a1.credit(1500);
    cout << "Amount remaining for a1: " << a1.get_balance() << endl;
    return 0;
}
