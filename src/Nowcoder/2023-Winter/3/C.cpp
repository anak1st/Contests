/**
 * @author: XiaFan
 * @date: 2023-01-20 14:02
 **/
#include <bits/stdc++.h>
using i64 = long long;

/**
 * @author: XiaFan
 * @date: 2023-01-20 14:11
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    if (n < 4 || n == 7) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<int> ans(n + 1);
    if (n % 4 == 0) {
        for (int i = 0; i < n; i += 4) {
            ans[i + 1] = i + 3;
            ans[i + 2] = i + 4;
            ans[i + 3] = i + 1;
            ans[i + 4] = i + 2;
        }
    } else if (n % 4 == 1) {
        ans[1] = 4;
        ans[2] = 5;
        ans[3] = 1;
        ans[4] = 2;
        ans[5] = 3;
        for (int i = 5; i < n; i += 4) {
            ans[i + 1] = i + 3;
            ans[i + 2] = i + 4;
            ans[i + 3] = i + 1;
            ans[i + 4] = i + 2;
        }
    } else if (n % 4 == 2) {
        ans[1] = 3;
        ans[2] = 5;
        ans[3] = 1;
        ans[4] = 6;
        ans[5] = 2;
        ans[6] = 4;
        for (int i = 6; i < n; i += 4) {
            ans[i + 1] = i + 3;
            ans[i + 2] = i + 4;
            ans[i + 3] = i + 1;
            ans[i + 4] = i + 2;
        }
    } else if (n % 4 == 3) {
        ans[1] = 4;
        ans[2] = 5;
        ans[3] = 1;
        ans[4] = 2;
        ans[5] = 3;
        ans[1 + 5] = 3 + 5;
        ans[2 + 5] = 5 + 5;
        ans[3 + 5] = 1 + 5;
        ans[4 + 5] = 6 + 5;
        ans[5 + 5] = 2 + 5;
        ans[6 + 5] = 4 + 5;
        for (int i = 5 + 6; i < n; i += 4) {
            ans[i + 1] = i + 3;
            ans[i + 2] = i + 4;
            ans[i + 3] = i + 1;
            ans[i + 4] = i + 2;
        }
    }
    bool ok = true;
    std::vector<int> vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
        vis[ans[i]] = 1;
        int dif = std::abs(ans[i] - i);
        if (dif < 2 || dif > 3) {
            ok = false;
        }
    }
    // std::cout << "ok " << ok << " " << std::count(vis.begin(), vis.end(), 1) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}