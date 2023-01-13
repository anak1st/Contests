/**
 * @author: XiaFan
 * @date: 2023-01-09 21:39
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    freopen("intel.in", "r", stdin);
    freopen("intel.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        ans += std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
    }
    auto [minx, maxx] = std::minmax_element(x.begin(), x.end());
    auto [miny, maxy] = std::minmax_element(y.begin(), y.end());
    ans -= 2 * (*maxx - *minx + *maxy - *miny);
    std::cout << ans;

    return 0;
}