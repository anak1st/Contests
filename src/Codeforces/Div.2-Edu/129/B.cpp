/**
 * @author: XiaFan
 * @date: 05-23 22:44
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) {
        cin >> it;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &it : b) {
        cin >> it;
    }
    int p = 1;
    for (int i = m - 1; i >= 0; i--) {
        if (p > (n - b[i])) {
            p = p - (n - b[i]);
        } else {
            p += b[i];
        }
    }
    cout << a[p - 1] << "\n";
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
