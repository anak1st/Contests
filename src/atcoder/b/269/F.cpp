/**
 * @author: XiaFan
 * @date: 09-19 20:14
 **/
#include <bits/stdc++.h>

using i64 = long long;
constexpr int P = 998244353;

int modulo(i64 x) {
    return (x % P + P) % P;
}

template<class T> T fpower(T a, i64 b) {
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
    Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, Mint &a){
        i64 temp;
        is >> temp;
        a.x = modulo(temp);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a){
        os << a.x;
        return os;
    }
    
    Mint operator-() const {
        return Mint(modulo(-x));
    }
    
    Mint inv() const {
        assert(x != 0);
        return fpower(*this, P - 2);
    }
    
    Mint &operator*=(const Mint &rhs) {
        x = 1LL * x * rhs.x % P;
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

Mint fun(Mint i, Mint j, Mint m) {
    return (i - 1) * m + j;
}

Mint sum(Mint x, Mint d, Mint n) {
    return n * x + n * (n - 1) * d / 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int q;
    std::cin >> q;
    while (q--) {
        i64 a, b, c, d;
        std::cin >> a >> b >> c >> d;

        Mint ans = 0;

        if ((a + c) % 2 == 1) {
            Mint n1 = (d - c + 1) / 2;
            Mint m1 = (b - a + 2) / 2;
            Mint row1 = sum(fun(a, c + 1, m), 2, n1);
            
            Mint n2 = (d - c + 2) / 2;
            Mint m2 = (b - a + 1) / 2;
            Mint row2 = sum(fun(a + 1, c, m), 2, n2);
            
            ans += sum(row1, 2 * m * n1, m1);
            ans += sum(row2, 2 * m * n2, m2);
        } else {
            Mint n1 = (d - c + 2) / 2;
            Mint m1 = (b - a + 2) / 2;
            Mint row1 = sum(fun(a, c, m), 2, n1);
            
            Mint n2 = (d - c + 1) / 2;
            Mint m2 = (b - a + 1) / 2;
            Mint row2 = sum(fun(a + 1, c + 1, m), 2, n2);
            
            ans += sum(row1, 2 * m * n1, m1);
            ans += sum(row2, 2 * m * n2, m2);
        }
        std::cout << ans << "\n";
    }

    return 0;
}