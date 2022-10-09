/**
 * @author: XiaFan
 * @date: 09-30 19:02
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        mp[{x, y}]++;
    }
    int ans = 0;
    for (auto [t, c] : mp) {
        ans = std::max(ans, c);
    }
    std::cout << ans;
    
    return 0;
}