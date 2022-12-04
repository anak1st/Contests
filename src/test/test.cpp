/**
 * @author: XiaFan
 * @date: 12-04 13:34
 **/
#include <bits/stdc++.h>
#include "xf.hpp"

#ifndef DEBUG_XF
#define printIn(...)
#endif

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 sum = std::reduce(a.begin(), a.end());
    sum %= m;
    
    i64 c1 = n;
    i64 c2 = (n + 1) * n / 2;
    i64 lcm = std::lcm(c1, c2);
    // printIn("c1", c1, "c2", c2, "lcm", lcm);
    // res = (s * c1 + d * c2 + sum) % m
    i64 ans = m, s, d;
    std::vector<std::pair<i64, i64>> pre(std::max(m, lcm) + 1, {-1, -1});
    pre[0] = {0LL, 0LL};
    for (int i = 0; i < pre.size(); i++) {
        if (pre[i] == std::pair<i64, i64>{-1, -1}) continue;
        if (pre[i + c1] == std::pair<i64, i64>{-1, -1}) {
            pre[i + c1] = pre[i];
            pre[i + c1].first++;
        }
        if (pre[i + c2] == std::pair<i64, i64>{-1, -1}) {
            pre[i + c2] = pre[i];
            pre[i + c2].second++;
        }
        auto [ts, td] = pre[i];
        if (ans > (ts * c1 + td * c2 + sum) % m) {
            ans = (ts * c1 + td * c2 + sum) % m;
            s = ts;
            d = td;
        }
    }
    // printIn(pre);
    std::cout << ans << "\n" << s << " " << d;
    
    return 0;
}