/**
 * @author: XiaFan
 * @date: 05-12 14:22
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int &i : c) {
        cin >> i;
    }
    if (count(c.begin(), c.end(), 1) != 1) {
        cout << "NO\n";
        return;
    }

    int maxp = find(c.begin(), c.end(), 1) - c.begin();
    rotate(c.begin(), c.begin() + maxp, c.end());

    for (int i = 0; i < n - 1; i++) {
        if (c[i + 1] - c[i] > 1) {
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