/**
 * @author: XiaFan
 * @date: 10-16 22:36
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::string s;
    std::cin >> s;
    std::map<int, char> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(a[i])) {
            mp[a[i]] = s[i];
        }
        if (mp[a[i]] != s[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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