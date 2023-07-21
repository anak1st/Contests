/**
 * @author: XiaFan
 * @date: 2023-07-17 12:48
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    if (m * n != 1) {
        std::cout << "Kelin" << std::endl;
    } else {
        std::cout << "Walk Alone" << std::endl;
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