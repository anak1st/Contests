/**
 * @author: XiaFan
 * @date: 05-03 18:12
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s[s.length() - 1] - '0';
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b[i] = s[s.length() - 1] - '0';
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= 2 && b[i] <= 2) {
            cout << "NO\n";
            return;
        }
        if (a[i] > 2 && b[i] > 2) {
            cout << "NO\n";
            return;
        }
    }
    if (a[n - 1] > 2 && b[n - 1] <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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