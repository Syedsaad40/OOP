#include<iostream>
#include<cmath>
using namespace std;

class Polynomial {
    double *coff;
    int degree;

public:
    Polynomial() {
        degree = 0;
        coff = new double[1];
        coff[0] = 0;
    }

    Polynomial(int deg, double *arr) {
        degree = deg;
        coff = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coff[i] = arr[i];
        }
    }

    Polynomial(const Polynomial &p) : degree(p.degree) {
        coff = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coff[i] = p.coff[i];
        }
    }

    Polynomial& operator=(const Polynomial &p) {
        if (this != &p) {
            delete[] coff;
            degree = p.degree;
            coff = new double[degree + 1];
            for (int i = 0; i <= degree; i++) {
                coff[i] = p.coff[i];
            }
        }
        return *this;
    }

    Polynomial(Polynomial &&p) noexcept : coff(p.coff), degree(p.degree) {
        p.coff = nullptr;
        p.degree = 0;
    }

    Polynomial& operator=(Polynomial &&p) noexcept {
        if (this != &p) {
            delete[] coff;
            coff = p.coff;
            degree = p.degree;
            p.coff = nullptr;
            p.degree = 0;
        }
        return *this;
    }

    ~Polynomial() {
        delete[] coff;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; i++) {
            result += coff[i] * pow(x, degree - i);
        }
        return result;
    }

    Polynomial add(const Polynomial &other) const {
        int maxDegree = max(degree, other.degree);
        double *sumCoff = new double[maxDegree + 1];
        for (int i = 0; i <= maxDegree; i++) {
            sumCoff[i] = 0;
            if (i <= degree) sumCoff[i] += coff[i];
            if (i <= other.degree) sumCoff[i] += other.coff[i];
        }
        Polynomial sum(maxDegree, sumCoff);
        delete[] sumCoff;
        return sum;
    }

    Polynomial multiply(const Polynomial &other) const {
        int resultDegree = degree + other.degree;
        double *prodCoff = new double[resultDegree + 1];
        for (int i = 0; i <= resultDegree; i++) {
            prodCoff[i] = 0;
        }
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                prodCoff[i + j] += coff[i] * other.coff[j];
            }
        }
        Polynomial product(resultDegree, prodCoff);
        delete[] prodCoff;
        return product;
    }

    void display() const {
        for (int i = 0; i <= degree; i++) {
            cout << coff[i];
            if (i < degree) cout << "x^" << degree - i << " + ";
        }
        cout << endl;
    }
};

int main() {
    double arr1[] = {1, 2, 3};  
    int degree1 = 2;  

    double arr2[] = {0, 1, 4};  
    int degree2 = 2;  

    Polynomial p1(degree1, arr1);  
    Polynomial p2(degree2, arr2);  

    cout << "Polynomial 1: ";
    p1.display();  

    cout << "Polynomial 2: ";
    p2.display();  

    cout << "Evaluating Polynomial 1 at x = 2: " << p1.evaluate(2) << endl;  
    cout << "Evaluating Polynomial 2 at x = 2: " << p2.evaluate(2) << endl;  

    Polynomial sum = p1.add(p2);  
    cout << "Sum of Polynomial 1 and Polynomial 2: ";
    sum.display();  

    Polynomial product = p1.multiply(p2);  
    cout << "Product of Polynomial 1 and Polynomial 2: ";
    product.display();

    return 0;
}
