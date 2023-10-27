/**
 * @author: XiaFan
 * @date: 2023-10-24 21:11
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<int> a(26);
    for (char c : s) {
        a[c - 'a']++;
    }
    int ans = s.length();
    for (int i = 0; i < 26; i++) {
        ans = std::min(ans, (int)s.length() - a[i]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}