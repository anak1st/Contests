/**
 * @author: XiaFan
 * @date: 2023-04-12 14:34
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<i64, i64>> a(n);
    for (auto& [x, y] : a) {
        std::cin >> x >> y;
    }
    std::sort(a.begin(), a.end());

    std::multiset<i64> suff;
    for (int i = 0; i < n; i++) {
        suff.insert(a[i].second);
    }
    i64 max = -INF, ans = INF;
    for (int i = n - 1; i >= 0; i--) {
        suff.erase(suff.find(a[i].second));
        ans = std::min(ans, std::abs(a[i].first - max));
        if (!suff.empty()) {
            auto it = suff.lower_bound(a[i].first);
            if (it != suff.end()) {
                ans = std::min(ans, std::abs(a[i].first - std::max(max, *it)));
            }
            if (it != suff.begin()) {
                ans = std::min(ans, std::abs(a[i].first - std::max(max, *std::prev(it))));
            }
        }
        max = std::max(max, a[i].second);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}