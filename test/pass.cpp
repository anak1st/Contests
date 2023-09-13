/**
 * @author: XiaFan
 * @date: 2023-09-11 23:32
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != i) {
                std::cout << "NO\n";
                return;
            }
        }

        std::cout << "YES\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == i) {
            std::cout << "NO\n";
            return;
        }
    }

    std::vector<int> vis(n, -1);
    auto find_cycle = [&](int st) -> std::vector<int> {
        std::vector<int> res;
        int p = st;
        do {
            res.push_back(p);
            p = a[p];
        } while (p != st);
        return res;
    };

    std::vector<std::vector<int>> cycles;

    auto dfs = [&](auto &&dfs, int p, int st) -> void {
        vis[p] = st;
        if (vis[a[p]] == -1) {
            dfs(dfs, a[p], st);
        } else if (vis[a[p]] == st) {
            cycles.push_back(find_cycle(p));
        }
    };

    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            dfs(dfs, i, i);
        }
    }

    for (auto &c : cycles) {
        if (c.size() != k) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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