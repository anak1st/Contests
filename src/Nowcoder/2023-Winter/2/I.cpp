/**
 * @author: XiaFan
 * @date: 2023-01-18 16:28
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e17;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    d++;

    std::array<int, 5> v;
    for (int i = 0; i < 5; i++) {
        std::cin >> v[i];
    }

    i64 res = 0;
    std::vector<std::pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        res += v[0];
        events.emplace_back(a - x[i], v[1] - v[0]);
        events.emplace_back(b - x[i], v[2] - v[1]);
        events.emplace_back(c - x[i], v[3] - v[2]);
        events.emplace_back(d - x[i], v[4] - v[3]);
    }
    i64 ans = res;
    std::sort(events.begin(), events.end());
    int pre = -1;
    for (auto [k, x] : events) {
        res += x;
        ans = std::max(ans, res);
        pre = k;
    }
    ans = std::max(ans, res);
    std::cout << ans << "\n";
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