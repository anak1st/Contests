#pragma once

#include <assert.h>
#include <iostream>

using i64 = long long;

int P = 998244353;

int modulo(i64 x) {
    return (x % P + P) % P;
}

template <class T> T fpow(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
private:
    int x;

public:
    Mint() : x(0) {}
    Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 temp;
        a.x = modulo(temp);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.x;
        return os;
    }

    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(modulo(-x));
    }

    Mint inv() const {
        assert(x != 0);
        return fpow(*this, P - 2);
    }

    Mint &operator*=(const Mint &rhs) {
        x = modulo(1LL * x * rhs.x);
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = modulo(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = modulo(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        return *this *= rhs.inv();
    }

    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
};

Mint A(int n, int m) {
    if (m > n) return 0;
    Mint ans = 1;
    for (int i = 1; i <= m; i++) {
        Mint a = n + i - m;
        ans *= a;
    }
    return ans;
}

Mint C(int n, int m) {
    if (m > n) return 0;
    Mint ans = 1;
    for (int i = 1; i <= m; i++) {
        Mint a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}