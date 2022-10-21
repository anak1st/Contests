/**
 * @author: XiaFan
 * @date: 10-18 20:01
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::deque<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    while (!a.empty()) {
        while (!a.empty() && a.front() == 0) {
            a.pop_front();
        }
        while (!a.empty() && a.back() == 1) {
            a.pop_back();
        }
        if (!a.empty() && a.front() == 1 && a.back() == 0) {
            a.pop_front();
            a.pop_back();
            ans++;
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