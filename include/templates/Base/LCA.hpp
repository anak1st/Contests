#pragma once
#include "XCPC.h"

struct LCA {
    std::vector<int> parent, depth;
    std::vector<std::array<int, 20>> pa;
    LCA(int n, std::vector<int>& parent) : parent(parent), pa(n + 1), depth(n + 1) {
        for (int i = 1; i <= n; i++) {
            if (this->parent[i] <= 0) this->parent[i] = i;
            pa[i][0] = this->parent[i];
        }

        for (int i = 1; i < 20; i++) {
            for (int j = 1; j <= n; j++) {
                pa[j][i] = pa[pa[j][i - 1]][i - 1];
            }
        }

        std::function<int(int)> get_depth = [&](int now) {
            if (now <= 0 || now > n) return 0;
            if (depth[now]) return depth[now];
            if (parent[now] <= 0 || parent[now] == now) return depth[now] = 1;
            return depth[now] = get_depth(parent[now]) + 1;
        };

        for (int i = 1; i <= n; i++) depth[i] = get_depth(i);
    }

    int lca(int u, int v) {
        /**
         * @brief 返回 u 和 v 的最近公共祖先, 如果 u 和 v 不连通(森林的情况)则返回 -1
         *
         * 使用倍增法, 时间复杂度是 O(n log n)
         */

        if (pa[u][19] != pa[v][19]) return -1;

        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }

        for (int i = 19; depth[u] > depth[v]; i--) {
            if (depth[pa[u][i]] >= depth[v]) {
                u = pa[u][i];
            }
        }

        if (u == v) return u;

        for (int i = 19; i >= 0; i--) {
            if (pa[u][i] != pa[v][i]) {
                u = pa[u][i];
                v = pa[v][i];
            }
        }

        return pa[u][0];
    }
};