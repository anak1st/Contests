/**
 * @author: XiaFan
 * @date: 05-05 14:28
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    set<char> c;
    bool ok = true;
    int k;
    for (k = 0; k < n; k++) {
        if (c.count(s[k])) {
            break;
        }
        c.insert(s[k]);
    }
    for (int i = k; i < n; i++) {
        if (s[i] != s[i - k]) {
            ok = false;
        }
    }
    if (ok) {
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