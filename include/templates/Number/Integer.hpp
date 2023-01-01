#pragma once

#include <algorithm>

using i64 = long long;

template <unsigned int Size>
class IntegerBase {
private:
    int length = 0;
    int digits[Size];

public:
    IntegerBase() {
        std::fill(digits, digits + Size, 0);
    }
    IntegerBase(i64 x) {
        while (x) {
            digits[length++] = x % 10;
            x /= 10;
        }
    }
    IntegerBase(const std::string &s) {
        for (int i = s.length() - 1; i >= 0; --i) {
            digits[length++] = s[i] - '0';
        }
    }
    IntegerBase(const IntegerBase &other) {
        length = other.length;
        std::copy(other.digits, other.digits + length, digits);
    }

    IntegerBase &operator=(const IntegerBase &other) {
        if (this == &other) {
            return *this;
        }
        length = other.length;
        std::copy(other.digits, other.digits + Size, digits);
        return *this;
    }

    void carry() {
        for (int i = 0; i < length - 1; i++) {
            digits[i + 1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }

    void remove_clz() {
        while (length > 1 && digits[length - 1] == 0) {
            length--;
        }
    }

    IntegerBase &operator+=(const IntegerBase &other) {
        for (int i = 0; i < other.length; i++) {
            digits[i] += other.digits[i];
        }
        length = std::max(length, other.length) + 1;
        carry();
        remove_clz();
        return *this;
    }

    IntegerBase &operator*=(const IntegerBase &other) {
        IntegerBase tmp;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < other.length; j++) {
                tmp.digits[i + j] += digits[i] * other.digits[j];
            }
        }
        tmp.length = length + other.length;
        tmp.carry();
        tmp.remove_clz();
        *this = tmp;
        return *this;
    }

    friend IntegerBase operator+(const IntegerBase &a, const IntegerBase &b) {
        IntegerBase tmp = a;
        tmp += b;
        return tmp;
    }

    friend IntegerBase operator*(const IntegerBase &a, const IntegerBase &b) {
        IntegerBase tmp = a;
        tmp *= b;
        return tmp;
    }

    friend std::ostream &operator<<(std::ostream &os, const IntegerBase &x) {
        for (int i = x.length - 1; i >= 0; i--) {
            os << x.digits[i];
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, IntegerBase &x) {
        std::string s;
        is >> s;
        x = IntegerBase(s);
        return is;
    }
};

using Integer = IntegerBase<100000>;
