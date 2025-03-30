#include<iostream>
#include<string>
using namespace std;

class Currency {
protected:
    double amount;
    string currcode;
    char currsymbol;
    double exchangerate;

public:
    Currency(double a, string b, char c, double d) : amount(a), currcode(b), currsymbol(c), exchangerate(d) {}

    virtual void convertToBase() {
        amount = amount * exchangerate;
    }

    virtual void displayCurrency() {
        cout << currsymbol << amount << " (" << currcode << ")" << endl;
    }

    void convertToTargetCurrency(Currency& target) {
        double baseAmount = amount * exchangerate;
        amount = baseAmount / target.exchangerate;
    }
};

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", '$', 1.0) {}
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", '€', 0.93) {}
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "INR", '₹', 82.0) {}
};

int main() {
    Dollar usd(100.0);
    Euro eur(100.0);
    Rupee inr(100.0);

    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    usd.convertToTargetCurrency(eur);
    usd.displayCurrency();

    eur.convertToTargetCurrency(inr);
    eur.displayCurrency();

    inr.convertToTargetCurrency(usd);
    inr.displayCurrency();

    return 0;
}