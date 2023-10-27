/**
 * @author: XiaFan
 * @date: 2023-10-19 12:31
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) {
        std::cin >> x;
    }

    std::sort(a.begin(), a.end(), std::greater<>());

    int ans = std::max({0, a[0], a[0] + a[1]});
    std::cout << ans << '\n';
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