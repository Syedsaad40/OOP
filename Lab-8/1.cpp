#include<iostream>
#include<string>
using namespace std;

class Account{
protected:
    string name;
    int accountnumber;
    double balance;
    string type;
    static int count;
    
public:
    Account(string a, int b, string c): name(a), accountnumber(b), type(c), balance(0) { count++; }
    
    void deposit_amount(double a){
        balance += a;
        cout<<"Amount after deposit:"<<balance<<endl;
    }
    
    double get_balance(){
        return balance;
    }	
    
    virtual void withdraw_amount(double a){
        if(balance >= a){
            balance -= a;
            cout<<"Amount after withdrawal:"<<balance<<endl;
        }
        else{
            cout<<"Insufficient balance!"<<endl;
        }
    }
    
    virtual void printstatement(){
        cout<<"Current Amount for account "<<accountnumber<<" is: "<<balance<<endl;
    }
    
    virtual void get_accountinfo(){
        cout<<"Account Details:"<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Account Number:"<<accountnumber<<endl;
        cout<<"Type:"<<type<<endl;
    }
    
    virtual double calculateinterest(){
        return 0.0;
    }
};

int Account::count = 0;

class SavingsAccount: public Account{
    double interestrate;
    double minimumbalance;
    
public:
    SavingsAccount(string a, int b, string c, double d, double e): Account(a, b, c), interestrate(d), minimumbalance(e) {}
    
    void get_accountinfo() override {
        Account::get_accountinfo();
        cout<<"Interest Rate:"<<interestrate<<endl;
        cout<<"Minimum Balance:"<<minimumbalance<<endl;
    }
    
    void withdraw_amount(double a) override {
        if(balance - a >= minimumbalance){
            balance -= a;
            cout<<"Amount after withdrawal:"<<balance<<endl;
        }
        else{
            cout<<"Withdrawal denied. Minimum balance requirement not met!"<<endl;
        }
    }
    
    double calculateinterest() override {
        return balance * interestrate;
    }
};

class CheckingAccount: public Account{
public:
    CheckingAccount(string a, int b, string c): Account(a, b, c) {}
    
    void withdraw_amount(double a) override {
        if(balance >= a){
            balance -= a;
            cout<<"Amount after withdrawal:"<<balance<<endl;
        }
        else{
            cout<<"Insufficient balance! Overdraft not allowed."<<endl;
        }
    }
};

class FixedDepositAccount: public Account{
    string maturitydate;
    double fixedinterestrate;
    
public:
    FixedDepositAccount(string a, int b, string c, string d, double e): Account(a, b, c), maturitydate(d), fixedinterestrate(e) {}
    
    void get_accountinfo() override {
        Account::get_accountinfo();
        cout<<"Maturity Date:"<<maturitydate<<endl;
        cout<<"Fixed Interest Rate:"<<fixedinterestrate<<endl;
    }
    
    void withdraw_amount(double a) override {
        cout<<"Withdrawal not allowed before maturity date!"<<endl;
    }
    
    double calculateinterest() override {
        return balance * fixedinterestrate;
    }
};

int main(){
    return 0;
}