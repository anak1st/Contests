/**
 * @author: XiaFan
 * @date: 10-11 22:45
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << "0\n";
        return;
    }

    using pii = std::pair<int, int>;

    int ans = 0;
    bool ok = true;
    std::function<pii (pii)> dfs = [&](pii range) -> pii {
        if (!ok) {
            return {-1, -1};
        }
        auto [l, r] = range;
        if (r - l == 1) {
            pii res = {a[l], a[r]};
            if (a[l] > a[r]) {
                std::swap(res.first, res.second);
                ans++;
            }
            return res;
        }

        int mid = (l + r) / 2;
        auto [x1, y1] = dfs({l, mid});
        auto [x2, y2] = dfs({mid + 1, r});

        if (x1 == -1 || x2 == -1) {
            return {-1, -1};
        }

        if (y1 == x2 - 1) {
            return {x1, y2};
        } else if (y2 == x1 - 1) {
            ans++;
            return {x2, y1};
        } else {
            ok = false;
            return {x1, y2};
        }
    };

    dfs({0, n - 1});
    if (ok) {
        std::cout << ans << "\n";
    } else {
        std::cout << -1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}