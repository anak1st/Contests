/**
 * @author: XiaFan
 * @date: 2023-02-03 15:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    i64 ans = 0;
    int limit = 100;
    for (int i = 2; i <= n; i++) {
        int x = i;
        if (1 < i - k) {
            x = 1;
        }
        for (int j = n; j > i + k && j >= n - limit + 1; j--) {
            int now = std::gcd(i, j);
            if (now < x) {
                x = now;
            }
            if (x == 1) {
                break;
            }
        }
        ans += x;
    }
    std::cout << ans << "\n";

    return 0;
}