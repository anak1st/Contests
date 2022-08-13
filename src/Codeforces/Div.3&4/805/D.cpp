/**
 * @author: XiaFan
 * @date: 07-17 14:39
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int p;
    cin >> p;
    map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }
    for (int i = 1; i <= 26; i++) {
        char c = 'a' + i - 1;
        int a = min(p / i, mp[c]);
        p -= a * i;
        mp[c] = a;
    }
    for (auto c : s) {
        if (mp[c] > 0) {
            cout << c;
            mp[c]--;
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}