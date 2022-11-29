/**
 * @author: XiaFan
 * @date: 11-29 18:08
 **/
#include <bits/stdc++.h>
// #include "xf.hpp"

#ifndef DEBUG_XF
#define printIn(...)
#endif

using i64 = long long;

constexpr int P = 1e9 + 7;

template <typename T>
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
private:
    int v;

public:
    Mint() : v(0) {}
    Mint(int x) : v(modulo(x)) {}
    Mint(i64 x) : v(modulo(x)) {}

    int modulo(i64 x) const { return (x % P + P) % P; }

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

namespace fast {
std::vector<Mint> fact;
void init() {
    if (fact.empty()) fact.push_back(1);
}

Mint C(i64 a, i64 b) {
    if (b < 0 || b > a) {
        return 0;
    }
    while ((i64)fact.size() <= a) {
        fact.push_back(fact.back() * (i64)fact.size());
    }
    return fact[a] / fact[b] / fact[a - b];
}
}  // namespace fast


void solve() {
    int x, y;
    std::cin >> x >> y;
    std::cout << fast::C(x, y) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    fast::init();
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}