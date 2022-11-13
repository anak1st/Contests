/**
 * @author: XiaFan
 * @date: 08-27 21:19
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    std::vector<int> f, s;
    
    DSU(int n) : f(n), s(n, 1) { 
        std::iota(f.begin(), f.end(), 0); 
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
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
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n);
    std::vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
        cnt[x]++, cnt[y]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 1) {
            q.push(i);
        }
    }

    std::set<int> ncyc;
    while(!q.empty()) {
        int x = q.front();
        ncyc.insert(x);
        q.pop();
        for (auto y : G[x]) {
            cnt[y]--;
            if (cnt[y] == 1) {
                q.push(y);
            }
        }
    }

    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (auto j : G[i]) {
            if (ncyc.count(i) || ncyc.count(j)) {
                dsu.merge(i, j);
            }
        }
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (dsu.same(x, y)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}