/**
 * @author: XiaFan
 * @date: 10-16 22:53
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    char c;
    std::cin >> c;
    std::string s;
    std::cin >> s;
    if (n == 1) {
        std::cout << "0\n";
        return;
    }

    int p = s.find('g');
    std::vector<int> a(n, -10000);
    a[p] = 0;
    for (int i = 0; i < n; i++) {
        int j = (n + p - i - 1) % n;
        int k = (n + p - i) % n;
        if (s[j] == 'g') {
            a[j] = 0;
        } else {
            a[j] = a[k] + 1;
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            max = std::max(max, a[i]);
        }
    }
    std::cout << max << "\n";
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