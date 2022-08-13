/**
 * @author: XiaFan
 * @date: 05-23 22:37
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

    int maxa = *max_element(a.begin(), a.end());
    int maxb = *max_element(b.begin(), b.end());

    if (maxa >= maxb) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }

    if (maxa <= maxb) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
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