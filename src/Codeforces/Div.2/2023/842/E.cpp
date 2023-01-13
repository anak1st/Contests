/**
 * @author: XiaFan
 * @date: 2023-01-07 09:55
 **/
#include <bits/stdc++.h>
using i64 = long long;

int P = 1e9 + 7;
template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <int Mod> struct MintBase {
    int _x;
    int M() const {
        if constexpr (Mod <= 0) {
            return P;
        } else {
            return Mod;
        }
    }
    // assume -M <= __x < 2 M
    int mod(int x) const {
        if (x < 0) x += M();
        if (x >= P) x -= M();
        return x;
    }
    MintBase() : _x(0) {}
    MintBase(int x) : _x(mod(x)) {}
    MintBase(i64 x) : _x(mod(x % M())) {}
    int val() const { return _x; }
    MintBase operator-() const { return MintBase(mod(M() - _x)); }
    MintBase inv() const {
        assert(_x != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
    MintBase &operator*=(const MintBase &rhs) {
        _x = 1LL * _x * rhs._x % M();
        return *this;
    }
    MintBase &operator+=(const MintBase &rhs) {
        _x = mod(_x + rhs._x);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        _x = mod(_x - rhs._x);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) { return *this *= rhs.inv(); }
    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend MintBase operator+(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res += rhs;
        return res;
    }
    friend MintBase operator-(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res -= rhs;
        return res;
    }
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 v;
        is >> v;
        a = MintBase(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
using Mint = MintBase<0>;

std::vector<Mint> fact, invfact;
void init(int size) {
    fact.resize(size + 1);
    invfact.resize(size + 1);
    fact[0] = 1;
    for (int i = 1; i <= size; i++) {
        fact[i] = fact[i - 1] * i;
    }
    invfact[size] = fact[size].inv();
    for (int i = size; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i;
    }
}
Mint A(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k];
}
Mint C(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] * invfact[k];
}

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n >> P;

    init(3 * n);

    Mint ans[4];
    ans[0] = 1;
    ans[1] = fact[2 * n] * 2 - fact[n];
    ans[1] -= ans[0];
    ans[2] = C(2 * n, n) * 2 * fact[2 * n] * fact[n];
    for (int i = 0; i <= n; i++) {
        ans[2] -= C(n, i) * C(n, n - i) * C(2 * n - i, n) * fact[n] * fact[n] * fact[n];
    }
    ans[2] -= ans[1] + ans[0];
    ans[3] = fact[3 * n] - ans[2] - ans[1] - ans[0];
    Mint tot = ans[1] * 1 + ans[2] * 2 + ans[3] * 3;
    std::cout << tot << std::endl;

    return 0;
}