#include <bits/stdc++.h>

using namespace std;

vector<int> get_ans(vector<array<int, 3>> &ops) {
    const int inf = 1e9 + 1;
    int n = ops.size();
    vector<vector<int>> dp(n + 1, vector<int>(101, inf));
    /**
     * @brief find min time
     */
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        auto [_, t, p] = ops[i];
        for (int j = 100; j > 0; j--) {
            int pre = max(0, j - p);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][pre] + t);
        }
    }
    if (dp[n][100] == inf) {
        return {-1};
    }
    /**
     * @brief find ans
     * ans[0] = min time
     */
    vector<int> ans;
    ans.push_back(dp[n][100]);
    for (int i = n - 1, j = 100; i >= 0; i--) {
        if (dp[i + 1][j] == dp[i][j]) {
            continue;
        }
        auto [id, _, p] = ops[i];
        ans.push_back(id);
        j = max(0, j - p);
    }
    reverse(ans.begin() + 1, ans.end());
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<array<int, 3>>> ops(n + 1);
    for (int i = 1; i <= m; i++) {
        int e, t, p;
        cin >> e >> t >> p;
        ops[e].push_back({i, t, p});
    }

    vector<int> ans;
    int time = 0;
    for (int i = 1; i <= n; i++) {
        auto cur = get_ans(ops[i]);
        time += cur[0];
        if (cur[0] == -1 || time > a[i]) {
            cout << "-1\n";
            return;
        }
        ans.insert(ans.end(), cur.begin() + 1, cur.end());
    }

    cout << ans.size() << '\n';
    for (int it : ans) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}