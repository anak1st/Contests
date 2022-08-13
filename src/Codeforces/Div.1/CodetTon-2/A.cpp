/**
 * @author: XiaFan
 * @date: 08-05 17:38
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n1, n2;
    std::cin >> n1 >> n2;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    char c = s2.front();
    s2.erase(s2.begin());
    std::string s = s1.substr(0, n1 - n2 + 1);
    s1 = s1.substr(n1 - n2 + 1);
    if (s.find(c) != s.npos && s1 == s2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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