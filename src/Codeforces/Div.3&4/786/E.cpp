/**
 * @author: XiaFan
 * @date: 05-08 15:03
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1e6;
    for (int i = 0; i < n - 1; i++) {
        int times = (a[i] + a[i + 1] + 2) / 3;
        if (a[i] >= a[i + 1] * 2) {
            times = (a[i] + 1) / 2;
        }
        if (a[i + 1] >= a[i] * 2) {
            times = (a[i + 1] + 1) / 2;
        }
        ans = min(ans, times);
    }
    for (int i = 0; i < n - 2; i++) {
        int times = (a[i] + a[i + 2] + 1) / 2;
        ans = min(ans, times);
    }
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] + 1) / 2;
    }
    sort(a.begin(), a.end());
    ans = min(ans, a[0] + a[1]);

    cout << ans;

    return 0;
}