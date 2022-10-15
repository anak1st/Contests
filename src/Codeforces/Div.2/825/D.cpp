#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    
    std::vector<int> ans;
    int need = 0, freq = 0;
    
    for (int i = 0; i < 2 * n; i += 2) {
        if (s[i] != s[i + 1]) {
            freq++;
            ans.push_back(i);
            if (s[i] - '0' != need) {
                ans.back()++;
            }
            need ^= 1;
        }
    }
    if (freq % 2 == 1) {
        std::cout << "-1\n";
        return;
    }

    std::cout << ans.size() << " ";
    for (auto it : ans) {
        std::cout << it + 1 << " ";
    }
    std::cout << "\n";
    for (int i = 1; i <= n; i++) {
        std::cout << 2 * i - 1 << " \n"[i == n];
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
}