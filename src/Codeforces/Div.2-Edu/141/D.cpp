/**
 * @author: XiaFan
 * @date: 2023-01-12 21:36
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int B = 300 * 300;
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

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector dp(n + 2, std::vector<Mint>(B * 2 + 1));
    dp[2][a[2] + B] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = -B + 300; j <= B - 300; j++) {
            if (j != 0) {
                dp[i + 1][a[i + 1] - j + B] += dp[i][j + B];
                dp[i + 1][a[i + 1] + j + B] += dp[i][j + B];
            } else {
                dp[i + 1][a[i + 1] + B] += dp[i][B];
            }
        }
    }

    Mint ans = 0;
    for (int i = -B; i <= B; i++) {
        ans += dp[n][i + B];
    }
    std::cout << ans;

    return 0;
}