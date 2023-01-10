/**
 * @author: XiaFan
 * @date: 05-03 18:25
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    i64 m, n;
    cin >> m >> n;
    i64 maxa = 1ll << m;
    if (m == 1) {
        // 0 1
        if (n == 0) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    } else if (n == 0) {
        cout << maxa << "\n";
    } else {
        cout << maxa - 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}