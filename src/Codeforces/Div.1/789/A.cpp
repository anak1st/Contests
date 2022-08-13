/**
 * @author: XiaFan
 * @date: 05-09 00:06
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        if (a[0] == 0) {
            for (int i = 0; i < n; i++) {
                ans += (a[i] > 0);
            }
        } else {
            bool same = false;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] == a[i + 1]) {
                    same = true;
                    break;
                }
            }
            if (same) {
                ans = n;
            } else {
                ans = n + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}