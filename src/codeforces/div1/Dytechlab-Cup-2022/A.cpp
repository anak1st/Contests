/**
 * @author: XiaFan
 * @date: 10-10 20:11
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> a(26);
    for (auto c : s) {
        a[c - 'a']++;
    }

    std::string ans;

    for (int i = 0; i < k; i++) {
        int cnt = 0;
        int x = -1;
        for (int j = 0; j <= std::min(n / k - 1, 25); j++) {
            if (a[j] == 0) {
                x = j;
                break;
            } else {
                a[j]--;
                cnt++;
            }
        }
        
        if (x == -1) {
            x = n / k;
        }
        ans.push_back('a' + x);
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