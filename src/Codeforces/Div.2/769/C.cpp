/**
 * @author: XiaFan
 * @date: 05-18 23:00
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    int x = b - a;
    int ans = x;
    for (int i = 0; i < x; i++) {
        int y = ((a + i) | b) - b + i + 1;
        int z = (a | (b + i)) - (b + i) + i + 1;
        ans = min({ans, y, z});
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