/**
 * @author: XiaFan
 * @date: 2023-02-01 14:17
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::pair<i64, i64>> a(m);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }

    std::vector<i64> ans(n + 1, inf);
    ans[n] = 0;
    for (int i = n; i >= 1; i--) {
        for (auto [x, y] : a) {
            if (y > i) {
                continue;
            }
            ans[i - i % y] = std::min(ans[i - i % y], ans[i] + x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] != inf) {
            std::cout << ans[i];
            break;
        }
    }

    return 0;
}