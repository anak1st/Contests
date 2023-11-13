/**
 * @author: XiaFan
 * @date: 2023-10-31 20:14
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
template <int P>
struct MintBase {
    int v;
    int norm(int x) const {
        if (x >= P) x -= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x % P)} {}
    int val() const { return v; }
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
        v = norm(1LL * v * rhs.v % P);
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
// constexpr int P = 998244353;
// using Mint = MintBase<P>;


constexpr i64 P = 998244353;
using Mint = MintBase<P>;
struct Comb {
    int n;
    std::vector<Mint> facs, invfacs, invs;
    Comb(int n = 1000) : n{0}, facs{1}, invfacs{1}, invs{0} { init(n); }
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
        return fac(n) * invfac(n - m);
    }
    Mint C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
    Mint lucas(int a, int b) {
        if (a < P && b < P) {
            // 小于p了之后直接从定义出发计算
            return C(a, b);
        }
        return C(a % P, b % P) * lucas(a / P, b / P);
    }
} comb;


Mint double_factorial(int n) {
    assert(n % 2 == 1);
    int m = (n + 1) / 2;
    return comb.fac(2 * m) / comb.fac(m) / power(Mint(2), m);
}


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> cnt(n);
    auto dfs = [&](auto &&dfs, int p, int f) -> int {
        std::vector<int> res(2);
        for (auto c : adj[p]) {
            if (c == f) {
                continue;
            }
            res[dfs(dfs, c, p)]++;
        }
        if (adj[p].size() == 1) {
            return 1;
        }
        if (adj[p].size() == 2) {
            return res[0];
        }
        // std::cerr << p + 1 << ' ' << res[0] << ' ' << res[1] << '\n';
        if (res[1] % 2) {
            cnt[p] = res[1] + 1;
            return 0;
        } else {
            cnt[p] = res[1];
            return 1;
        }
    };

    dfs(dfs, 0, -1);
    Mint ans = 1;
    for (int i = 0; i < n; i++) {
        // std::cerr << cnt[i] << " \n"[i == n - 1];
        if (cnt[i]) {
            ans *= double_factorial(cnt[i] - 1);
        }
    }

    std::cout << ans << '\n';
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}