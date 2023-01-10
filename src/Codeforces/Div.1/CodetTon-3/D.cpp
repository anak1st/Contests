/**
 * @author: XiaFan
 * @date: 11-06 23:46
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

    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(modulo(-x));
    }

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

std::vector<int> get(int x) {
    std::vector<int> res;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] % a[i + 1] != 0) {
            std::cout << 0 << "\n";
            // std::cerr << 0 << "\n";
            return;
        }
    }

    Mint ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != 1) {
            int num = 0;
            for (int j = a[i]; j <= m; j += a[i]) {
                if (std::gcd(a[i - 1], j) == a[i]) {
                    num++;
                }
            }
            ans *= num;
        }
    }
    std::cout << ans << "\n";
    std::cerr << ans << "\n";
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