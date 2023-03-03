/**
 * @author: XiaFan
 * @date: 07-16 18:33
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    vector<i64> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    i64 ans = 0;
    for (int i = n; i >= 0; i--) {
        i64 suf = 0;
        i64 d = 2;
        for (int j = i + 1; j <= n; j++) {
            suf += a[j] / d;
            d *= 2LL;
            if (d >= 1e12) {
                break;
            }
        }
        i64 tmp = pref[i] - (i64)i * k + suf;
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}