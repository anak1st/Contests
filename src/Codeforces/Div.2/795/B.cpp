/**
 * @author: XiaFan
 * @date: 05-31 22:40
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = i; j < n; j++) {
            if (a[j] != a[i]) {
                break;
            }
            p = j;
        }
        if (i == p) {
            cout << "-1\n";
            return;
        }
        // cerr << p << "\n";
        for(int j = i; j < p; j++) {
            b[j] = j + 1;
        }
        b[p] = i;
        i = p;
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] + 1 << " ";
    }
    cout << "\n";
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