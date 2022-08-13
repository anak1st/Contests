/**
 * @author: XiaFan
 * @date: 05-08 19:02
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 x;
    cin >> x;
    int z = x % 11;
    if (x >= z * 111) {
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