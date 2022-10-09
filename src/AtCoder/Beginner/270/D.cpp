/**
 * @author: XiaFan
 * @date: 09-28 19:44
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, -1));

    std::function<int (int, int)> dfs = [&](int x, int i) -> int {
        if (x == 0) {
            return 0;
        }
        if (dp[x][i] != -1) {
            return dp[x][i];
        }
        int res;
        if (i) {
            res = -1e5;
            for (int i = 1; i <= k; i++) {
                if (a[i] <= x) {
                    res = std::max(res, dfs(x - a[i], 0) + a[i]);
                }
            }
        } else {
            res = 1e5;
            for (int i = 1; i <= k; i++) {
                if (a[i] <= x) {
                    res = std::min(res, dfs(x - a[i], 1) - a[i]);
                }
            }
        }
        dp[x][i] = res;
        return dp[x][i];
    };

    std::cout << (n + dfs(n, 1)) / 2;

    return 0;
}