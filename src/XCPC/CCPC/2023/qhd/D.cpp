/**
 * @author: XiaFan
 * @date: 2023-10-17 00:00
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<i64> b(n);
    for (int i = 0; i < m; i++) {
        int x;
        i64 y;
        std::cin >> x >> y;
        x--;
        b[x] += y;
    }

    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] < a[j]) {
            j = i;
        }
        a[j] -= b[i];
    }

    std::sort(a.begin(), a.end());
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        std::cout << sum << " \n"[i == n - 1];
    }
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