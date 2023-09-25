/**
 * @author: XiaFan
 * @date: 2023-09-18 20:16
 */
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
T power(T a, int b) {
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
        x %= P;
        // if (x >= P) x -= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x % P)} {}
    int val() const { return v; }
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
constexpr int P = 998244353;
using Mint = MintBase<P>;

struct DSU {
    int n;
    std::vector<int> f, sz;
    DSU(int size) : n(size), f(n), sz(n, 1) { 
        std::iota(f.begin(), f.end(), 0); 
    }
    int find(int x) { 
        return f[x] == x ? x : f[x] = find(f[x]); 
    }
    bool same(int x, int y) { 
        return find(x) == find(y); 
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};

void fast_read(int &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    x *= f;
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        // std::cin >> x >> y;
        fast_read(x), fast_read(y);
        x--, y--;
        a[i] = {x, y};
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        // std::cin >> x >> y;
        fast_read(x), fast_read(y);
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<int> fa(n, -1);
    auto dfs = [&](auto &&dfs, int x, int f) -> void {
        fa[x] = f;
        for (auto y : adj[x]) {
            if (y == f) continue;
            dfs(dfs, y, x);
        }
    };
    dfs(dfs, 0, -1);
    // for (int i = 0; i < n; i++) {
    //     std::cerr << fa[i] << " ";
    // }

    DSU dsu(n);
    Mint ans = 1;
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        auto &[x, y] = a[i];
        x = dsu.find(x), y = dsu.find(y);
        ans *= dsu.size(x);
        ans *= dsu.size(y);

        if (fa[x] >= 0 && dsu.find(fa[x]) == y) {
            dsu.merge(y, x);
        } else if (fa[y] >= 0 && dsu.find(fa[y]) == x) {
            dsu.merge(x, y);
        } else {
            ok = false;
            break;
        }
    }

    if (!ok) {
        std::cout << 0;
        return 0;
    }
    std::cout << ans.inv();

    return 0;
}