/**
 * @author: XiaFan
 * @date: 11-08 19:30
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    // i64 sum = std::accumulate(a.begin(), a.end(), 0LL);

    std::map<i64, i64> mp, use;
    std::vector<std::pair<int, int>> p(k);
    for (int i = 0; i < k; i++) {
        i64 x, y;
        std::cin >> x >> y;
        mp[x] = y;
        p[i] = {x, y};
    }
    std::sort(p.begin(), p.end());

    i64 end = 0, j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (; j < k && p[j].first < a[i]; j++) {
            if (p[j].second == 0) {
                end = p[j].first + 1;
            }
        }
        while (mp.count(end) && use[end] == mp[end]) {
            end++;
        }
        use[end]++;
        // std::cerr << i << " " << a[i] - end << "\n";
        ans += a[i] - end;
    }

    // std::cerr << ans << "\n";
    if (ans % 2 == 0) {
        std::cout << "FuuFuu\n";
    } else {
        std::cout << "Pico\n";
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