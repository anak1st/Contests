/**
 * @author: XiaFan
 * @date: 05-08 19:21
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    if (l == r && l != 1) {
        cout << "YES\n";
        return;
    }
    if (k == 0) {
        cout << "NO\n";
        return;
    }
    int one = (r + 1) / 2 - l / 2;

    if (one <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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