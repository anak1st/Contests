/**
 * @author: XiaFan
 * @date: 07-16 17:55
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void rotate(vector<vector<int>> &a) {
    auto b = a;
    int n  = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[j][n - 1 - i];
        }
    }
}

void print(vector<vector<int>> &a) {
    for (auto i : a) {
        for (auto j : i) {
            cout << j;
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (auto &it : a) {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            it[i] = s[i] - '0';
        }
    }
    
    vector<vector<int>> c(n / 2, vector<int>((n + 1) / 2));
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                if (a[i][j]) c[i][j]++;
            }
        }
        // print(a);
        rotate(a);
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            ans += min(c[i][j], 4 - c[i][j]);
        }
    }

    cout << ans << "\n";
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