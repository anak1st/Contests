/**
 * @author: XiaFan
 * @date: 2023-03-11 13:37
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <i64 P> struct MintBase {
    i64 v;
    i64 norm(i64 x) const {
        x %= P;
        if (x < 0) {
            x += P;
        }
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x)} {}
    i64 val() const {
        return v;
    }
    MintBase operator-() const {
        return MintBase(norm(P - v));
    }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, P - 2);
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
        v = norm(v * rhs.v);
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
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
};
constexpr i64 P = 1e9 + 9;
using Mint = MintBase<P>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int m = 1 << n;
    std::vector<Mint> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    std::vector<Mint> b = a;

    auto dfs = [&](auto &&dfs, int l, int r) -> Mint {
        if (l == r) {
            return b[l];
        }
        int d = r - l + 1;
        for (int i = 0; i < d / 2; i++) {
            b[i + l] -= b[l + d / 2 + i];
        }
        int mid = (l + r) / 2;
        return dfs(dfs, l, mid) * dfs(dfs, mid + 1, r);
    };

    std::cout << dfs(dfs, 0, m - 1) << "\n";

    return 0;
}