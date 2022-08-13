/**
 * @author: XiaFan
 * @date: 06-11 20:19
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 x, a, d, n;
    cin >> x >> a >> d >> n;
    x -= a;
    if (d < 0) {
        d = -d;
        x = -x;
    }
    if (d == 0 || x <= 0) {
        cout << abs(x);
    } else if (x <= d * (n - 1)) {
        x %= d;
        cout << min(x, d - x);
    } else {
        cout << x - (n - 1) * d;
    }

    return 0;
}