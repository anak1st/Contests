/**
 * @author: XiaFan
 * @date: 2023-01-18 13:40
 **/
#include <bits/stdc++.h>
#include <debug/vector>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    std::vector<int> b;
    for (auto [k, v] : mp) {
        b.push_back(v);
    }
    int sz = b.size();
    std::sort(b.begin(), b.end());
    // for (int i = 0; i < sz; i++) {
    //     std::cerr << b[i] << " \n"[i == sz - 1];
    // }
    std::vector<i64> sum(sz + 1);
    for (int i = 1; i <= sz; i++) {
        sum[i] = sum[i - 1] + b[i - 1];
    }
    for (i64 k = 1, i = -1; k <= n; k++) {
        while (i + 1 < sz && b[i + 1] <= k) {
            i++;
        }
        i64 ans = sum[i + 1] + 1LL * (k - 1) * (sz - i - 1);
        // std::cerr << i + 1 << " " << sum[i + 1] << " " << sz - i - 1 << "\n";
        std::cout << ans << "\n";
    }
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