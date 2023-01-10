/**
 * @author: XiaFan
 * @date: 09-29 22:58
 **/
#include <bits/stdc++.h>
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

    int val() {
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
        x = i64(x) * rhs.x % P;
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

Mint C(int n, int m) {
    if (m > n) return 0;
    Mint ans = 1;
    for (int i = 1; i <= m; i++) {
        Mint a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}

Mint fun(int n) {
    if (n == 2) {
        return 1;
    }
    return C(n - 1, n / 2 - 1) + C(n - 2, n / 2 - 1) - fun(n - 2) - 1;
}

void solve() {
    int n;
    std::cin >> n;
    Mint all = C(n, n / 2);
    Mint win = fun(n);
    std::cout << win << " " << all - win - 1 << " " << 1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}