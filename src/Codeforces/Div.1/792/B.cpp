/**
 * @author: XiaFan
 * @date: 05-19 22:48
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    /**
     * @brief a < b < c
     * x % y = a
     * y % z = b
     * z % x = c
     *
     * x > y > z
     * x = a + b + c
     * y = b + c
     * z = c
     */
    int x = a + b + c;
    int y = b + c;
    int z = c;
    cout << x << " " << y << " " << z << "\n";
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