/**
 * @author: XiaFan
 * @date: 2024-03-01 20:34
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::list<std::tuple<i64, bool, int>> b;
    for (int i = 0; i < n; i++) {
        bool flag = s[i] == 'A';

        if (b.empty()) {
            b.push_back({a[i], flag, -1});
            continue;
        }

        auto &[x, y, z] = b.back();
        if (y != flag) {
            b.push_back({a[i], flag, -1});
        } else if (flag == y) {
            x = std::max(x, a[i]);
        }
    }

    std::vector<decltype(b)::iterator> c;
    int cnt = 0;
    for (auto it = b.begin(); it != b.end(); it++) {
        std::get<2>(*it) = cnt++;
        c.push_back(it);
    }

    std::sort(c.begin(), c.end(), [&](auto x, auto y) {
        return std::get<0>(*x) > std::get<0>(*y);
    });

    i64 ans = 0;
    std::vector<int> vis(cnt);
    for (auto it : c) {
        if (vis[std::get<2>(*it)]) {
            continue;
        }
        
        if (it == b.begin() || std::next(it) == b.end()) {
            continue;
        }

        // std::cerr << std::get<0>(*it) << ' ' << std::get<2>(*it) << '\n';
        
        vis[std::get<2>(*it)] = 1;
        ans += std::get<0>(*it);
        auto pre = std::prev(it);
        auto nxt = std::next(it);
        b.erase(it);
        if (std::get<0>(*pre) < std::get<0>(*nxt)) {
            vis[std::get<2>(*pre)] = 1;
            b.erase(pre);
        } else {
            vis[std::get<2>(*nxt)] = 1;
            b.erase(nxt);
        }
    }

    std::cout << ans << '\n';
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