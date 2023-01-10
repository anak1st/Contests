/**
 * @author: XiaFan
 * @date: 09-27 20:04
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    std::vector<int> a(10, 0);
    for (int i = 0; i < int(s.length()); i++) {
        int num = s[i] - '0';
        a[num]++;
    }
    std::string t;
    for (int i = 0, j = 0; i < int(s.length()); i++) {
        int num = s[i] - '0';
        while (a[j] == 0 && j + 1 <= 9) {
            j++;
        }
        if (num == j) {
            t.push_back(num + '0');
        } else {
            t.push_back(std::min(num + 1, 9) + '0');
        }
        a[num]--;
    }
    std::sort(t.begin(), t.end());
    std::cout << t << "\n";
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