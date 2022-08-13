/**
 * @author: XiaFan
 * @date: 05-09 09:52
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int negative = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            negative++;
            a[i] = -a[i];
        }
    }
    for (int i = 0; i < negative; i++) {
        a[i] = -a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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