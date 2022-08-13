/**
 * @author: XiaFan
 * @date: 05-24 18:26
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = n / 2;
    int ans = 0;
    for (int i = p; i >= 0; i--) {
        if (s[i] == s[p]) {
            ans++;
        } else {
            break;
        }
    }
    for (int i = p + 1; i < n; i++) {
        if (s[i] == s[p]) {
            ans++;
        } else {
            break;
        }
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