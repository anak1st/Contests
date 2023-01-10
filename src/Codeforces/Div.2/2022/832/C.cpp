/**
 * @author: XiaFan
 * @date: 11-05 20:37
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    a[0]--;
    if (std::count(a.begin(), a.end(), a[0]) == 1 &&
        std::min_element(a.begin(), a.end()) == a.begin()) {
        std::cout << "Bob\n";
    } else {
        std::cout << "Alice\n";
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