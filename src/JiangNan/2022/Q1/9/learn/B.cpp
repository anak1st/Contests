/**
 * @author: XiaFan
 * @date: 05-02 09:03
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    i64 a, b;
    cin >> a >> b;
    b %= 9973;
    while(a % b) {
        a += 9973;
    }
    i64 ans = (a / b) % 9973;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}