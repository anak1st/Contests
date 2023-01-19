/**
 * @author: XiaFan
 * @date: 2023-01-18 17:22
 **/
#include <bits/stdc++.h>
using i64 = long long;

i64 fun(i64 n, i64 x) {
    return n / x + x - 1;
}
i64 get_min(i64 n) {
    i64 L = sqrt(n) - 6000;
    L = std::max(L, 1LL);
    i64 R = sqrt(n);
    i64 ansx = L;
    for (i64 x = L; x <= R; x++) {
        if (fun(n, x) < fun(n, ansx)) {
            ansx = x;
        }
    }
    return ansx;
}

void solve() {
    i64 n, L, R;
    std::cin >> n >> L >> R;
    i64 ans = get_min(n);
    // std::cerr << ans << "\n";
    if (ans < L) {
        ans = L;
        for (int i = 1; i < 5000; i++) {
            i64 x = L + i;
            if (x > R) {
                break;
            }
            if (fun(n, x) < fun(n, ans)) {
                ans = x;
            }
        }
    } else if (ans > R) {
        ans = R;
        for (int i = 1; i < 5000; i++) {
            i64 x = R - i;
            if (x < L) {
                break;
            }
            if (fun(n, x) < fun(n, ans)) {
                ans = x;
            }
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