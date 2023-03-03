/**
 * @author: XiaFan
 * @date: 05-08 15:44
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector a(n, vector<bool>(m, false));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                a[i][j] = true;
                sum++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < sum; i++) {
        if (!a[i % n][i / n]) {
            ans++;
        }
    }
    // cout << "init " << ans << "\n";
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << x << " " << y << "\n";
        */

        if (a[x][y]) {
            if (a[(sum - 1) % n][(sum - 1) / n]) {
                ans++;
            }
            sum--;
            if (x + y * n >= sum) {
                ans--;
            }
            a[x][y] = false;
        } else {
            sum++;
            if (a[(sum - 1) % n][(sum - 1) / n]) {
                ans--;
            }
            if (x + y * n >= sum) {
                ans++;
            }
            a[x][y] = true;
        }
        cout << ans << "\n";
    }

    return 0;
}