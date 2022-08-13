/**
 * @author: XiaFan
 * @date: 05-24 18:33
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != i && ok) {
            ok = false;
            ans = a[i];
        }
        if (a[i] != i && !ok) {
            ans &= a[i];
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