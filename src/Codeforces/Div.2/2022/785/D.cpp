/**
 * @author: XiaFan
 * @date: 05-10 18:58
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

i64 lcm(i64 x, i64 y) {
    i64 g = gcd(x, y);
    return x * y / g;
}

void solve() {
    i64 b1, bd, bn;
    i64 c1, cd, cn;
    cin >> b1 >> bd >> bn;
    cin >> c1 >> cd >> cn;
    i64 be = b1 + (bn - 1) * bd;
    i64 ce = c1 + (cn - 1) * cd;
    // b1 c1 ce be
    if (c1 < b1 || ce > be || ce < b1 || c1 > be || cd % bd || (c1 - b1) % bd) {
        cout << "0\n";
        return;
    } else if (c1 - cd < b1 || ce + cd > be) {
        cout << "-1\n";
        return;
    }
    i64 ans = 0;
    for (i64 i = 1; i * i <= cd; i++) {
        if (cd % i) {
            continue;
        }
        if (lcm(i, bd) == cd) {
            i64 a = (cd / i) * (cd / i) % mod;
            ans = (ans + a) % mod;
        }
        if (i * i != cd && lcm(cd / i, bd) == cd) {
            i64 a = i * i % mod;
            ans = (ans + a) % mod;
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