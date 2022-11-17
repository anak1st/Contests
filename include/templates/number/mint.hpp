#pragma once

#include <cassert>
#include <iostream>

using i64 = long long;

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

template <int P>
struct Mint {
private:
    int v;

public:
    Mint() : v(0) {}
    Mint(int x) : v(modulo(x)) {}
    Mint(i64 x) : v(modulo(x)) {}
    
    int modulo(i64 x) const { 
        return (x % P + P) % P; 
    }

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 x;
        is >> x;
        a.v = a.modulo(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.val();
        return os;
    }

    constexpr int val() const { return v; }

    Mint operator-() const { return Mint(modulo(-v)); }

    Mint inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }

    Mint &operator++() { return *this += 1; }
    Mint &operator--() { return *this -= 1; }

    Mint &operator*=(const Mint &rhs) {
        v = modulo(1LL * v * rhs.v);
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        v = modulo(v + rhs.v);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        v = modulo(v - rhs.v);
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
};

using mint = Mint<998244353>;

template <typename T>
T A(int n, int m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans *= a;
    }
    return ans;
}

template <typename T>
T C(int n, int m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}