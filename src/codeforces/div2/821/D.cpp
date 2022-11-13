#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve() {
    int n;
    i64 x, y;
    std::cin >> n >> x >> y;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char ch;
        std::cin >> ch;
        a[i] ^= ch - '0';
    }
    for (int i = 0; i < n; i++) {
        char ch;
        std::cin >> ch;
        a[i] ^= ch - '0';
    }

    int cnt = std::accumulate(a.begin(), a.end(), 0);
    if (cnt % 2 != 0) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<int> pos;

    for (int i = 0; i < n; i++) {
        if (a[i]) {
            pos.push_back(i);
        }
    }

    if (x >= y) {
        if (cnt != 2) {
            std::cout << (cnt / 2) * y << "\n";
            return;
        }
        if (pos[1] > pos[0] + 1) {
            std::cout << y << "\n";
            return;
        }
        i64 ans = x;
        if (n > 2) {
            ans = std::min(ans, 2 * y);
        }
        std::cout << ans << "\n";
        return;
    }

    std::vector dp(cnt, std::vector<i64>(cnt, -1));

    auto get = [&](int l, int r) -> i64 {
        if (l + 1 == r) {
            return std::min(2 * y, x);
        } else {
            return std::min(y, x * (r - l));
        } 
    };

    std::function<i64(int, int)> dfs = [&](int l, int r) -> i64 {
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        i64 res = 1e18;
        res = std::min(res, dfs(l + 1, r - 1) + get(pos[l], pos[r]));
        res = std::min(res, dfs(l, r - 2) + get(pos[r - 1], pos[r]));
        res = std::min(res, dfs(l + 2, r) + get(pos[l], pos[l + 1]));
        dp[l][r] = res;
        return dp[l][r];
    };

    std::cout << dfs(0, cnt - 1) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}