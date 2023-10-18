/**
 * @author: XiaFan
 * @date: 2023-10-16 23:48
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int B = 13;

void solve() {
    int n, w;
    std::cin >> n >> w;
    std::vector<int> a(B);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[x - 1]++;
    }
    std::vector<std::pair<int, int>> b(1 << B, {-1, -1});
    b[0] = {1, 0};

    auto get = [&](auto &&get, int x) {
        if (b[x].first != -1) {
            return b[x];
        }
        b[x] = {2 * B, 0};

        for (int i = 0; i < B; i++) {
            if (x >> i & 1) {
                auto res = get(get, x ^ (1 << i));
                if (res.second + a[i] <= w) {
                    res.second += a[i];
                } else {
                    res.first++;
                    res.second = a[i];
                }
                b[x] = std::min(b[x], res);
            }
        }

        return b[x];
    };

    std::cout << get(get, (1 << B) - 1).first << '\n';
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