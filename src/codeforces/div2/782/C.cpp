/**
 * @author: XiaFan
 * @date: 04-21 19:33
 **/
#include <bits/stdc++.h>

typedef long long i64;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<i64> x(n);
    for(int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    std::vector<i64> right(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        right[i] += right[i + 1] + x[i];
    }
    i64 capital = 0;
    i64 cost = 0;
    i64 ans = b * right[0];
    for(int i = 0; i < n; i++) {
        cost += (a + b) * (x[i] - capital);
        capital = x[i];
        i64 rightcost = b * (right[i + 1] - (n - i - 1) * capital);
        ans = std::min(ans, cost + rightcost);
        // std::cout << "cost:" << cost + rightcost << '\n';
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}