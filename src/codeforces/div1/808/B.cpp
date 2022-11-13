/**
 * @author: XiaFan
 * @date: 08-01 20:59
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++;
    }

    while (true) {
        int zero = mp.count(0) ? mp[0] : 0;
        if (n - zero <= 1) {
            break;
        }
        
        int j = -1;
        std::map<int, int> next;
        for (const auto &[i, cnt] : mp) {
            if (cnt > 1) {
                next[0] += cnt - 1;
            }
            if (j != -1) {
                next[i - j]++;
            }
            j = i;
        }

        mp = next;
        n--;
    }
    
    mp.erase(0);
    int ans = mp.empty() ? 0 : mp.begin()->first;
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