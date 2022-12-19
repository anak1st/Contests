/**
 * @author: XiaFan
 * @date: 12-18 10:50
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(m);
    for (auto &x : a) std::cin >> x;
    std::sort(a.begin(), a.end(), std::greater<int>());
    for (auto &x : a) std::cout << x << ' ';
    std::cout << '\n';

    for (int i = 0; i < m; i++) {
        int max = n / k;
        if (i < n % k) max++;
        if (a[i] > max) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    
    return 0;
}