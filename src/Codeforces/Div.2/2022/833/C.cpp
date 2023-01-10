/**
 * @author: XiaFan
 * @date: 11-13 13:12
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

    std::map<i64, i64> mp;
    i64 end = -1, ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (end == -1) {
                ans += mp[0];
            } else {
                i64 x = 0, y = 0;
                for (auto [val, cnt] : mp) {
                    if (cnt > y) {
                        x = val;
                        y = cnt;
                    }
                }
                ans += y;
                a[end] = x;
            }

            end = i;
            mp.clear();
            sum = 0;
        }

        sum += a[i];
        mp[sum]++;
    }

    if (end == -1) {
        ans += mp[0];
    } else {
        i64 x = 0, y = 0;
        for (auto [val, cnt] : mp) {
            if (cnt > y) {
                x = val;
                y = cnt;
            }
        }
        ans += y;
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