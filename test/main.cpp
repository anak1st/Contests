/**
 * @author: XiaFan
 * @date: 2023-05-24 13:57
 */
#include <bits/stdc++.h>

using i64 = long long;

// Disjoint Set Union
struct DSU {
    int n;
    std::vector<int> f, cntv;
    DSU(int size) : n(size), f(n), cntv(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        cntv[x] += cntv[y];
        f[y] = x;
        return true;
    }
    int cnt_v(int x) { return cntv[find(x)]; }
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
    
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[dsu.find(i)].push_back(a[i]);
    }
    int two = 0;
    int full = 0;
    int rest = 0;

    for (auto [k, v] : mp) {
        if (v.size() == 2) {
            two++;
            continue;
        }

        std::set<int> st(v.begin(), v.end());
        if (st.size() == v.size()) {
            full++;
        } else {
            rest++;
        }
    }

    std::cout << full + std::min(1, rest + two) << " " << mp.size() << "\n";
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