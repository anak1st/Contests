/**
 * @author: XiaFan
 * @date: 10-17 22:49
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 ans = 0;
    std::vector<int> Q;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            Q.push_back(i);
            int k = -1;
            for (int j = 0; j < int(Q.size()); j++) {
                if (k == -1 || a[Q[j]] > a[Q[k]]) {
                    k = j;
                }
            }
            ans += a[Q[k]];
            Q.erase(Q.begin() + k);
        } else {
            Q.clear();
            Q.push_back(i);
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