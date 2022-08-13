/**
 * @author: XiaFan
 * @date: 05-05 14:16
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    string s;
    cin >> s;
    if (s.length() == 1) {
        int value = (s[0] - 'a') + 1;
        cout << "Bob " << value << "\n";
    } else {
        int value = 0;
        if (s.length() % 2 == 0) {
            for (int i = 0; i < (int)s.length(); i++) {
                value += (s[i] - 'a') + 1;
            }
        } else {
            for (int i = 1; i < (int)s.length() - 1; i++) {
                value += (s[i] - 'a') + 1;
            }
            value += abs(s[0] - s[s.length() - 1]);
        }
        cout << "Alice " << value << "\n";
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