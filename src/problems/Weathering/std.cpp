/**
 * @author: XiaFan
 * @date: 2023-10-30 15:25
 */
#include <bits/stdc++.h>

using i64 = long long;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(m);
    std::vector<std::vector<int>> b(n);
    for (int i = 0; i < m; i++) {
        auto &[x, y] = a[i];
        std::cin >> x >> y;
        x--, y--;
        b[x].push_back(i);
        if (y + 1 < n) {
            b[y + 1].push_back(i);
        }
    }

    std::set<int> s;
    std::vector<int> cnt(m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : b[i]) {
            if (s.count(x)) {
                s.erase(x);
            } else {
                s.insert(x);
            }
        }
        if (s.size() == 0) {
            ans++;
        }
        if (s.size() == 1) {
            cnt[*s.begin()]++;
        }
    }

    ans += *std::max_element(cnt.begin(), cnt.end());
    std::cout << ans << "\n";

    return 0;
}