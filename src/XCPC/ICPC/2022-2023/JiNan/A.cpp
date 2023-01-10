/**
 * @author: XiaFan
 * @date: 11-27 17:14
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    i64 z = n - m;

    std::vector<i64> a(n);
    for (auto& it : a) std::cin >> it;

    auto fun = [&](i64 from, i64 to) -> i64 {
        if (from <= to) {
            return std::abs(from - to);
        } else {
            i64 cnt = 0, ans = std::abs(from - to);
            while (from >= to) {
                from /= 2;
                cnt++;
                i64 temp = cnt + std::abs(from - to);
                ans = std::min(ans, temp);
            }
            return ans;
        }
    };

    auto check = [&](i64 to) -> i64 {
        std::vector<i64> b;
        for (auto it : a) b.push_back(fun(it, to));
        std::nth_element(b.begin(), b.begin() + z, b.end());
        // print(b);
        return std::accumulate(b.begin(), b.begin() + z, 0LL);
    };

    i64 ans = 1e18;
    for (auto it : a) {
        while (it > 0) {
            i64 res = check(it);
            ans = std::min(ans, res);
            it /= 2;
        }
    }

    std::cout << ans << "\n";
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