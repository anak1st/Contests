/**
 * @author: XiaFan
 * @date: 2023-10-29 00:49
 */
#include <bits/stdc++.h>

using i64 = long long;


void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        a[i] = {x, y};
    }

    std::vector<std::vector<int>> b(n);
    for (int i = 0; i < m; i++) {
        auto [x, y] = a[i];
        b[x].push_back(i);
        if (y + 1 < n)
            b[y + 1].push_back(i);
    }

    std::vector<int> cnt1(m);
    std::map<std::pair<int, int>, int> cnt2;
    std::set<int> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : b[i]) {
            if (s.count(x)) {
                s.erase(x);
            } else {
                s.insert(x);
            }
        }

        if (s.empty()) {
            ans++;
            continue;
        }

        if (s.size() <= 2) {
            std::vector<int> vals;
            for (auto x : s) {
                vals.push_back(x);
            }
            
            if (vals.size() == 1) {
                cnt1[vals[0]]++;
            }
            if (vals.size() == 2) {
                cnt2[{vals[0], vals[1]}]++;
            }
        }
    }

    auto cntt = cnt1;
    std::sort(cntt.rbegin(), cntt.rend());
    int tmp = cntt[0];
    if (cntt.size() >= 2) {
        tmp += cntt[1];
    }
    for (auto [_, v] : cnt2) {
        auto [x, y] = _;
        // std::cerr << x << " " << y << " " << v << "+" << cnt1[x] << "+" << cnt1[y] << "\n";
        tmp = std::max(tmp, v + cnt1[x] + cnt1[y]);
    }

    std::cout << ans + tmp << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}