/**
 * @author: XiaFan
 * @date: 05-12 14:35
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }

    int x = 0;
    for (int j = 0; j <= 30; j++) {
        int bit = 1 << j;
        int cnt = 0;
        for (int &i : a) {
            if (i & bit) {
                cnt++;
            }
        }
        if (cnt * 2 > n) {
            x += bit;
        }
    }
    cout << x << "\n";
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