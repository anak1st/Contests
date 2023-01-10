/**
 * @author: XiaFan
 * @date: 11-17 21:47
 **/
#include <bits/stdc++.h>

using i64 = long long;

int P;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    P = n;
    Mint x = 1;
    std::vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (std::gcd(i, n) == 1) {
            x *= i;
            ans.push_back(i);
        }
    }
    if (x.val() != 1) {
        int e = x.val();
        ans.erase(std::lower_bound(ans.begin(), ans.end(), e));
    }
    std::cout << ans.size() << "\n";
    for (auto i : ans) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    return 0;
}