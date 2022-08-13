/**
 * @author: XiaFan
 * @date: 05-23 22:44
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &it : a) {
        cin >> it;
    }
    for (auto &it : b) {
        cin >> it;
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = i;
    }
    sort(c.begin(), c.end(), [&](int x, int y) -> bool {
        if (a[x] == a[y]) {
            return b[x] < b[y];
        }
        return a[x] < a[y];
    });
    for (int i = 0; i < n - 1; i++) {
        if (b[c[i]] > b[c[i + 1]]) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = i;
    }
    std::vector<std::array<int, 2>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] < a[j] || (a[i] == a[j] && b[i] < b[j])) {
                ans.push_back({i, j});
                std::swap(a[i], a[j]);
                std::swap(b[i], b[j]);
            }
        }
    }

    if (std::is_sorted(b.begin(), b.end())) {
        std::cout << ans.size() << "\n";
        for (auto [x, y] : ans) {
            std::cout << x + 1 << " " << y + 1 << "\n";
        }
    } else {
        std::cout << "-1\n";
    }
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
