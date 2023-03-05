/**
 * @author: XiaFan
 * @date: 10-16 23:01
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

    auto fun = [](int x) -> int {
        int res = 0;
        while (x % 2 == 0) {
            x /= 2;
            res++;
        }
        return res;
    };

    int x = 0;
    std::vector<int> add;
    for (int i = 0; i < n; i++) {
        x += fun(a[i]);
        if ((i + 1) % 2 == 0) {
            add.push_back(fun(i + 1));
        }
    }

    int ans = 0;
    std::sort(add.begin(), add.end());
    while (x < n && !add.empty()) {
        x += add.back();
        add.pop_back();
        ans++;
    }

    if (x < n) {
        ans = -1;
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