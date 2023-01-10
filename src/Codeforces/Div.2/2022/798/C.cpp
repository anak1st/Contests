/**
 * @author: XiaFan
 * @date: 06-11 15:53
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> edge(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> dp(n, 0), ch(n, 1);
    function<void(int, int)> dfs = [&](int f, int r) -> void {
        int cnt = 0;
        for (auto v : edge[r]) {
            if (v == f) {
                continue;
            }
            dfs(r, v);
            cnt += dp[v];
            ch[r] += ch[v];
        }
        for (auto v : edge[r]) {
            if (v == f) {
                continue;
            }
            dp[r] = max(dp[r], cnt - dp[v] + ch[v] - 1);
        }
    };
    dfs(-1, 0);

    cout << dp[0] << "\n";
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