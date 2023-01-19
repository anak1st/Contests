/**
 * @author: XiaFan
 * @date: 2023-01-18 14:30
 **/
#include <bits/stdc++.h>
using i64 = long long;

int P;
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

    int n;
    std::cin >> n >> P;
    std::vector<Mint> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> ans(P);
    std::vector<i64> tmp(P);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[(a[i] * a[j]).val()]++;
        }
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < n; j++) {
            ans[(i + a[j]).val()] += tmp[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[(a[i] * a[i] + a[j]).val()]--;
            ans[(a[i] * a[j] + a[i]).val()]--;
            ans[(a[j] * a[i] + a[i]).val()]--;
        }
    }
    for (int i = 0; i < n; i++) {
        ans[(a[i] * a[i] + a[i]).val()] += 2;
    }

    for (int i = 0; i < P; i++) {
        std::cout << ans[i] << ' ';
    }

    return 0;
}