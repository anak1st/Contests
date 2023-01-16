/**
 * @author: XiaFan
 * @date: 2023-01-16 17:28
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    int n;
    std::vector<int> f, cntv;
    DSU(int size) : n(size), f(n), cntv(n, 1) {
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
        cntv[x] += cntv[y];
        f[y] = x;
        return true;
    }
    int get_cntv(int x) {
        return cntv[find(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        dsu.merge(u, v);
    }
    std::set<int> st;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i]) {
            st.insert(dsu.find(i));
        }
    }

    if (st.size() == 0) {
        i64 ans = 0;
        std::vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[dsu.find(i)]) {
                continue;
            }
            vis[dsu.find(i)] = true;
            i64 v = dsu.get_cntv(i);
            ans += v * v;
        }
        std::cout << ans;
    } else if (st.size() == 1) {
        i64 v = dsu.get_cntv(*st.begin());
        std::cout << v * v;
    } else {
        std::cout << 0;
    }

    return 0;
}