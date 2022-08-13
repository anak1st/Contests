/**
 * @author: XiaFan
 * @date: 06-27 10:26
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    vector<int> colour(n, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        q.push(x);
        colour[x] = 2;
    }
    q.push(0);
    colour[0] = 1;
    
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto u : e[v]) {
            if (colour[u] == 0) {
                colour[u] = colour[v];
                q.push(u);
            }
        }
    }

    bool ok = false;
    for(int i = 1; i < n; i++) {
        if(e[i].size() == 1 && colour[i] == 1) {
            ok = true;
            break;
        }
    }

    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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