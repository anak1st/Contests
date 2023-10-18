/**
 * @author: XiaFan
 * @date: 2023-10-17 00:00
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i].first >> b[i].second;
    }
    std::sort(b.begin(), b.end());

    std::priority_queue<int, std::vector<int>, std::greater<>> q;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && b[j].first <= i) {
            auto t = q.top();
            q.pop();
            t -= b[j].second;
            j++;
            q.push(t);
        }
        q.push(a[i]);
    }

    while (j < m) {
        auto t = q.top();
        q.pop();
        t -= b[j].second;
        j++;
        q.push(t);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += q.top();
        std::cout << ans << ' ';
        q.pop();
    }

    std::cout << "\n";
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