/**
 * @author: XiaFan
 * @date: 07-17 14:59
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct node {
    int x, y;
    friend bool operator<(const node &lhs, const node &rhs) {
        return lhs.x + lhs.y > rhs.x + rhs.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    function<int(int)> fun = [&](int x) -> int {
        if (x > n) {
            return 0;
        } else {
            return a[x];
        }
    };

    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 1;

    priority_queue<node> q;
    q.push({0, 0});
    int ans = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.top();
        q.pop();
        if (y < fun(x)) {
            // cout << x << " " << y << " " << mp[{x, y}] << "\n";
            if (!mp.count({x, y + 1})) {
                q.push({x, y + 1});
            }
            if (!mp.count({x + 1, y})) {
                q.push({x + 1, y});
            }
            mp[{x, y + 1}] += mp[{x, y}];
            mp[{x + 1, y}] += mp[{x, y}];
            ans += mp[{x, y}];
        }
    }
    cout << ans;

    return 0;
}