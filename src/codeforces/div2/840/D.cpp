/**
 * @author: XiaFan
 * @date: 12-19 23:03
 **/
#include <bits/stdc++.h>

using i64 = long long;

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

template <int MOD>
class MintBase {
private:
    int v;

public:
    MintBase() : v(0) {}
    MintBase(int x) : v(mod(x)) {}
    MintBase(i64 x) : v(mod(x)) {}

    int mod(i64 x) const { return (x % MOD + MOD) % MOD; }

    int val() const { return v; }

    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a.v = a.mod(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        os << a.val();
        return os;
    }

    MintBase operator-() const { return MintBase(mod(-v)); }

    MintBase inv() const {
        assert(v != 0);
        return power(*this, MOD - 2);
    }

    MintBase &operator++() { return *this += 1; }
    MintBase &operator--() { return *this -= 1; }

    MintBase &operator+=(const MintBase &rhs) {
        v = mod(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = mod(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = mod(1LL * v * rhs.v);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) {
        *this *= rhs.inv();
        return *this;
    }

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
};

constexpr int P = 1e9 + 7;
using Mint = MintBase<P>;

void solve() {
    int n, i, j, x, y;
    std::cin >> n >> i >> j >> x >> y;

    auto check = [&](int pos, int val) {
        if (pos == i && val != x) {
            return false;
        }
        if (pos == j && val != y) {
            return false;
        }
        return true;
    };

    std::vector dp(n + 2, std::vector<Mint>(n + 2));

    for (int i = 2; i <= n - 1; i++) {
        if (check(i, n)) {
            dp[i][i] = 1;
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            int val = n - (j - i + 1);
            if (check(i - 1, val)) {
                dp[i - 1][j] += dp[i][j];
            }
            if (check(j + 1, val)) {
                dp[i][j + 1] += dp[i][j];
            }
        }
    }

    std::cout << dp[1][n] << "\n";
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