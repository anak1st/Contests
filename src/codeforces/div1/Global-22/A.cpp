/**
 * @author: XiaFan
 * @date: 09-30 22:27
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    i64 sum = std::accumulate(b.begin(), b.end(), 0LL);
    std::vector<i64> c[2];
    for (int i = 0; i < n; i++) {
        c[a[i]].push_back(b[i]);
    }
    std::sort(c[0].begin(), c[0].end(), std::greater<i64>());
    std::sort(c[1].begin(), c[1].end(), std::greater<i64>());
    if (c[0].size() == c[1].size()) {
        std::cout << sum * 2 - std::min(c[0].back(), c[1].back()) << "\n";
    } else {
        int k = std::min(c[0].size(), c[1].size());
        if (k == 0) {
            std::cout << sum << "\n";
            return;
        }
        i64 s[2];
        s[0] = std::accumulate(c[0].begin(), c[0].begin() + k, 0LL);
        s[1] = std::accumulate(c[1].begin(), c[1].begin() + k, 0LL);
        i64 ans = std::max(ans, sum + s[0] + s[1]);
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}