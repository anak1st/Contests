#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int P = 998244353;

int mod(i64 x) {
    x = (x % P + P) % P;
    return x;
}

template <typename T> T power(T a, int x) {
    T res = 1;
    while (x > 0) {
        if (x % 2) {
            res *= a;
        }
        x /= 2;
        a *= a;
    }
    return res;
}

struct Mint {
    int x;
    Mint(int _x = 0) : x(mod(_x)) {}
    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(mod(-x));
    }

    Mint &operator+=(const Mint &rhs) {
        x = mod(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = mod(x - rhs.x);
        return *this;
    }
    Mint &operator*=(const Mint &rhs) {
        x = mod(1ll * x * rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        assert(rhs.x != 0);
        x = mod(x / rhs.x);
        return *this;
    }

    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res -= rhs;
        return res;
    }
    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res *= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res /= rhs;
        return res;
    }

    friend istream &operator>>(istream &is, Mint &m) {
        i64 val;
        is >> val;
        m.x = mod(val);
        return is;
    }
    friend ostream &operator<<(ostream &os, Mint &m) {
        os << m.val();
        return os;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Mint> dp1(n + 2), dp2(n + 2);
    dp1[0] = 1;
    while (n--) {
        int x;
        cin >> x;
        dp1[x + 1] *= 2;
        dp1[x + 1] += dp1[x];
        if (x > 0) dp2[x - 1] *= 2;
        if (x > 0) dp2[x - 1] += dp1[x - 1];
        dp2[x + 1] *= 2;
    }
    Mint ans = 0;
    for (auto &x : dp1) ans += x.val();
    for (auto &x : dp2) ans += x.val();

    cout << mod(ans.val() - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}