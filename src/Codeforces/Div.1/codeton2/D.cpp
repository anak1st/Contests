/**
 * @author: XiaFan
 * @date: 08-07 15:29
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1));
    std::vector<i64> pref(n + 1, 0);
    std::map<i64, int> cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
            pref[i] += a[i][j] * j;
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt[pref[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[pref[i]] == 1) {
            ans = i;
            break;
        }
    }
    i64 step = pref[ans] - std::min(pref[1], pref[2]);
    std::cout << ans << " " << step << "\n";
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