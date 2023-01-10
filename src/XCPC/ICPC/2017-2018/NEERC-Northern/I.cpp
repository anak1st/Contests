/**
 * @author: XiaFan
 * @date: 01-09 21:39
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // using std::cin, std::cout;
    std::ifstream cin("intel.in");
    std::ofstream cout("intel.out");

    int n;
    cin >> n;
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
    cout << ans;

    return 0;
}