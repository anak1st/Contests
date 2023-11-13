/**
 * @author: XiaFan
 * @date: 2023-11-12 13:52
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back({i, i});
        ans.push_back({i, (i + 1) % n});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (i + 1) % n == j) continue;
            if (ans.size() == k) break;
            ans.push_back({i, j});
        }
    }

    for (auto [x, y] : ans) {
        std::cout << x + 1 << ' ' << y + 1 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}