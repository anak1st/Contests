/**
 * @author: XiaFan
 * @date: 2023-02-15 19:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

bool judge(i64 x) {
    i64 y = std::sqrt(x);
    return y * y == x;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // ai + b = A * A
    // aj + b = B * B
    // A * A - B * B = aj - ai
    // (B - A) * (B + A) = aj - ai
    // x * y = aj - ai
    // A = (y - x) / 2
    // B = (y + x) / 2

    auto calc = [&](i64 x) -> int {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += judge(a[i] + x);
        }
        return res;
    };

    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            i64 d = a[j] - a[i];
            for (i64 x = 1; x * x <= d; x++) {
                if (d % x) continue;
                i64 y = d / x;
                if ((y - x) % 2) continue;
                i64 A = (y - x) / 2;
                i64 B = (y + x) / 2;
                i64 b = A * A - a[i];
                if (b < 0) continue;
                ans = std::max(ans, calc(b));
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