/**
 * @author: XiaFan
 * @date: 05-08 20:05
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int p = 1000000007;

i64 mpower(i64 a, i64 x) {
    a %= p;
    i64 res = 1;
    while (x) {
        if (x % 2) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 bit = mpower(2, n - 1);
    i64 res = 0;

    if (n % 2 == 0) {
        for (int i = 0; i < k; i++) {
            res = (res + mpower(bit - 1, i) * mpower(2 * bit, k - 1 - i) % p) % p;
        }
        res = (res + mpower(bit - 1, k)) % p;
    } else {
        res = mpower(bit + 1, k);
    }

    std::cout << res << "\n";
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