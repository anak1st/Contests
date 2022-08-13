/**
 * @author: XiaFan
 * @date: 2022-04-10 19:25:49
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, x, y, n;
    std::cin >> a >> b >> x >> y >> n;
    i64 ans = a * b, newa, newb, newn;
    newb = std::max(y, b - n);
    newn = n - (b - newb);
    newa = std::max(x, a - newn);

    ans = std::min(ans, newa * newb);
    // std::cout << newa << ' ' << newb << ' ' << ans << '\n';

    newa = std::max(x, a - n);
    newn = n - (a - newa);
    newb = std::max(y, b - newn);
    // std::cout << newa << ' ' << newb << ' ' << ans << '\n';

    ans = std::min(ans, newa * newb);

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}