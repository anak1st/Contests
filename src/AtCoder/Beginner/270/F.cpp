/**
 * @author: XiaFan
 * @date: 09-29 19:51
 **/
#include <bits/stdc++.h>
using i64 = long long;

class DSU {
private:
    std::vector<int> f, s;

public:
    DSU(int n) : f(n), s(n, 1) {
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
        if (x == y) return false;
        s[x] += s[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return s[find(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::array<int, 3>> E;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        E.push_back({x, i, n});
    }
    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        E.push_back({y, i, n + 1});
    }
    for (int i = 0; i < m; i++) {
        int a, b, z;
        std::cin >> a >> b >> z;
        a--, b--;
        E.push_back({z, a, b});
    }

    std::sort(E.begin(), E.end());

    auto fun = [&](int root, std::set<int> del) -> i64 {
        DSU dsu(n + 2);
        i64 ans = 0;
        for (auto [z, x, y] : E) {
            if (del.count(x) || del.count(y)) {
                continue;
            }
            if (dsu.merge(x, y)) {
                ans += z;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!dsu.same(i, root)) {
                return 1e18;
            }
        }
        return ans;
    };

    i64 ans = 1e18;
    ans = std::min(ans, fun(0,     std::set<int>{}));
    ans = std::min(ans, fun(n,     std::set<int>{n + 1}));
    ans = std::min(ans, fun(n + 1, std::set<int>{n}));
    ans = std::min(ans, fun(0,     std::set<int>{n, n + 1}));

    std::cout << ans;

    return 0;
}