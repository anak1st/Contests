/**
 * @author: XiaFan
 * @date: 05-10 08:17
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << "\n";

    return 0;
}