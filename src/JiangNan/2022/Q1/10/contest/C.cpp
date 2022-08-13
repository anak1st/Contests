/**
 * @author: XiaFan
 * @date: 05-15 19:11
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int j1 = min(a, b);
        int j2 = (a + b + c) / 3;
        int ans = min(j1, j2);
        cout << ans << "\n";
    }

    return 0;
}