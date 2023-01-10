/**
 * @author: XiaFan
 * @date: 11-02 20:19
 **/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1000000007;

int modulo(i64 x) { return (x % P + P) % P; }

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
private:
    int x;

public:
    Mint() : x(0) {}
    Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 temp;
        is >> temp;
        a.x = modulo(temp % P);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.x;
        return os;
    }

    int val() const { return x; }

    Mint operator-() const { return Mint(modulo(-x)); }

    Mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    Mint sum = 0, psum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum = (sum + a[i]);
        psum = (psum + Mint(n - i) * a[i]);
    }

    Mint p = power(Mint(2), m);

    Mint ans1 = sum * (p * n + 1) * p / 2;
    Mint ans2 = sum * ((p - 1) * n) * p / 2 + psum * p;

    int ans = std::max(ans1.val(), ans2.val());

    std::cout << ans << "\n";

    return 0;
}