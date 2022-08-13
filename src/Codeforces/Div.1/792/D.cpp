/**
 * @author: XiaFan
 * @date: 05-21 13:19
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        a[i] -= (n - i - 1);
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < k; i++) {
        sum -= a[i];  // sum - a[ii] + (n - ii + 1)
    }
    sum -= 1LL * k * (k - 1) / 2;
    cout << sum << "\n";
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