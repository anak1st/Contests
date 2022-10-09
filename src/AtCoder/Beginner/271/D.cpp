/**
 * @author: XiaFan
 * @date: 10-01 20:44
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    std::cin >> n >> s;
    std::vector<bool> ans(n + 1);
    std::vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) {
            ans[i] = !ans[i];
            std::swap(x, y);
        }
        sum += x;
        a[i] = y - x;
    }
    if (sum > s) {
        std::cout << "No\n";
        return 0;
    }
    s -= sum;

    std::vector dp(n + 1, std::vector<int>(s + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
            }
        }
    }

    if (dp[n][s] != s) {
        std::cout << "No\n";
        return 0;
    }

    int j = s;
    for (int i = n; i >= 1; i--) {
        if (j >= a[i] && dp[i][j] == dp[i - 1][j - a[i]] + a[i]) {
            ans[i] = !ans[i];
            j -= a[i];
        }
    }
    
    std::cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            std::cout << 'T';
        } else {
            std::cout << 'H';
        }
    }

    return 0;
}