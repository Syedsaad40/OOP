#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInteger {
private:
    std::vector<int> digits;
    bool isNegative = false;

    void normalize() {
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0) isNegative = false;
    }

public:
    BigInteger() : digits{0} {}
    BigInteger(const std::string& s) {
        if (s.empty()) digits.push_back(0);
        else {
            int start = (s[0] == '-') ? 1 : 0;
            isNegative = (s[0] == '-');
            for (int i = s.size() - 1; i >= start; --i) {
                digits.push_back(s[i] - '0');
            }
        }
        normalize();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            BigInteger temp = other;
            temp.isNegative = !temp.isNegative;
            return *this - temp;
        }

        BigInteger result;
        result.isNegative = isNegative;
        result.digits.clear();
        int carry = 0;
        size_t max_len = std::max(digits.size(), other.digits.size());
        for (size_t i = 0; i < max_len || carry; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            BigInteger temp = other;
            temp.isNegative = !temp.isNegative;
            return *this + temp;
        }

        if (abs() < other.abs()) {
            BigInteger result = other - *this;
            result.isNegative = !isNegative;
            return result;
        }

        BigInteger result;
        result.digits.clear();
        int borrow = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int diff = digits[i] - borrow;
            if (i < other.digits.size()) diff -= other.digits[i];
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.normalize();
        return result;
    }

    BigInteger abs() const {
        BigInteger result = *this;
        result.isNegative = false;
        return result;
    }

    friend bool operator<(const BigInteger& a, const BigInteger& b) {
        if (a.isNegative != b.isNegative) return a.isNegative;
        if (a.digits.size() != b.digits.size()) {
            return a.isNegative ? (a.digits.size() > b.digits.size()) : (a.digits.size() < b.digits.size());
        }
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.isNegative ? (a.digits[i] > b.digits[i]) : (a.digits[i] < b.digits[i]);
            }
        }
        return false;
    }

    friend bool operator==(const BigInteger& a, const BigInteger& b) {
        return a.isNegative == b.isNegative && a.digits == b.digits;
    }

    friend bool operator!=(const BigInteger& a, const BigInteger& b) { return !(a == b); }
    friend bool operator>(const BigInteger& a, const BigInteger& b) { return b < a; }
    friend bool operator<=(const BigInteger& a, const BigInteger& b) { return !(b < a); }
    friend bool operator>=(const BigInteger& a, const BigInteger& b) { return !(a < b); }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) os << '-';
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }
};

int main() {
    BigInteger a("1234");
    BigInteger b("5678");
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a < b? " << (a < b) << std::endl;
    std::cout << "a == b? " << (a == b) << std::endl;
    return 0;
}