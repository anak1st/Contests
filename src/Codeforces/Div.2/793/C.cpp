/**
 * @author: XiaFan
 * @date: 05-24 18:54
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 0;
    bool flag = true;
    for (auto [_, y] : mp) {
        if (y == 1) {
            ans++;
            if (flag) {
                flag = false;
                ans++;
            }
        } else if (y >= 2) {
            ans += 2;
        }
    }

    ans /= 2;
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