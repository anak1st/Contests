/**
 * @author: XiaFan
 * @date: 04-24 10:45
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            a++;

        } else {
            b++;
        }
        // a >= b
        if(a < b) {
            cout << "NO\n";
            return;
        }
    }
    if(s[n - 1] != 'B') {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}