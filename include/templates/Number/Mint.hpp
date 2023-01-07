#include <cassert>
#include <iostream>

using i64 = long long;

constexpr int P = 1e9 + 7;

int mod(i64 x) {
    return (x % P + P) % P;
}

template <class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
    int x;

    Mint() : x(0) {}
    Mint(int x) : x(mod(x)) {}
    Mint(i64 x) : x(mod(x)) {}

    int val() const {
        return x;
    }
    Mint operator+() const {
        return *this;
    }
    Mint operator-() const {
        return Mint(mod(P - x));
    }
    Mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    Mint &operator*=(const Mint &rhs) {
        x = mod(1LL * x * rhs.x);
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = mod(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = mod(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        *this *= rhs.inv();
        return *this;
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

    Mint &operator++() {
        *this += 1;
        return *this;
    }
    Mint &operator--() {
        *this -= 1;
        return *this;
    }
    Mint operator++(int) {
        Mint res = *this;
        ++(*this);
        return res;
    }
    Mint operator--(int) {
        Mint res = *this;
        --(*this);
        return res;
    }

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
};
