/**
 * @author: XiaFan
 * @date: 05-11 18:55
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 1; i < n; i++) {
        int r;
        cin >> r;
        r--;
        a[r].push_back(i);
    }
    string s;
    cin >> s;

    int ans = 0;
    function<pair<int, int>(int)> dfs = [&](int r) -> pair<int, int> {
        int b = 0, w = 0;
        if (s[r] == 'B') {
            b++;
        } else {
            w++;
        }
        for (int i : a[r]) {
            auto res = dfs(i);
            b += res.first;
            w += res.second;
        }
        if (b == w) {
            ans++;
        }
        return {b, w};
    };
    dfs(0);
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