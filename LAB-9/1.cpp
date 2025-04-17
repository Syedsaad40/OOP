#include<iostream>
#include<string>
using namespace std;

class Wallet {
private:
    double balance;
    int limit;
public:
    Wallet(double a = 0, int b = 5000) : balance(a), limit(b) {}
    
    void spend(double a) {
        if (balance <= 0 || a > balance) {
            cout << "Insufficient balance cannot spend.." << endl;
        }
        else if (a > limit) {
            cout << "Cannot spend more than the limit: " << limit << endl;
        }
        else {
            balance -= a;
            cout << "Amount withdrawn. New balance is: " << balance << endl;
        }
    }
    
    void deposit(double b) {
        balance += b;
        cout << "Amount deposited. New balance is: " << balance << endl;
        if (balance > limit) {
            cout << "Balance is now exceeding the limit" << endl;
        }
    }
    
    void set_maxlimit(int new_limit) {
        limit = new_limit;
    }
    
    int get_limit() const {
        return limit;
    }
    
    double get_balance() const {
        return balance;
    }
};

class User {
private:
    int userID;
    string name;
    Wallet wallet;
public:
    User(int a, string b) : userID(a), name(b), wallet(0, 5000) {}
    
    void deposit(double a) {
        wallet.deposit(a);
    }
    
    void withdraw(double b) {
        wallet.spend(b);
    }
    
    void set_limit(int a) {
        wallet.set_maxlimit(a);
    }
    
    void display() const {
        cout << "User ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << wallet.get_balance() << endl;
        cout << "Spending Limit: " << wallet.get_limit() << endl;
    }
};

int main() {
    User user1(101, "Alice");
    User user2(102, "Bob");
    user1.deposit(2000);
    user1.withdraw(500);
    user1.set_limit(3000);
    user1.withdraw(4000); 
    user1.display();
    cout << "\n";
    user2.deposit(10000);
    user2.withdraw(2000);
    user2.display();
    return 0;
}
