#include <bits/stdc++.h>

using i64 = long long;

template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}
template <i64 P> struct MintBase {
    i64 v;
    i64 norm(i64 x) const {
        x %= P;
        if (x < 0) x += P;
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

constexpr i64 P = 1e9 + 7;
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

void update(std::pair<int, Mint> &a, std::pair<int, Mint> b) {
    if (b.first > a.first) {
        a = b;
    } else if (a.first == b.first) {
        a.second += b.second;
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    std::vector<std::pair<int, Mint>> dp(n + 1);
    dp[0] = {0, 1};
    std::pair<int, Mint> ans{0, 1};
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            cnt += (c[j] == c[i - 1]);
            if (cnt >= k) {
                update(dp[i], {dp[j].first + 1, dp[j].second * comb.C(cnt - 1, k - 1)});
            }
        }
        update(ans, dp[i]);
    }
    
    std::cout << ans.second << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}