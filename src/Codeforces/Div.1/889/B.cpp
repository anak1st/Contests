/**
 * @author: XiaFan
 * @date: 2023-07-30 17:16
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::bitset<2 * N + 1> vis;
    vis[1] = true;
    i64 ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        vis |= vis << a[i];
        sum += a[i];
        if (vis[i]) {
            vis[i] = false;
            ans = std::max(ans, sum - i + 1);
        }
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        if (vis[i]) {
            ans = std::max(ans, sum - i + 1);
        }
    }
    
    std::cout << ans << "\n";

    return 0;
}