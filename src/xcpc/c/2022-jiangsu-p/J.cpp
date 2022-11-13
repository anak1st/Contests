/**
 * @author: XiaFan
 * @date: 05-29 11:04
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    function<u64(u64)> g = [&](u64 x) -> u64 {
        u64 a = 1, b = 0, c = 0;
        while (x / 2 >= 1) {
            if (x % 2 == 0) {
                a = a;
                b = a + 2 * b;
                c = c + a;
            } else {
                a = 2 * a + b;
                b = b;
                c = c + b;
            }
            // cerr << x << " " << a << " " << b << " " << c << "\n";
            x /= 2;
        }
        return c;
    };

    int t;
    cin >> t;
    while (t--) {
        u64 x;
        cin >> x;
        u64 c = g(x);
        u64 ans = 0;
        if (c < 64) {
            ans = 1ull << c;
        }
        cout << ans << "\n";
    }

    return 0;
}