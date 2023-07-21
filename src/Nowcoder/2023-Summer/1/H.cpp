/**
 * @author: XiaFan
 * @date: 2023-07-17 14:09
 */
#include <bits/stdc++.h>

using i64 = long long;


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 3>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][1];
    }
    
    
    i64 dif = 0;
    for (int i = 0; i < n; i++) {
        dif += std::abs(a[i][0] - a[i][1]);
        if (a[i][0] > a[i][1]) {
            std::swap(a[i][0], a[i][1]);
            a[i][2] = 1;
        }
    }

    std::sort(a.begin(), a.end());
    
    i64 ans = 0;
    for (int i = 0; i + 1 < n;) {
        int j = i + 1;
        while (j < n) {
            if (a[i][2] != a[j][2]) 
                ans = std::max(ans, std::min(a[i][1], a[j][1]) - a[j][0]);
            
            if (a[j][1] > a[i][1]) break;
            j++;
        }
        i = j;
    }
    // std::cerr << dif << " " << ans << '\n';

    dif -= 2 * ans;

    std::cout << dif << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}