/**
 * @author: XiaFan
 * @date: 08-05 18:26
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (auto &i : a) {
        std::cin >> i;
    }
    if (m == 1) {
        std::cout << 2 << "\n";
        return;
    }
    std::sort(a.begin(), a.end());
    std::vector<int> b(m);
    for (int i = 0; i < m - 1; i++) {
        b[i] = a[i + 1] - a[i] - 1;
    }
    b.back() = n - a.back() + a.front() - 1;
    std::sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int temp = b[i] - 4 * i;
        if (temp > 0) {
            ans += std::max(1, temp - 1);
        }
    }
    std::cout << n - ans << "\n";
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