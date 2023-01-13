/**
 * @author: XiaFan
 * @date: 2023-01-05 23:23
 **/
#include <bits/stdc++.h>

using i64 = long long;

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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        dsu.merge(i, a[i]);
    }
    std::set<int> cnt;
    for (int i = 0; i < n; i++) {
        cnt.insert(dsu.find(i));
    }
    int op = n - cnt.size() + 1;

    // std::cerr << cnt.size() << "\n";
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && dsu.same(i, i + 1)) {
            op -= 2;
            break;
        }
        if (i - 1 >= 0 && dsu.same(i, i - 1)) {
            op -= 2;
            break;
        }
    }
    std::cout << op << "\n";
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