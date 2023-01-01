/**
 * @author: XiaFan
 * @date: 12-30 18:29
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int N = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        N |= a[i];
    }

    std::vector<int> mp(N + 1);
    i64 ans = 0;
    int xsum = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        int add = i + 1;
        xsum ^= a[i];
        for (int j = 0; j < 600; j++) {
            int f = (j * j) ^ xsum;
            if (f <= N) {
                add -= mp[f];
            }   
        }
        ans += add;
        mp[xsum]++;
    }

    std::cout << ans << "\n";
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