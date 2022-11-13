/**
 * @author: XiaFan
 * @date: 07-16 18:08
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
    vector<int> b;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < i + 1) {
            ans += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            b.push_back(i + 1);
        }
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