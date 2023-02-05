/**
 * @author: XiaFan
 * @date: 2023-01-28 21:44
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n, 0);
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        x--;
        a[x]++;
    }
    i64 ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            while (a[i]--) {
                ans /= 3;
            }
        } else {
            ans *= 2;
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