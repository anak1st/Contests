/**
 * @author: XiaFan
 * @date: 08-10 23:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string t;
    std::cin >> t;
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto &i : s) {
        std::cin >> i;
    }
    int step = -1, next = -1;
    std::pair<int, int> c;
    std::vector<std::pair<int, int>> ans;
    
    int tlen = t.length();
    for (int i = 0; i < tlen; i++) {
        for (int j = 0; j < n; j++) {
            int slen = s[j].length();
            if (i + slen - 1 >= tlen) {
                continue;
            }
            auto ss = t.substr(i, slen);
            if (i + slen - 1 > next && s[j] == ss) {
                c = {j, i};
                next = i + slen - 1;
            }
        }
        if (step < i) {
            step = next;
            ans.push_back(c);
        }
        if (step < i) {
            std::cout << "-1\n";
            return;
        }
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x + 1 << " " << y + 1 << "\n";
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