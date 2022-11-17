/**
 * @author: XiaFan
 * @date: 11-14 20:36
 **/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 998244353;

int modulo(i64 x) {
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

struct mint {
private:
    int x;

public:
    mint() : x(0) {}
    mint(int x_) : x(modulo(x_)) {}
    mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, mint &a) {
        i64 temp;
        is >> temp;
        a.x = modulo(temp % P);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        os << a.x;
        return os;
    }

    int val() const {
        return x;
    }

    mint operator-() const {
        return mint(modulo(-x));
    }

    mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    mint &operator*=(const mint &rhs) {
        x = modulo(1LL * x * rhs.x);
        return *this;
    }
    mint &operator+=(const mint &rhs) {
        x = modulo(x + rhs.x);
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        x = modulo(x - rhs.x);
        return *this;
    }
    mint &operator/=(const mint &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
};

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

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << A<mint>(n, n) * C<mint>(n - 1, m - 1)  << "\n";
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