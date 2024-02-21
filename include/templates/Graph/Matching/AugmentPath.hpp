#pragma once
#include <bits/stdc++.h>

using i64 = long long;

struct AugmentPath {
    std::vector<std::vector<int> > g;
    std::vector<int> pa;
    std::vector<int> pb;
    std::vector<int> vis;
    int n, m;
    int dfn;  // 时间戳记
    int res;  // 匹配数

    AugmentPath(int _n, int _m) : n(_n), m(_m) {
        assert(0 <= n && 0 <= m);
        pa = std::vector<int>(n, -1);
        pb = std::vector<int>(m, -1);
        vis = std::vector<int>(n);
        g.resize(n);
        res = 0;
        dfn = 0;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < m);
        g[from].push_back(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pb[u] = v;
                pa[v] = u;
                return true;
            }
        }
        for (int u : g[v]) {
            if (vis[pb[u]] != dfn && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            dfn++;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                break;
            }
            res += cnt;
        }
        return res;
    }
};