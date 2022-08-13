/**
 * @author: XiaFan
 * @date: 05-15 19:43
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    int maxa = 2e5;
    vector<int> a(maxa + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    vector<int> dp(maxa + 1, 0);
    for (int i = 1; i <= maxa; i++) {
        dp[i] += a[i];
        for (int j = i; j <= maxa; j += i) {
            dp[j] = max(dp[j], dp[i]);
        }
    }
    cout << n - *max_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}