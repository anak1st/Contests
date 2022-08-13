/**
 * @author: XiaFan
 * @date: 05-30 15:27
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
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        double ans = 1.0 * sum / n;
        bool find = false;
        for (int i = 0; i < n; i++) {
            if (ans == a[i]) {
                find = true;
            }
        }
        if (find) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}