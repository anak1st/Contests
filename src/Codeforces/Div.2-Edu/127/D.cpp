/**
 * @author: XiaFan
 * @date: 04-30 17:31
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 x;
    cin >> n >> x;
    vector<i64> a(n);
    i64 _min = 2e5, _max = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        _min = min(_min, a[i]);
        _max = max(_max, a[i]);
    }

    i64 l = min(x, _min - 1);
    i64 r = max(0ll, x - _max);
    i64 ans = 0;
    i64 sl = 0, sr = 0;
    // cout << "l,r:" << l << " " << r << "\n";
    if(l > 0) {
        ans += l - 1;
        sl = min(abs(a[0] - l), abs(a[n - 1] - l));
    }
    if(r > 0) {
        ans += r - 1;
        sr = min(abs(a[0] - (_max + 1)), abs(a[n - 1] - (_max + 1)));
    }
    for(int i = 0; i < n - 1; i++) {
        ans += abs(a[i] - a[i + 1]);
        if(l > 0) {
            i64 cnt = abs(a[i] - 1) + abs(a[i] - l);
            sl = min(sl, cnt);
        }
        if(r > 0) {
            i64 cnt = abs(a[i] - (_max + 1)) + abs(a[i] - x);
            sr = min(sr, cnt);
        }
    }
    // cout << "debug:" << ans << " " << sl << " " << sr << "\n";
    cout << ans + sl + sr << "\n";
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