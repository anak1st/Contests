/**
 * @author: XiaFan
 * @date: 05-05 15:43
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

const int p = 1e9 + 7;

bool palindromic(int x) {
    int t = x;
    int y = 0;
    while (t) {
        y = y * 10 + t % 10;
        t /= 10;
    }
    return x == y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    const int n = 4e4;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        if (palindromic(i)) {
            a.push_back(i);
        }
    }
    int m = a.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = a[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - a[i]]) % p;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }
    return 0;
}