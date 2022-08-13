/**
 * @author: XiaFan
 * @date: 04-24 19:07
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    vector dp(n + 1, vector<i64>(2, 1e18));
    dp[0][0] = b;
    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == '1') {
            // 0 1 1 0
            // t t t t
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a + b * 2);
        } else {
            i64 dp1 = dp[i - 1][0] + a + b;           // 0->0
            i64 dp2 = dp[i - 1][1] + 2 * a + b;       // 1->0
            dp[i][0] = min(dp[i][0], min(dp1, dp2));  // <= 1e18
                                                      //
            i64 dp3 = dp[i - 1][0] + 2 * a + 2 * b;   // 0->1
            i64 dp4 = dp[i - 1][1] + a + 2 * b;       // 1->1
            dp[i][1] = min(dp[i][1], min(dp3, dp4));
        }
    }
    cout << dp[n][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}