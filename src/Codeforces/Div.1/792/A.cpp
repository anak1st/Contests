/**
 * @author: XiaFan
 * @date: 05-19 22:46
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    if (s.length() == 2) {
        cout << s[1] << "\n";
    } else {
        cout << *min_element(s.begin(), s.end()) << "\n";
    }
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