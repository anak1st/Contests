/**
 * @author: XiaFan
 * @date: 07-10 17:26
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<pair<i64, i64>> fun(const vector<i64> &a, const i64 m) {
    int n = a.size();
    vector<pair<i64, i64>> res;
    for (int i = 0; i < n; i++) {
        i64 x = a[i], num = 1;
        while (x % m == 0) {
            x /= m;
            num *= m;
        }
        if (!res.empty() && res.back().first == x) {
            res.back().second += num;
        } else {
            res.push_back({x, num});
        }
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    for (auto &it : a) {
        cin >> it;
    }
    int k;
    cin >> k;
    vector<i64> b(k);
    for (auto &it : b) {
        cin >> it;
    }
    auto res1 = fun(a, m);
    auto res2 = fun(b, m);

    // for (auto [x, y] : res1) {
    //     cout << "Debug1: " << x << " " << y << "\n";
    // }
    // for (auto [x, y] : res2) {
    //     cout << "Debug2: " << x << " " << y << "\n";
    // }

    if (res1 == res2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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