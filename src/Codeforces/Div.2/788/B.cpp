/**
 * @author: XiaFan
 * @date: 05-09 19:33
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n;
    string s;
    cin >> s;
    cin >> k;
    vector<bool> c(26, false);
    for (int i = 0; i < k; i++) {
        char cc;
        cin >> cc;
        int index = cc - 'a';
        c[index] = true;
    }
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        int index = s[i] - 'a';
        if (c[index]) {
            ans = max(ans, i - j);
            j = i;
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