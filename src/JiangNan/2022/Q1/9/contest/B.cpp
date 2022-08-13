/**
 * @author: XiaFan
 * @date: 05-08 19:40
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 k, x;
    cin >> k >> x;
    i64 ans = x + 9 * (k - 1);
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