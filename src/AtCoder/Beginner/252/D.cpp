/**
 * @author: XiaFan
 * @date: 05-25 21:55
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    vector<i64> b;
    for (auto [_, y] : mp) {
        b.push_back(y);
    }
    int m = b.size();
    /*
    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            ans += b[i] * b[j] * (n - b[i] - b[j]);
        }
    }
    cout << ans / 3 << "\n";
    */

    vector dp(m + 1, vector<i64>(3));
    for (int i = 0; i < m; i++) {
        dp[i + 1][0] = dp[i][0] + b[i];
        dp[i + 1][1] = dp[i][1] + dp[i][0] * b[i];
        dp[i + 1][2] = dp[i][2] + dp[i][1] * b[i];
    }
    cout << dp[m][2];

    return 0;
}