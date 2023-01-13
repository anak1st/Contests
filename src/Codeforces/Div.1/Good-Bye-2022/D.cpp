/**
 * @author: XiaFan
 * @date: 2023-01-05 14:40
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

    int mod(i64 x) const {
        return (x % MOD + MOD) % MOD;
    }

    int val() const {
        return v;
    }

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

    MintBase operator-() const {
        return MintBase(mod(-v));
    }

    MintBase inv() const {
        assert(v != 0);
        return power(*this, MOD - 2);
    }

    MintBase &operator++() {
        return *this += 1;
    }
    MintBase &operator--() {
        return *this -= 1;
    }

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

constexpr int P = 998244353;
using Mint = MintBase<P>;

struct DSU {
    std::vector<int> f, cnt_v;

    DSU(int n) : f(n), cnt_v(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        cnt_v[x] += cnt_v[y];
        f[y] = x;
        return true;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &it : a) {
        std::cin >> it;
        it--;
    }
    for (auto &it : b) {
        std::cin >> it;
        it--;
    }

    std::vector<int> cnt_e(n);
    std::vector<bool> selfloop(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        int x = dsu.find(a[i]), y = dsu.find(b[i]);
        if (x != y) {
            dsu.cnt_v[x] += dsu.cnt_v[y];
            cnt_e[x] += cnt_e[y];
            selfloop[x] = selfloop[x] || selfloop[y];
            dsu.f[y] = x;
        }
        cnt_e[x]++;
        if (a[i] == b[i]) {
            selfloop[x] = true;
        }
    }

    std::vector<bool> vis(n);
    Mint ans = 1;
    for (int i = 0; i < n; i++) {
        int x = dsu.find(i);
        if (vis[x]) {
            continue;
        }
        if (dsu.cnt_v[x] != cnt_e[x]) {
            std::cout << "0\n";
            return;
        }
        if (selfloop[x]) {
            ans *= n;
        } else {
            ans *= 2;
        }
        vis[x] = true;
    }

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