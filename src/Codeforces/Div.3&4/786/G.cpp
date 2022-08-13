/**
 * @author: XiaFan
 * @date: 05-10 09:13
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    vector<int> in(n), out(n), cnt_in(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        in[y]++;
        out[x]++;
        cnt_in[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<int> len(n, 1);
    int ans = 1;
    while (!q.empty()) {
        int r = q.front();
        q.pop();
        ans = max(ans, len[r]);
        // cerr << r << "\n";
        for (int i : edge[r]) {
            if (in[i] > 1 && out[r] > 1) {
                len[i] = max(len[i], len[r] + 1);
            }
            cnt_in[i]--;
            if (cnt_in[i] == 0) {
                q.push(i);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}