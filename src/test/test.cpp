/**
 * @author: XiaFan
 * @date: 01-10 22:57
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            p[i].push_back(x);
        }
    }

    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)p[i].size(); j++) {
            mp[p[i][j]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < (int)p[i].size(); j++) {
            if (mp[p[i][j]] < 2) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) solve();

    return 0;
}