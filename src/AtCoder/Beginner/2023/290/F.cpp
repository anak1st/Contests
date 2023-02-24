/**
 * @author: XiaFan
 * @date: 2023-02-23 20:40
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> constexpr T power(T a, i64 b) {
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
    constexpr i64 norm(i64 x) const {
        x %= P;
        if (x < 0) {
            x += P;
        }
        return x;
    }
    constexpr MintBase() : v{0} {}
    constexpr MintBase(i64 x) : v{norm(x)} {}
    explicit constexpr operator i64() const {
        return v;
    }
    constexpr i64 val() const {
        return v;
    }
    constexpr MintBase operator-() const {
        return MintBase(norm(P - v));
    }
    constexpr MintBase inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }
    constexpr MintBase &operator+=(const MintBase &rhs) {
        v = norm(v + rhs.v);
        return *this;
    }
    constexpr MintBase &operator-=(const MintBase &rhs) {
        v = norm(v - rhs.v);
        return *this;
    }
    constexpr MintBase &operator*=(const MintBase &rhs) {
        v = norm(v * rhs.v);
        return *this;
    }
    constexpr MintBase &operator/=(const MintBase &rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MintBase operator+(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MintBase operator-(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
};

constexpr i64 P = 998244353;
using Mint = MintBase<P>;
struct Comb {
    int n;
    std::vector<Mint> facs, invfacs, invs; 
    Comb(int n = 1000) : n{0}, facs{1}, invfacs{1}, invs{0} {
        init(n);
    }
    void init(int m) {
        if (m <= n) return;
        facs.resize(m + 1);
        invfacs.resize(m + 1);
        invs.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            facs[i] = facs[i - 1] * i;
        }
        invfacs[m] = facs[m].inv();
        for (int i = m; i > n; i--) {
            invfacs[i - 1] = invfacs[i] * i;
            invs[i] = invfacs[i] * facs[i - 1];
        }
        n = m;
    }
    Mint fac(int m) {
        if (m > n) init(2 * m);
        return facs[m];
    }
    Mint invfac(int m) {
        if (m > n) init(2 * m);
        return invfacs[m];
    }
    Mint inv(int m) {
        if (m > n) init(2 * m);
        return invs[m];
    }
    Mint A(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m);
    }
    Mint C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

void solve() {
    int n;
    std::cin >> n;
    Mint ans = Mint(n) * comb.C(2 * n - 4, n - 1) + comb.C(2 * n - 3, n - 1);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}