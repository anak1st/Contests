/**
 * @author: XiaFan
 * @date: 05-19 23:06
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    if (m == 1) {
        cout << "1 1\n";
        return;
    }
    vector b(a);
    vector<vector<int>> c(n);
    for (int i = 0; i < n; i++) {
        sort(b[i].begin(), b[i].end());
        for (int j = 0; j < m; j++) {
            if (b[i][j] != a[i][j]) {
                c[i].push_back(j);
            }
        }
    }
    int row = 0;
    for (int i = 0; i < n; i++) {
        if (c[i].size() > c[row].size()) {
            row = i;
        }
    }
    if (c[row].size() == 0) {
        cout << "1 1\n";
        return;
    }
    if (c[row].size() > 2) {
        cout << "-1\n";
        return;
    }
    cerr << c[row].size();
    int x = c[row][0], y = c[row][1];
    for (auto &ai : a) {
        swap(ai[x], ai[y]);
        if (!is_sorted(ai.begin(), ai.end())) {
            cout << "-1\n";
            return;
        }
    }

    cout << x + 1 << " " << y + 1 << "\n";
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