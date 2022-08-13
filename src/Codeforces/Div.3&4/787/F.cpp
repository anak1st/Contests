/**
 * @author: XiaFan
 * @date: 05-07 21:53
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    vector<bool> visy(n);
    vector<bool> visa(n);
    visy[y] = true;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        a--;
        visa[a] = true;
    }

    vector<vector<int>> t(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int r, int f) {
        for (int i : t[r]) {
            if (i == f) {
                continue;
            }
            dfs(i, r);
            if (visa[i]) {
                visa[r] = true;
            }
            if (visy[i]) {
                visy[r] = true;
            }
        }
    };
    dfs(x, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == x) {
            continue;
        }
        if (visy[i]) {
            ans++;
        } else if (visa[i]) {
            ans += 2;
        }
    }

    cout << ans << "\n";
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