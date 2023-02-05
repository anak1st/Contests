#include <bits/stdc++.h>
#include <debug/vector>

using i64 = long long;

constexpr i64 inf = 1E18;

// Disjoint Set Union
struct DSU {
    int n;
    std::vector<int> f, cntv;
    DSU(int size) : n(size), f(n), cntv(n, 1) {
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
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        cntv[x] += cntv[y];
        f[y] = x;
        return true;
    }
    int get_cntv(int x) {
        return cntv[find(x)];
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += i;
    }

    int x = 1;
    std::vector<bool> vis(n + 1);
    std::vector<int> b;
    while (1 <= x && x <= n && !vis[x]) {
        b.push_back(x);
        vis[x] = true;
        x = a[x];
    }

    DSU dsu(n + 1);
    std::vector<bool> cyc(n + 1);
    for (int i = 1; i <= n; i++) {
        if (1 <= a[i] && a[i] <= n && !vis[i]) {
            if (!dsu.merge(i, a[i])) {
                cyc[i] = true;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (cyc[i]) {
            sum += dsu.get_cntv(i);
        }
    }

    if (1 <= x && x <= n) {
        for (int i = 1; i <= n; i++) {
            if (1 <= a[i] && a[i] <= n && vis[i]) {
                dsu.merge(i, a[i]);
            }
        }
        sum += dsu.get_cntv(1);
        i64 ans = 1LL * b.size() * (2 * n + 1 - sum);
        std::cout << ans << "\n";
    } else {
        i64 ans = 0;
        for (auto v : b) {
            ans += sum + dsu.get_cntv(1);
            if (1 <= a[v] && a[v] <= n) {
                dsu.merge(v, a[v]);
            }
        }
        ans = 1LL * n * (2 * n + 1) - ans;
        std::cout << ans << "\n";
    }
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
