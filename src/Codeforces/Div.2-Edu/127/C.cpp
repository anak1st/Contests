/**
 * @author: XiaFan
 * @date: 04-28 10:02
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        i64 day = 0;
        if(a[i] <= x) {
            // a1 + ... + a[i] + i * day <= x
            day = (x - a[i]) / (i + 1) + 1;
        }
        // day1 + day2 + ... + dayi = ans
        ans += day;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}