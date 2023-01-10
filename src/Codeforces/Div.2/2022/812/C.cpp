/**
 * @author: XiaFan
 * @date: 08-18 18:05
 **/
#include <bits/stdc++.h>
using i64 = long long;


bool judge(int x) {
    int y = sqrt(x);
    return y * y == x;
}


void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> ans(n, -1);
    int x = std::sqrt(n - 1) + 1;
    // std::cerr << x << "\n";
    for (int i = n - 1; i >= 0; i--) {
        while (x * x - i >= n || ans[x * x - i] != -1) {
            x--;
        }
        if (0 <= x * x - i && x * x - i < n) {
            ans[x * x - i] = i;
        } else {
            // std::cerr << "error\n";
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
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