/**
 * @author: XiaFan
 * @date: 09-08 19:44
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    int n;
    std::vector<int> f, s;

    DSU(int n_) : n(n_), f(n_), s(n_, 1) {
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        s[x] += s[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return s[find(x)];
    }

    int num() {
        std::set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(find(i));
        }
        return st.size();
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    DSU dsu1(n);
    std::string s;
    std::vector<std::pair<int, int>> edge(m);
    for (auto &[x, y] : edge) {
        std::cin >> x >> y;
        x--, y--;
        if (dsu1.merge(x, y)) {
            s.push_back('0');
        } else {
            s.push_back('1');
        }
    }

    DSU ans(n), dsu2(n);
    for (int i = 0; i < m; i++) {
        auto [x, y] = edge[i];
        if (s[i] == '1') {
            if (!dsu2.merge(x, y)) {
                ans.merge(x, y);
                s[i] = '2';
            }
        }
    }

    for (int i = 0; i < m; i++) {
        auto [x, y] = edge[i];
        if (s[i] == '2') {
            s[i] = '0';
        } else if (ans.merge(x, y)) {
            s[i] = '0';
        } else {
            s[i] = '1';
        }
    }

    std::cout << s << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}