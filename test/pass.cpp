/**
 * @author: XiaFan
 * @date: 2023-02-03 15:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

// Disjoint Set Union
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

struct edge {
    int a, b;
    int c;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
};
int Kruskal(int n, std::vector<edge> edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    for (auto &[a, b, c] : edges) {
        if (dsu.merge(a, b)) {
            // std::cout << a + 1 << " " << b + 1 << " ";
            std::cout << c << " ";
            ans += c;
        }
    }
    std::cout << "\n";
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<edge> e;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int len = std::gcd(i, j);
            if (j - i <= k) {
                len = std::lcm(i, j);
            }
            e.emplace_back(i - 1, j - 1, len);
        }
    }
    std::cout << Kruskal(n, e) << "\n";

    return 0;
}