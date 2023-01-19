/**
 * @author: XiaFan
 * @date: 2023-01-18 17:22
 **/
#include <bits/stdc++.h>
using i64 = long long;

i64 fun(i64 n, i64 x) {
    return n / x + x - 1;
}

void solve() {
    i64 n, L, R;
    std::cin >> n >> L >> R;

    i64 x = std::sqrt(n) + 1;
    if (x <= L) {
        std::cout << L << "\n";
        return;
    }
    x = std::clamp(x, L, R);
    i64 fx = fun(n, x);
    i64 l = L, r = x, ans = x;
    while (l <= r) {
        i64 mid = (l + r) / 2;
        if (fun(n, mid) <= fx) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
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