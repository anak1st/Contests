/**
 * @author: XiaFan
 * @date: 05-13 19:24
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 h;
    cin >> n >> h;
    vector<i64> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    i64 left = 0, right = h - n + 1, k = 1;
    while (left <= right) {
        i64 mid = (left + right) / 2;
        i64 sum = mid;
        for (int i = 1; i < n; i++) {
            sum += min(mid, (a[i] - a[i - 1]));
        }
        // cout << "d:" << mid << " " << sum << "\n";
        if (sum >= h) {
            k = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << k << "\n";
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