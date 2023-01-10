/**
 * @author: XiaFan
 * @date: 06-07 18:29
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    i64 mod = 998244353;

    i64 sum = 1;
    for(i64 i = 2; i <= n; i++) {
        sum = (sum * i) % mod;
    }
    cout << sum;

    return 0;
}