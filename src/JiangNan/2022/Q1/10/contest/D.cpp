/**
 * @author: XiaFan
 * @date: 05-15 20:06
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int P = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int ans = count(s.begin(), s.end(), 'a');
    if (ans == 0) {
        cout << "0\n";
        return 0;
    }
    vector<i64> a;
    i64 c = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'a') {
            c++;
        } else if (s[i] == 'b' && c != 0) {
            a.push_back(c);
            c = 0;
        }
    }
    if (c) {
        a.push_back(c);
    }
    int n = a.size();
    vector<i64> dp(n);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = (dp[i - 1] + a[i] * dp[i - 1] + a[i]) % P;
    }
    cout << dp[n - 1] << "\n";

    return 0;
}