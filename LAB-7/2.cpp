#include <iostream>
#include <vector>
#include <string>

class PolynomialUtils;

class Polynomial {
private:
    std::vector<int> coefficients;
    friend class PolynomialUtils;

    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

public:
    Polynomial() = default;
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }

    Polynomial operator+(const Polynomial& other) const {
        std::vector<int> result(std::max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] += other.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        std::vector<int> result(std::max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] -= other.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> result(coefficients.size() + other.coefficients.size(), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) return os << "0";
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            if (p.coefficients[i] == 0) continue;
            if (!first) {
                os << (p.coefficients[i] > 0 ? " + " : " - ");
                os << abs(p.coefficients[i]);
            } else {
                os << p.coefficients[i];
                first = false;
            }
            if (i > 0) os << "x";
            if (i > 1) os << "^" << i;
        }
        return os;
    }
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        for (int coeff : p.coefficients) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        std::vector<int> result;
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            result.push_back(p.coefficients[i] * i);
        }
        return Polynomial(result);
    }
};

int main() {
    Polynomial p1({1, 2, 3});
    Polynomial p2({0, 1, 1});
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p1 + p2: " << (p1 + p2) << std::endl;
    std::cout << "p1 - p2: " << (p1 - p2) << std::endl;
    std::cout << "p1 * p2: " << (p1 * p2) << std::endl;
    std::cout << "p1 at x=2: " << PolynomialUtils::evaluate(p1, 2) << std::endl;
    std::cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << std::endl;
    return 0;
}