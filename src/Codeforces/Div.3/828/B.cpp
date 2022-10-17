/**
 * @author: XiaFan
 * @date: 10-16 22:40
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> cnt(2), sum(2);
    for (int i = 0; i < n; i++) {
        i64 x;
        std::cin >> x;
        cnt[x % 2]++;
        sum[x % 2] += x;
    }

    while (q--) {
        i64 t, e;
        std::cin >> t >> e;
        if (e % 2 == 0) {
            sum[t] += e * cnt[t];
        } else {
            sum[(t + 1) % 2] += sum[t] + e * cnt[t];
            cnt[(t + 1) % 2] += cnt[t];
            sum[t] = 0;
            cnt[t] = 0;
        }
        
        std::cout << sum[0] + sum[1] << "\n";
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