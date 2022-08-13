/**
 * @author: XiaFan
 * @date: 08-05 17:48
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (auto &i : a) {
        std::cin >> i;
    }

    int min = a.front(), max = a.front();
    int ans = 0;
    for (auto &i : a) {
        min = std::min(min, i);
        max = std::max(max, i);
        if (max - min > 2 * x) {
            ans++;
            min = i;
            max = i;
        }
    }
    std::cout << ans << "\n";
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