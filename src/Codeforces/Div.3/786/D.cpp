/**
 * @author: XiaFan
 * @date: 05-05 19:31
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 1; i -= 2) {
        if (a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}