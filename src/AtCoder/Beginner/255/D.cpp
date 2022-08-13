/**
 * @author: XiaFan
 * @date: 06-11 20:30
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    vector<i64> pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    while (q--) {
        i64 x;
        cin >> x;
        /*
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(x - a[i]);
        }
        cout << ans << " ";
        */

        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        i64 s1 = x * p - pref[p];
        i64 s2 = pref[n] - pref[p] - x * (n - p);
        cout << s1 + s2 << "\n";
    }

    return 0;
}