/**
 * @author: XiaFan
 * @date: 2023-07-28 15:20
 */
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}
template <i64 P>
struct MintBase {
    i64 v;
    i64 norm(i64 x) const {
        x %= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x)} {}
    i64 val() const { return v; }
    MintBase operator-() const { return MintBase(norm(P - v)); }
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
    MintBase &operator/=(const MintBase &rhs) { return *this *= rhs.inv(); }
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
constexpr i64 P = 1e9 + 7;
using Mint = MintBase<P>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
 
    std::vector<Mint> f(2 * m + 1), g(2 * m + 1);
     
    for (int i = 0; i <= 2 * m; i++) {
        f[i] = 1;
    }
 
    for (int i = 2; i <= n; i++) {
        for (int j = -m; j <= m; j++) {
            if (j < 0) {
                g[m] += f[m + j];
                g[2 * m + j + 1] -= f[m + j];
            } else {
                g[m - j] += f[m + j];
                g[2 * m + 1] -= f[m + j];
            }
        }
 
        for (int j = 1; j <= 2 * m; j++) {
            g[j] += g[j - 1];
        }
        for (int j = 0; j <= 2 * m; j++) {
            f[j] = g[j];
            
        }

        for (int j = 0; j < m; j++) {
            std::cerr << f[j] << " \n"[j == m];
        }
        for (int j = 2 * m; j >= m; j--) {
            std::cerr << f[j] << " \n"[j == m];
        }

        g = std::vector<Mint>(2 * m + 1);
    }
    Mint ans = 0;
    for (int i = 0; i <= 2 * m; i++) {
        ans += f[i];
    }
    std::cout << ans << "\n";
 
}