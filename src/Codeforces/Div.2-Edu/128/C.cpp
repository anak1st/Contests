/**
 * @author: XiaFan
 * @date: 05-14 10:06
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s = '#' + s;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i] == '0');
    }
    int ans = a[n];
    int len = n - a[n];
    for (int i = len; i <= n; i++) {
        ans = min(ans, a[i] - a[i - len]);
    }
    cout << ans << "\n";
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