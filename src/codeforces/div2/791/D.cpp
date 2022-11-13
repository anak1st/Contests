/**
 * @author: XiaFan
 * @date: 05-21 22:57
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    i64 k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> edge(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[u].push_back(v);
    }

    auto fun = [&](int x) -> bool {
        vector<int> b(n, 0), cnt(n);
        int res = 0, j1 = 0, j2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                continue;
            }
            j1++;
            for (int &v : edge[i]) {
                cnt[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (a[i] <= x && cnt[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            // cerr << r << "\n";
            j2++;
            b[r] = max(b[r], 1);
            res = max(res, b[r]);
            for (int &v : edge[r]) {
                if (a[v] > x) {
                    continue;
                }
                b[v] = max(b[v], b[r] + 1);
                cnt[v]--;
                if (cnt[v] == 0) {
                    q.push(v);
                }
            }
        }
        // cerr << x << " " << j1 << " " << j2 << " " << res << endl;
        return ((j1 > j2) || (res >= k));
    };

    int left = 0, right = 1e9 + 1, ans = 1e9 + 1;
    while (left <= right) {
        int mid = 1LL * (left + right) / 2;
        if (fun(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (ans > 1e9) {
        cout << "-1";
    } else {
        cout << ans;
    }

    return 0;
}