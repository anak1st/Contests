/**
 * @author: XiaFan
 * @date: 11-01 20:22
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> a(128);
    for (auto c : s) {
        a[c]++;
    }

    int j = 0;
    // bones
    if (a['b'] > 0 || a['B'] > 0) {
        j++;
    }
    if (a['o'] > 0 || a['O'] > 0) {
        j++;
    }
    if (a['n'] > 0 || a['N'] > 0) {
        j++;
    }
    if (a['e'] > 0 || a['E'] > 0) {
        j++;
    }
    if (a['s'] > 0 || a['S'] > 0) {
        j++;
    }
    
    if (j == 5) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}