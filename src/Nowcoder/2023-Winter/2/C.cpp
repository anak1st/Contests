/**
 * @author: XiaFan
 * @date: 2023-01-18 14:13
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int P = 998244353;
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
    int v;
    int M() const {
        if constexpr (Mod <= 0) {
            return P;
        } else {
            return Mod;
        }
    }
    // assume -M <= __x < 2 M
    int norm(int x) const {
        if (x >= P) {
            x -= M();
        } else if (x < 0) {
            x += M();
        }
        return x;
    }
    MintBase() : v(0) {}
    MintBase(int x) : v(norm(x)) {}
    MintBase(i64 x) : v(norm(x % M())) {}
    int val() const {
        return v;
    }
    MintBase operator-() const {
        return MintBase(norm(M() - v));
    }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
    MintBase &operator+=(const MintBase &rhs) {
        v = norm(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = norm(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = 1LL * v * rhs.v % M();
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) {
        return *this *= rhs.inv();
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
    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
using Mint = MintBase<0>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector<int> dif(n + 1);
    for (int i = 0; i < m; i++) {
        int L = std::min(a[i].first, n);
        int R = std::min(a[i].second + 1, n);
        dif[L]++;
        dif[R]--;
    }
    std::vector<Mint> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + dif[i];
    }
    Mint ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans += f[i] * f[n - i];
    }
    for (int i = 0; i < m; i++) {
        double X = 1.0 * n / 2;
        auto [L, R] = a[i];
        if (X > R || X < L) {
            continue;
        }
        int t = std::min((int)floor(X) - L, R - (int)ceil(X)) + 1;
        t *= 2;
        if (n % 2 == 0) {
            t--;
        }
        ans -= t;
    }
    std::cout << ans;

    return 0;
}